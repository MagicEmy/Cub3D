/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawing_bonus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 19:57:36 by dmalacov      #+#    #+#                 */
/*   Updated: 2023/03/29 15:45:07 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"
#include <math.h>

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
	draw_line(img, a, c, GOAT_CLR);
	draw_line(img, c, b, GOAT_CLR);
	draw_line(img, goat, b, GOAT_CLR);
	draw_line(img, a, goat, GOAT_CLR);
}

static void	st_fill_in_wall_block(mlx_image_t *img, t_point a, t_point b)
{
	t_coord	idx;

	idx.y = (int)a.y;
	while (idx.y++ < b.y)
	{
		idx.x = (int)a.x;
		while (idx.x >= 0 && idx.x++ < b.x && idx.x < (int)img->width && \
		idx.y >= 0 && idx.y < (int)img->height)
			mlx_put_pixel(img, idx.x, idx.y, WALL_FILL);
	}
}

static void	st_draw_wall_block(mlx_image_t *img, t_coord pt, t_coord *offset)
{
	t_point	a;
	t_point	b;
	t_point	c;
	t_point	d;

	a.x = PAD + offset->x + PPU * pt.x;
	a.y = PAD + offset->y + PPU * pt.y;
	b.x = PAD + offset->x + PPU * pt.x;
	b.y = PAD + offset->y + PPU * (pt.y + 1);
	c.x = PAD + offset->x + PPU * (pt.x + 1);
	c.y = PAD + offset->y + PPU * pt.y;
	d.x = PAD + offset->x + PPU * (pt.x + 1);
	d.y = PAD + offset->y + PPU * (pt.y + 1);
	if (a.x > 0 - PAD && c.x < img->width + PAD && \
		c.y < img->height + PAD)
	{
		st_fill_in_wall_block(img, a, d);
		draw_line(img, a, b, WALL_OUTLINE);
		draw_line(img, a, c, WALL_OUTLINE);
		draw_line(img, d, b, WALL_OUTLINE);
		draw_line(img, d, c, WALL_OUTLINE);
	}
}

/* will be removed */
void	draw_rays(t_data *data, t_ray *ray)
{
	t_point	wall;
	t_point	goat_pos;

	goat_pos.x = PAD + PPU * data->goat->x + data->offset.x;
	goat_pos.y = PAD + PPU * data->goat->y + data->offset.y;
	wall.x = PAD + PPU * ray->x + data->offset.x;
	wall.y = PAD + PPU * ray->y + data->offset.y;
	draw_line(data->img_mm, goat_pos, wall, 0xFFC300FF);
}

void	draw_minimap(t_data *data)
{
	t_coord	idx;
	t_point	goat_pos;

	if (data->img_mm->width - 2 * PAD < data->map_width * PPU || \
	data->img_mm->height - 2 * PAD < data->map_height * PPU)
		get_xy_offset(data);
	goat_pos.x = PAD + PPU * data->goat->x + data->offset.x;
	goat_pos.y = PAD + PPU * data->goat->y + data->offset.y;
	get_img_cleaned(data->img_mm);
	st_draw_goat(data->img_mm, goat_pos, to_rad(data->goat->angle));
	idx.y = 0;
	while (data->map[idx.y])
	{
		idx.x = 0;
		while (data->map[idx.y][idx.x])
		{
			if (data->map[idx.y][idx.x] == '1')
				st_draw_wall_block(data->img_mm, idx, &data->offset);
			idx.x++;
		}
		idx.y++;
	}
}
