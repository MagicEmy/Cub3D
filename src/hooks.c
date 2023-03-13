/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 17:28:17 by dmalacov      #+#    #+#                 */
/*   Updated: 2023/03/13 18:48:37 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "cub3D_structures.h"
#include <stdlib.h>
#include <math.h>

void	go_left_right(int key, t_data *data)
{
	t_point	step;
	int32_t	dir;

	if (key == MLX_KEY_D)
		dir = 1;
	else
		dir = -1;
	step.x = cos(to_rad(data->goat->angle - 90)) * dir;
	step.y = sin(to_rad(data->goat->angle - 90)) * -1 * dir;
	if (!is_wall(data, step.x, step.y))
	{
		data->goat->x += step.x;
		data->goat->y += step.y;
	}
	draw_minimap(data);	// move to bonus
	casting_rays(data);
}

void	go_fwd_bck(int key, t_data *data)
{
	t_point	step;
	int32_t	dir;

	if (key == MLX_KEY_W)
		dir = 1;
	else
		dir = -1;
	step.x = cos(to_rad(data->goat->angle)) * dir;
	step.y = sin(to_rad(data->goat->angle)) * -1 * dir;
	if (!is_wall(data, step.x, step.y))
	{
		data->goat->x += step.x;
		data->goat->y += step.y;
	}
	draw_minimap(data);	// move to bonus
	casting_rays(data);
}

void	look_left_right(int key, t_data *data)
{
	if (key == MLX_KEY_RIGHT)
	{
		data->goat->angle -= 15;
		if (data->goat->angle < 0)
			data->goat->angle += 360;
	}
	else if (key == MLX_KEY_LEFT)
	{
		data->goat->angle += 15;
		if (data->goat->angle >= 360)
			data->goat->angle -= 360;
	}
	draw_minimap(data);	// move to bonus
	casting_rays(data);
}

void	mouse_hook(double xpos, double ypos, void *param)	// move to bonus
{
	t_data	*data;

	data = (t_data *)param;
	if (xpos > 0 && ypos > 0 && xpos < data->img->width && \
	ypos < data->img->height)
	{
		if (xpos > data->cursor_x)
		{
			data->goat->angle -= 1;
			if (data->goat->angle < 0)
				data->goat->angle += 360;
		}
		else if (xpos < data->cursor_x)
		{
			data->goat->angle += 1;
			if (data->goat->angle >= 360)
				data->goat->angle -= 360;
		}
		mlx_get_mouse_pos(data->mlx, &data->cursor_x, &data->cursor_y);
		draw_minimap(data);
		casting_rays(data);
	}
}

/* for debugging */
void	print_goat_info(t_data *data)
{
	printf("Goat coordinates: %f, %f\n", data->goat->x, data->goat->y);
	printf("Goat angle: %f\n", data->goat->angle);
	printf("Mouse pos: %d, %d\n", data->cursor_x, data->cursor_y);
}
