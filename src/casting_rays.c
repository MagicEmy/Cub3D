/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   casting_rays.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 10:34:29 by dmalacov      #+#    #+#                 */
/*   Updated: 2023/02/22 19:42:10 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "cub3D_defines.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

double	calc_distance_from_wall(const char map[10][31], int32_t goat_x, \
int32_t goat_y, double angle)
{
	int32_t	ray_x;
	int32_t	ray_y;
	double	step_x;
	double	step_y;
	size_t	i;
	
	
	// printf("Angle %f\n", angle * 180 / M_PI);
	ray_x = goat_x;
	ray_y = goat_y;
	step_x = 1 * cos(angle) / fabs(cos(angle));
	step_y = -1 * sin(angle) / fabs(sin(angle));
	if (sin(angle) > cos(angle))
		step_x = 1 / tan(angle);
	else if (sin(angle) < cos(angle))
		step_y = -1 * tan(angle);
	i = 0;
	while (ray_x >= 0 && ray_x < 30 && ray_y >= 0 && ray_y < 30 && \
	map[ray_y][ray_x] != '1' && i < 30)	// doesn't work (segfault)
	{
		ray_x = goat_x + round(i * step_x);
		ray_y = goat_y + round(i * step_y);
		// printf("ray_y [%d] ray_x [%d], map[y][x] is %c\n", ray_y, ray_x, map[ray_y][ray_x]);
		i++;
	}
	// printf("distance is %f\n", sqrt(pow(ray_x - goat_x, 2) + pow(ray_y - goat_y, 2)));
	return (sqrt(pow(ray_x - goat_x, 2) + pow(ray_y - goat_y, 2)));
}

void	casting_rays(mlx_image_t *img, int width, int height)
{
	size_t	xi;
	size_t	yi;
	size_t	top_wall;
	size_t	bottom_wall;
	int32_t	goat_angle = 90;
	double	distance;
	const char	map[10][31] = {"111111111111111111111111111111", \
	"100000000000000000000000000001", "100000000000000000000000000001", \
	"1000000001", "100000000000000000000000000001", "100000000000000000000000000001", \
	"100000000000000000000000000001", "100000000000000000000000000001", \
	"100000000000000000000000000001", "111111111111111111111111111111"};

	xi = 0;
	while ((int32_t)xi < width)
	{
		distance = calc_distance_from_wall(map, 15, 5, \
		M_PI * (goat_angle + FOV / 2 - xi * FOV / WIDTH) / 180);
		yi = 0;
		top_wall = HEIGHT / 2 - (WALL_HEIGHT / (2 * distance/5));
		bottom_wall = HEIGHT / 2 + (WALL_HEIGHT / (2 * distance/5));
		// printf("top wall: %zu, bottom wall: %zu\n", top_wall, bottom_wall);
		while (yi < top_wall)
			mlx_put_pixel(img, xi, yi++, 0x800080ff);
		while (yi < bottom_wall)
		{
			// printf("about to put pixel [%zu][%zu]\n", yi, xi);
			mlx_put_pixel(img, xi, yi++, 0x008080ff);
		}
		while ((int32_t)yi < height)
			mlx_put_pixel(img, xi, yi++, 0xf08080ff);
		xi++;
	}
	
}