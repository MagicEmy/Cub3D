/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawing_bonus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 19:57:36 by dmalacov      #+#    #+#                 */
/*   Updated: 2023/03/07 19:59:10 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "cub3D_defines.h"
#include "cub3D.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>


void	draw_goat(mlx_image_t *img, t_point goat, double angle)
{
	t_point	a;
	t_point	b;
	t_point c;
	
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

void	wipe_everything(mlx_image_t *img)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel(img, x, y, 0x000000FF);
			x++;
		}
	y++;
	}
}

void	draw_wall_block(mlx_image_t *img, t_point pt)
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

void	draw_minimap(t_data *data, t_point goat_pos)
{
	t_point	idx;
	const char	map[10][31] = \
	{"111111111111111111111111111111", \
	"100000000000000000000000000001", \
	"100000000000000000000000000001", \
	"100000000000000000000000000001", \
	"100000000000000010000000000001", \
	"100000000000000010000000000001", \
	"100000000000000010000000000001", \
	"100000000000000000000000000001", \
	"100000000000000000000000000001", \
	"111111111111111111111111111111"};

	idx.y = 0;
	// wipe_everything(data->img);
	draw_goat(data->img, goat_pos, to_rad(data->goat->angle));
	while (idx.y < data->map_height)
	{
		idx.x = 0;	
		while (idx.x < data->map_width)
		{
			if (map[(int)idx.y][(int)idx.x] == '1')
				draw_wall_block(data->img, idx);
			idx.x++;
		}
		idx.y++;
	}
}