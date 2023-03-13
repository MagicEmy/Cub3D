/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 10:49:12 by dmalacov      #+#    #+#                 */
/*   Updated: 2023/03/13 11:42:22 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "cub3D_defines.h"
#include "cub3D.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void	draw_scene(t_data *data, t_ray *ray, t_point idx)
{
	while (idx.y < (int)round(HALF_HEIGHT - HALF_HEIGHT / ray->dist) && \
	idx.y < HEIGHT)
		mlx_put_pixel(data->img, idx.x, idx.y++, data->sky_clr);
	while (idx.y < (int)round(HALF_HEIGHT + HALF_HEIGHT / ray->dist) && \
	idx.y < HEIGHT)
		mlx_put_pixel(data->img, idx.x, idx.y++, data->nsew_clr[ray->facing]);
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
