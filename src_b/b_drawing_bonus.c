/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_drawing_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:57:36 by dmalacov          #+#    #+#             */
/*   Updated: 2023/03/22 15:15:32 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "cub3D_defines.h"
#include "cub3D.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

static void	st_draw_goat(mlx_image_t *img, t_point goat, double angle)
{
	t_point	a;
	t_point	b;
	t_point	c;

	a.x = goat.x + 3 * cos(angle - 3 * M_PI_4);
	a.y = goat.y - 3 * sin(angle - 3 * M_PI_4);
	b.x = goat.x + 3 * cos(angle + 3 * M_PI_4);
	b.y = goat.y - 3 * sin(angle + 3 * M_PI_4);
	c.x = goat.x + 5 * cos(angle);
	c.y = goat.y - 5 * sin(angle);
	draw_line(img, a, c, 0xFF00FFFF);
	draw_line(img, c, b, 0xFF00FFFF);
	draw_line(img, goat, b, 0xFF00FFFF);
	draw_line(img, a, goat, 0xFF00FFFF);
}

static void	st_wipe_everything(mlx_image_t *img)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			mlx_put_pixel(img, x, y, 0x00000040);
			x++;
		}
	y++;
	}
}

static void	st_draw_wall_block(mlx_image_t *img, t_point pt)
{
	t_point	a;
	t_point	b;
	t_point	c;

	a.x = PADDING + PPU * pt.x;
	a.y = PADDING + PPU * pt.y;
	b.x = PADDING + PPU * pt.x;
	b.y = PADDING + PPU * (pt.y + 1);
	c.x = PADDING + PPU * (pt.x + 1);
	c.y = PADDING + PPU * pt.y;
	draw_line(img, a, b, WALL_CLR);
	draw_line(img, a, c, WALL_CLR);
	a.x = PADDING + PPU * (pt.x + 1);
	a.y = PADDING + PPU * (pt.y + 1);
	draw_line(img, a, b, WALL_CLR);
	draw_line(img, a, c, WALL_CLR);
}

void	draw_rays(t_data *data, t_ray *ray)
{
	t_point	wall;
	t_point	goat_pos;

	goat_pos.x = PADDING + PPU * data->goat->x;
	goat_pos.y = PADDING + PPU * data->goat->y;
	wall.x = PADDING + PPU * ray->x;
	wall.y = PADDING + PPU * ray->y;
	draw_line(data->img_mm, goat_pos, wall, 0xFFC30050);
}

void	draw_minimap(t_data *data)
{
	t_point	idx;
	t_point	goat_pos;

	idx.y = 0;
	goat_pos.x = PADDING + PPU * data->goat->x;
	goat_pos.y = PADDING + PPU * data->goat->y;
	st_wipe_everything(data->img_mm);
	st_draw_goat(data->img_mm, goat_pos, to_rad(data->goat->angle));
	while (data->map[(int)idx.y])
	{
		idx.x = 0;
		while (data->map[(int)idx.y][(int)idx.x])
		{
			if (data->map[(int)idx.y][(int)idx.x] == '1')
				st_draw_wall_block(data->img_mm, idx);
			idx.x++;
		}
		idx.y++;
	}
}
