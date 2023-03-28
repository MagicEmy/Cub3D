/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 10:49:12 by dmalacov      #+#    #+#                 */
/*   Updated: 2023/03/27 17:39:05 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <math.h>

static void	st_draw_texture(t_data *data, t_ray *ray, int32_t wall_height, \
t_coord *idx)
{
	t_coord			txt;
	size_t			start_ty;
	size_t			i;
	mlx_texture_t	*tx;

	i = 0;
	tx = data->textures[ray->facing];
	texture_x_coord(&txt, ray, tx);
	if (wall_height > (int)data->img->height)
		start_ty = round(tx->height * ((wall_height - \
		(int)data->img->height) / 2) / wall_height);
	else
		start_ty = 0;
	txt.y = start_ty;
	while (idx->y < ((int)data->img->height + wall_height) / 2 \
	&& idx->y < (int)data->img->height && txt.y < (int)tx->height \
	&& txt.x < (int)tx->width)
	{
		texture_put_pixel(data, idx, &txt, tx);
		idx->y++;
		i++;
		txt.y = start_ty + round(i * (double)tx->height / wall_height);
	}
}

void	draw_scene(t_data *data, t_ray *ray, t_coord idx)
{
	int32_t	wall_height;

	wall_height = round(data->goat->dist_pp / ray->dist);
	while (idx.y < ((int)data->img->height - wall_height) / 2 && \
	idx.y < (int)data->img->height)
		mlx_put_pixel(data->img, idx.x, idx.y++, data->ceiling_clr);
	st_draw_texture(data, ray, wall_height, &idx);
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
