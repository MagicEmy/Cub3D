/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 17:28:17 by dmalacov      #+#    #+#                 */
/*   Updated: 2023/03/07 17:42:31 by dmalacov      ########   odam.nl         */
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
}

void	go_up_down(int key, t_data *data)
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
}