/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   casting_rays.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 10:34:29 by dmalacov      #+#    #+#                 */
/*   Updated: 2023/02/22 12:44:30 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "cub3D_defines.h"
#include <stdlib.h>

void	casting_rays(mlx_image_t *img, int width, int height)
{
	size_t	xi;
	size_t	yi;

	xi = 0;
	while ((int32_t)xi < width)
	{
		// do some calculations
		yi = 0;
		while ((int32_t)yi < height / 3)
			mlx_put_pixel(img, xi, yi++, 0x800080ff);
		while ((int32_t)yi < 2 * height / 3)
			mlx_put_pixel(img, xi, yi++, 0x008080ff);
		while ((int32_t)yi < height)
			mlx_put_pixel(img, xi, yi++, 0xf08080ff);
		xi++;
	}
	
}