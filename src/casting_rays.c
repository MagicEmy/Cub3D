/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   casting_rays.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 10:34:29 by dmalacov      #+#    #+#                 */
/*   Updated: 2023/02/28 19:22:06 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "cub3D_defines.h"
#include "cub3D.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

/* Digital Differential Analysis - walking along the y-axis */
int	dda_y_axis(t_ray *ns, t_data *data, t_goat *goat, double angle)
{
	t_point	step;
	t_point	first_step;
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

	if (angle == 0 || angle == M_PI)
		return (PARALLEL);
	data->map = NULL;	// DELETE
	// printf("\n*** Y AXIS ***\n");
	i = 0;
	get_first_step(&first_step, angle, Y_AXIS, goat);
	get_steps(&step, angle, Y_AXIS);
	// printf("FS.x = %f, FS.y = %f, S.x = %f, S.y = %f\n", first_step.x, first_step.y, step.x, step.y);
	ns->x = goat->x + first_step.x;
	ns->y = goat->y + first_step.y;
	ns->dist = dist_to_wall(ns, goat);
	while (is_inside_map(ns, data))
	{
		// printf("Round %zu: ns->x = %f, ns->y = %f\n", i, ns->x, ns->y);
		// printf("map[%d][%d] is %c\n", (int)round(ns->y), (int)ns->x, map[(int)round(ns->y)][(int)ns->x]);
		if (map[(int)(ns->y)][(int)floor(ns->x)] == '1' && step.y > 0) // +1 y solves this
			return (SOUTH);
		else if (map[(int)(ns->y) - 1][(int)floor(ns->x)] == '1')
			return (NORTH);
		ns->x = goat->x + first_step.x + i * step.x;
		ns->y = goat->y + first_step.y + i * step.y;
		ns->dist = dist_to_wall(ns, goat);
		i++;
	}
	return (1);
}

/* Digital Differential Analysis - walking along the x-axis */
int	dda_x_axis(t_ray *ew, t_data *data, t_goat *goat, double angle)
{
	t_point	step;
	t_point	first_step;
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

	if (angle == M_PI_2 || angle == 3 * M_PI_2)
		return (PARALLEL);
	data->map = NULL;	// DELETE
	// printf("\n*** X AXIS ***\n");
	i = 1;
	// printf("angle is %f\n", angle);
	get_first_step(&first_step, angle, X_AXIS, goat);
	get_steps(&step, angle, X_AXIS);
	// printf("FS.x = %f, FS.y = %f, S.x = %f, S.y = %f\n", first_step.x, first_step.y, step.x, step.y);
	ew->x = goat->x + first_step.x;
	ew->y = goat->y + first_step.y;
	ew->dist = dist_to_wall(ew, goat);
	while (is_inside_map(ew, data))
	{
		// printf("Round %zu: ew->x = %f, ew->y = %f\n", i, ew->x, ew->y);
		// printf("map[%d][%d] is %c\n", (int)round(ew->y), (int)ew->x, map[(int)round(ew->y)][(int)ew->x]);
		if (map[(int)floor(ew->y)][(int)ew->x] == '1' && step.x > 0)
			return (EAST);
		else if (map[(int)floor(ew->y)][(int)ew->x - 1] == '1') // -1 x solves this
			return (WEST);
		ew->x = goat->x + first_step.x + i * step.x;
		ew->y = goat->y + first_step.y + i * step.y;
		ew->dist = dist_to_wall(ew, goat);
		i++;
	}
	return (PARALLEL);
}

double	calc_distance_from_wall(t_data *data, t_goat *goat, double ray_angle)
{
	t_ray	ew;
	t_ray	ns;
	
	ew.facing = dda_x_axis(&ew, data, goat, to_rad(goat->angle + ray_angle));
	ns.facing = dda_y_axis(&ns, data, goat, to_rad(goat->angle + ray_angle));
	if (ew.dist > ns.dist)
	{
		// printf("[ns] wall touched at [%f, %f], wall type %d\t", ns.x, ns.y, ns.facing);
		return (ns.dist * cos(to_rad(ray_angle)));
	}
	else
	{
		// printf("[ew] wall touched at [%f, %f], wall type %d\t", ew.x, ew.y, ew.facing);
		return (ew.dist * cos(to_rad(ray_angle)));
	}
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
		printf("xi: %d - dist is %f\n", xi, distance);	// delete
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
