/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 10:49:12 by dmalacov      #+#    #+#                 */
/*   Updated: 2023/03/08 17:21:10 by dmalacov      ########   odam.nl         */
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

static int	st_is_inside_window(double x, double y)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
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
			if (st_is_inside_window(a.x + step.x * i, a.y + step.y * i))
				mlx_put_pixel(img, a.x + step.x * i, a.y + step.y * i, clr);
			i++;
		}
	}
	else
	{
		while ((step.y < 0 && a.y + step.y * i >= b.y) || \
		(step.y > 0 && a.y + step.y * i <= b.y))
		{
			if (st_is_inside_window(a.x + step.x * i, a.y + step.y * i))
				mlx_put_pixel(img, a.x + step.x * i, a.y + step.y * i, clr);
			i++;
		}
	}
}
