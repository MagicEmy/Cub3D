/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawing_get_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/20 19:06:46 by dmalacov      #+#    #+#                 */
/*   Updated: 2023/03/27 17:07:33 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"
#include <math.h>

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

void	get_img_cleaned(mlx_image_t *img)
{
	t_coord	idx;

	idx.y = 0;
	while (idx.y < (int)img->height)
	{
		idx.x = 0;
		while (idx.x < (int)img->width)
		{
			mlx_put_pixel(img, idx.x, idx.y, 0xFFFFFF85);
			idx.x++;
		}
	idx.y++;
	}
}
