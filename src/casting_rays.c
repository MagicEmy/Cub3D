/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   casting_rays.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 10:34:29 by dmalacov      #+#    #+#                 */
/*   Updated: 2023/02/23 19:11:02 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "cub3D_defines.h"
#include "cub3D.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void	get_wall_xy(t_point *ray, t_data *data, t_goat *goat, double angle)
{
	double	step_x;
	double	step_y;
	size_t	i;
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
	
	step_x = cos(angle);
	step_y = -1 * sin(angle);	// step.x, step.y can be a t_point
	i = 0;
	if (fabs(sin(angle)) < fabs(cos(angle)))	// x steps are smaller, start with x axis
		i = 1; // else start with y axis
	ray->x = goat->x; // 	DELETE! IS NONSENSE
	while (1)
	{
/* 
	DAA algorithm
	steps in direction +/- 1 along either x or y axis
		sqrt(1ˆ2 + (dy/dx)^2) for dy
		sqrt(1ˆ2 + (dx/dy)^2) for dx
	keep track of steps taken
	check every time whether we hit a wall (also which wall - orientation)
	
 */
		i++;
		if (ray->x < 0 || ray->x >= data->map_width || ray->y < 0 || \
			ray->y >= data->map_height)
			break;
	}
	// else if (fabs(sin(angle)) < fabs(cos(angle)))
	// 	step_y *= fabs(tan(angle));
	
}

double	calc_distance_from_wall(t_data *data, t_goat *goat, double ray_angle)
{
	t_point	ray;
	double	angle;
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
	
	get_wall_xy(&ray, data, goat, to_rad(goat->angle + ray_angle));
	// step_x = 1 * cos(angle) / fabs(cos(angle));
	// step_y = -1 * sin(angle) / fabs(sin(angle));
	// printf("goat standing on %c\t steps x: %f, step y %f\n:", map[ray.y][ray.x], step_x, step_y);
	// printf("goat->y: %d, goat->x %d\n", goat->y, goat->x);
	printf("angle: %f\t", ray_angle);
	// printf("ray.y [%d] ray.x [%d], map[y][x] is %c\n", ray.y, ray.x, map[ray.y][ray.x]);
	printf("distance is %f\t\t", sqrt(pow(ray.x - goat->x, 2) + pow(ray.y - goat->y, 2)));
	printf("corrected : %f\n", sqrt(pow(ray.x - goat->x, 2) + pow(ray.y - goat->y, 2)) * cos(to_rad(ray_angle)));
	return (sqrt(pow(ray.x - goat->x, 2) + pow(ray.y - goat->y, 2)) * cos(to_rad(ray_angle)));
	// return (sqrt(pow(ray.x - goat->x, 2) + pow(ray.y - goat->y, 2)));
}

void	casting_rays(t_data *data, t_goat *goat)
{
	int32_t	xi;
	int32_t	yi;
	int32_t	top_wall;
	int32_t	bottom_wall;
	double	distance;
	
	xi = 0;
	while (xi < WIDTH)
	{
		distance = calc_distance_from_wall(data, goat, FOV / 2 - (double)xi * FOV / (WIDTH - 1));
		yi = 0;
		
		top_wall = HEIGHT / 2 - (HEIGHT / 2 / distance);
		bottom_wall = HEIGHT / 2 + (HEIGHT / 2 / distance);
		// printf("top wall: %zu, bottom wall: %zu\n", top_wall, bottom_wall);
		while (yi < top_wall)
			mlx_put_pixel(data->img, xi, yi++, 0x8FFFFDff);
		while (yi < bottom_wall)
		{
			// printf("about to put pixel [%zu][%zu]\n", yi, xi);
			mlx_put_pixel(data->img, xi, yi++, 0xE78421ff);
		}
		while (yi < HEIGHT)
			mlx_put_pixel(data->img, xi, yi++, 0x25A703ff);
		xi++;
	}
}