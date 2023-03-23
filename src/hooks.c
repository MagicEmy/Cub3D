/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:28:17 by dmalacov          #+#    #+#             */
/*   Updated: 2023/03/23 13:03:04 by emlicame         ###   ########.fr       */
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
	step.x = cos(to_rad(data->goat->angle - 90)) * dir * STEP_LENGTH;
	step.y = sin(to_rad(data->goat->angle - 90)) * -1 * dir * STEP_LENGTH;
	if (is_accessible(data, step.x, step.y))
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
	step.x = cos(to_rad(data->goat->angle)) * dir * STEP_LENGTH;
	step.y = sin(to_rad(data->goat->angle)) * -1 * dir * STEP_LENGTH;
	if (is_accessible(data, step.x, step.y))
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
		data->goat->angle -= 5;
		if (data->goat->angle < 0)
			data->goat->angle += 360;
	}
	else if (key == MLX_KEY_LEFT)
	{
		data->goat->angle += 5;
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
		if (xpos > data->cursor_x + 3)
		{
			data->goat->angle -= 1;
			if (data->goat->angle < 0)
				data->goat->angle += 360;
		}
		else if (xpos < data->cursor_x - 3)
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

void	key_hooks(void *param)
{
	t_data	*data;
	// static double	time = 0;

	data = (t_data *)param;

	// time += data->mlx->delta_time;
	// int position = (int)(time / 3) % 6;
	// printf("position: %i, time: %f, delta: %f\n", position, time, data->mlx->delta_time);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		return (mlx_close_window(data->mlx));
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		go_left_right(MLX_KEY_D, data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		go_left_right(MLX_KEY_A, data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		go_fwd_bck(MLX_KEY_W, data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		go_fwd_bck(MLX_KEY_S, data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		look_left_right(MLX_KEY_RIGHT, data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		look_left_right(MLX_KEY_LEFT, data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_G))
		print_goat_info(data);
}

/* for debugging - to be deleted */
void	print_goat_info(t_data *data)
{
	printf("Goat coordinates: %f, %f\n", data->goat->x, data->goat->y);
	printf("Goat angle: %f\n", data->goat->angle);
	printf("Mouse pos: %d, %d\n", data->cursor_x, data->cursor_y);
}
