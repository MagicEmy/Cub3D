/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 10:49:12 by dmalacov      #+#    #+#                 */
/*   Updated: 2023/03/16 18:31:26 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "cub3D_defines.h"
#include "cub3D.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

/* Function to be split and finished - work in progress */
void	draw_texture(t_data *data, t_ray *ray, int32_t wall_height, t_point *idx)
{
	size_t			tx;
	size_t			ty;
	size_t			start_ty;
	size_t			i;
	double			ray_pos;
	mlx_texture_t	*texture;
	
	if (ray->facing == NORTH || ray->facing == SOUTH)	// WEST/SOUTH to be added
		ray_pos = ray->x - floor(ray->x);
	if (ray->facing == EAST || ray->facing == WEST)	// WEST/SOUTH to be added
		ray_pos = ray->y - floor(ray->y);
	texture = data->texture.south;
	tx = texture->width * ray_pos;
	i = 0;
	if (wall_height > IMG_HEIGHT)
		start_ty = round(texture->height * ((wall_height - IMG_HEIGHT) / 2) / wall_height);
	else
		start_ty = 0;
	ty = start_ty + i * (double)texture->height / wall_height;
	while (idx->y < ((int)data->img->height + wall_height) / 2 && \
	idx->y < data->img->height && ty < texture->height)
	{
		mlx_put_pixel(data->img, idx->x, idx->y, get_rgba(texture->pixels[(ty * texture->width + tx) * texture->bytes_per_pixel], \
		texture->pixels[(ty * texture->width + tx) * texture->bytes_per_pixel + 1], \
		texture->pixels[(ty * texture->width + tx) * texture->bytes_per_pixel + 2], \
		texture->pixels[(ty * texture->width + tx) * texture->bytes_per_pixel + 3]));
		idx->y++;
		i++;
		ty = start_ty + i * (double)texture->height / wall_height;
	}
}

void	draw_scene(t_data *data, t_ray *ray, t_point idx)
{
	int32_t	wall_height;

	// consider optimizing for fewer rays (then nested loop outer x)
	wall_height = round(data->goat->dist_pp / ray->dist);
	while (idx.y < ((int)data->img->height - wall_height) / 2 && \
	idx.y < data->img->height)
		mlx_put_pixel(data->img, idx.x, idx.y++, data->sky_clr);
	// while (idx.y < ((int)data->img->height + wall_height) / 2 && \
	// idx.y < data->img->height)
	// 	mlx_put_pixel(data->img, idx.x, idx.y++, data->nsew_clr[ray->facing]);
	draw_texture(data, ray, wall_height, &idx);
	while (idx.y < HEIGHT)
		mlx_put_pixel(data->img, idx.x, idx.y++, data->floor_clr);
}

static int	st_is_inside_img(mlx_image_t *img, double x, double y)
{
	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
		return (TRUE);
	else
		return (FALSE);
}

void	draw_line(mlx_image_t *img, t_point a, t_point b, int32_t clr)
{
	t_point	step;
	size_t	i;

	i = 0;
	get_line_steps(&step, a, b);
	if (fabs(b.x - a.x) >= fabs(b.y - a.y))
	{
		while ((step.x < 0 && a.x + step.x * i >= b.x) || \
		(step.x > 0 && a.x + step.x * i <= b.x))
		{
			if (st_is_inside_img(img, a.x + step.x * i, a.y + step.y * i))
				mlx_put_pixel(img, a.x + step.x * i, a.y + step.y * i, clr);
			i++;
		}
	}
	else
	{
		while ((step.y < 0 && a.y + step.y * i >= b.y) || \
		(step.y > 0 && a.y + step.y * i <= b.y))
		{
			if (st_is_inside_img(img, a.x + step.x * i, a.y + step.y * i))
				mlx_put_pixel(img, a.x + step.x * i, a.y + step.y * i, clr);
			i++;
		}
	}
}
