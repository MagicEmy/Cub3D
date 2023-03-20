/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/13 18:03:25 by dmalacov      #+#    #+#                 */
/*   Updated: 2023/03/20 17:51:34 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "cub3D_defines.h"
#include "MLX42/MLX42.h"
#include <math.h>

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
	mlx_put_pixel(data->img, idx->x, idx->y, \
		get_rgba(tx->pixels[(txt->y * tx->width + txt->x) * bpp], \
		tx->pixels[(txt->y * tx->width + txt->x) * bpp + 1], \
		tx->pixels[(txt->y * tx->width + txt->x) * bpp + 2], \
		tx->pixels[(txt->y * tx->width + txt->x) * bpp + 3]));
}
