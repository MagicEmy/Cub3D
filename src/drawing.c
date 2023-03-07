/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 10:49:12 by dmalacov      #+#    #+#                 */
/*   Updated: 2023/03/07 20:17:30 by dmalacov      ########   odam.nl         */
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
	int32_t	top_wall;
	int32_t	bottom_wall;
	
	top_wall = HEIGHT / 2 - ceil(HEIGHT / 2 / ray->dist);
	bottom_wall = HEIGHT / 2 + ceil(HEIGHT / 2 / ray->dist);
	// printf("top wall: %d, bottom wall: %d\n", top_wall, bottom_wall);
	while (idx.y < top_wall && idx.y < HEIGHT)
		mlx_put_pixel(data->img, idx.x, idx.y++, 0x8FFFFDff);
	while (idx.y < bottom_wall && idx.y < HEIGHT)
	{
		// printf("about to put pixel [%f][%f]\n", idx.y, idx.x);
		mlx_put_pixel(data->img, idx.x, idx.y++, 0xE78421ff);
	}
	while (idx.y < HEIGHT)
		mlx_put_pixel(data->img, idx.x, idx.y++, 0x25A703ff);
}

void	st_line_along_x(mlx_image_t *img, t_point a, t_point step, int32_t clr)
{
	// WORK IN PROGRESS
	// WON'T WORK WITHOUT PT B
		while ((dir.x < 0 && a.x + dir.x * i >= b.x) || \
		(dir.x > 0 && a.x + dir.x * i <= b.x))
		{
			if (a.x + dir.x * i >= 0 && a.x + dir.x * i < WIDTH && \
			a.y + dir.y * i * fabs(delta.y/delta.x) >= 0 && \
			a.y + dir.y * i * fabs(delta.y/delta.x) < HEIGHT)
				mlx_put_pixel(img, a.x + dir.x * i, \
				a.y + dir.y * i * fabs(delta.y / delta.x), clr);
			i++;
		}
}
void	st_line_along_y(mlx_image_t *img, t_point a, t_point step, int32_t clr)
{
	// WORK IN PROGRESS
	// WON'T WORK WITHOUT PT B
		while ((dir.y < 0 && a.y + dir.y * i >= b.y) || \
		(dir.y > 0 && a.y + dir.y * i <= b.y))
		{
			if (a.x + dir.x * i * fabs(delta.x/delta.y) >= 0 && \
			a.x + dir.x * i * fabs(delta.x/delta.y) < WIDTH && \
			a.y + dir.y * i >= 0 && a.y + dir.y * i < HEIGHT)
				mlx_put_pixel(img, a.x + dir.x * i * fabs(delta.x / delta.y), \
				a.y + dir.y * i, clr);
			i++;
		}
}

void	draw_line(mlx_image_t *img, t_point a, t_point b, int32_t clr)
{
	t_point	step;
	t_point	delta;
	size_t	i;

	i = 0;
	if (fabs(delta.x) >= fabs(delta.y))
	{
		get_line_steps(&step, a, b, X_AXIS);
		st_line_along_x(img, a, step, clr);	
	}
	else
	{
		get_line_steps(&step, a, b, Y_AXIS);
		st_line_along_y(img, a, step, clr);
	}
}
