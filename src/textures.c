/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:03:25 by dmalacov          #+#    #+#             */
/*   Updated: 2023/04/03 17:15:48 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <math.h>

int32_t	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	texture_x_coord(t_coord *txt, t_ray *ray, mlx_texture_t *texture)
{
	double	ray_pos;

	if (ray->facing == NORTH || ray->facing == SOUTH)
		ray_pos = ray->x - floor(ray->x);
	if (ray->facing == EAST || ray->facing == WEST)
		ray_pos = ray->y - floor(ray->y);
	if (ray->facing == NORTH || ray->facing == EAST)
		txt->x = texture->width * ray_pos;
	else
		txt->x = texture->width * (1 - ray_pos);
}

void	texture_put_pixel(t_data *data, t_coord *idx, t_coord *txt, \
mlx_texture_t *tx)
{
	int32_t	bpp;

	bpp = tx->bytes_per_pixel;
	if (idx->x >= 0 && idx->x < (int)data->img->width && idx->y >= 0 && \
	idx->y < (int)data->img->height)
	{
		mlx_put_pixel(data->img, idx->x, idx->y, \
			get_rgba(tx->pixels[(txt->y * tx->width + txt->x) * bpp], \
			tx->pixels[(txt->y * tx->width + txt->x) * bpp + 1], \
			tx->pixels[(txt->y * tx->width + txt->x) * bpp + 2], \
			tx->pixels[(txt->y * tx->width + txt->x) * bpp + 3]));
	}
}

void	texture_acquisition(t_parsing *parsing, t_data *data)
{
	data->textures = malloc (sizeof(mlx_texture_t *) * 4);
	if (!data->textures)
		error_exit(ERROR_MALLOC);
	ft_memset(data->textures, 0, sizeof(mlx_texture_t *) * 4);
	data->textures[NORTH] = mlx_load_png(parsing->no_path);
	if (data->textures[NORTH] == NULL)
		error_exit(ERROR_PATH_TEXTURE);
	data->textures[SOUTH] = mlx_load_png(parsing->so_path);
	if (data->textures[SOUTH] == NULL)
		error_exit(ERROR_PATH_TEXTURE);
	data->textures[EAST] = mlx_load_png(parsing->ea_path);
	if (data->textures[EAST] == NULL)
		error_exit(ERROR_PATH_TEXTURE);
	data->textures[WEST] = mlx_load_png(parsing->we_path);
	if (data->textures[WEST] == NULL)
		error_exit(ERROR_PATH_TEXTURE);
}
