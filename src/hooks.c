/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 17:28:17 by dmalacov      #+#    #+#                 */
/*   Updated: 2023/03/27 16:51:07 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
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
	casting_rays(data);
}

void	key_hooks(void *param)
{
	t_data	*data;

	data = (t_data *)param;
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
}
