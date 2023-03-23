/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawing_get_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/20 19:06:46 by dmalacov      #+#    #+#                 */
/*   Updated: 2023/03/23 18:25:35 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "cub3D_defines.h"
#include "cub3D.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void	get_xy_offset(t_data *data)
{
	if (data->img_mm->width - 2 * PAD < data->map_width * PPU)
	{
		if ((int)floor(data->goat->x) * PPU > \
			(int)data->img_mm->width / 2 - PAD)
			data->offset.x = -1 * \
			get_min(data->map_width * PPU - data->img_mm->width + 2 * PAD, \
			(int)floor(data->goat->x) * PPU - (data->img_mm->width / 2 - PAD));
		else
			data->offset.x = 0;
	}
	if (data->img_mm->height - 2 * PAD < data->map_height * PPU)
	{
		if ((int)floor(data->goat->y) * PPU > \
			(int)data->img_mm->height / 2 - PAD)
			data->offset.y = -1 * \
			get_min(data->map_height * PPU - data->img_mm->height + 2 * PAD, \
			(int)floor(data->goat->y) * PPU - (data->img_mm->height / 2 - PAD));
		else
			data->offset.y = 0;
	}
}

int32_t	get_min(int32_t a, int32_t b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}
