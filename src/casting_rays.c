/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   casting_rays.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 10:34:29 by dmalacov      #+#    #+#                 */
/*   Updated: 2023/02/28 13:32:42 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "cub3D_defines.h"
#include "cub3D.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void	get_first_step(t_point *first_step, double angle, int axis, t_goat *goat)
{
	if (axis == X_AXIS)
	{
		if (angle > M_PI_2 && angle < M_PI_2 * 3)
			first_step->x = floor(goat->x) - goat->x;
		else if (angle < M_PI_2 || angle > M_PI_2 * 3)
			first_step->x = ceil(goat->x) - goat->x;
		first_step->y = get_y(first_step->x, angle);
	}
	else
	{
		if ((angle > 0 && angle < M_PI) || angle > 2 * M_PI)
			first_step->y = floor(goat->y) - goat->y;
		else if (angle < 0 || (angle > M_PI && angle < M_PI * 2))
			first_step->y = ceil(goat->y) - goat->y;
		first_step->x = get_x(first_step->y, angle);
	}
}

void	get_steps(t_point *step, double angle, int axis)
{
	if (axis == X_AXIS)
	{
		if (angle > M_PI_2 && angle < M_PI_2 * 3)
			step->x = -1;
		else if (angle < M_PI_2 || angle > M_PI_2 * 3)
			step->x = 1;
		step->y = get_y(step->x, angle);
	}
	else
	{
		if ((angle > 0 && angle < M_PI) || angle > 2 * M_PI)
			step->y = -1;
		else if (angle < 0 || (angle > M_PI && angle < M_PI * 2))
			step->y = 1;
		step->x = get_x(step->y, angle);
	}
}

/* Digital Differential Analysis - walking along the y-axis */
int	dda_y_axis(t_point *ns, t_data *data, t_goat *goat, double angle)
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
	printf("\n*** Y AXIS ***");
	i = 0;
	get_first_step(&first_step, angle, Y_AXIS, goat);
	get_steps(&step, angle, Y_AXIS);
	printf("FS.x = %f, FS.y = %f, S.x = %f, S.y = %f\n", first_step.x, first_step.y, step.x, step.y);
	while (is_inside_map(ns, data))
	{
		if (i == 0)
		{
			ns->x = goat->x + first_step.x;
			ns->y = goat->y + first_step.y;
		}
		else
		{
			ns->x = goat->x + first_step.x + i * step.x;
			ns->y = goat->y + first_step.y + i * step.y;
		}
		printf("Round %zu: ns->x = %f, ns->y = %f\n", i, ns->x, ns->y);
		printf("map[%d][%d] is %c\n", (int)round(ns->y), (int)ns->x, map[(int)round(ns->y)][(int)ns->x]);
		if (map[(int)round(ns->y)][(int)ns->x] == '1' && step.y > 0)
			return (SOUTH);
		else if (map[(int)round(ns->y)][(int)ns->x] == '1')
			return (NORTH);
		i++;
	}
	return (1);
}

/* Digital Differential Analysis - walking along the x-axis */
int	dda_x_axis(t_point *ew, t_data *data, t_goat *goat, double angle)
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
	printf("\n*** X AXIS ***");
	i = 0;
	printf("angle is %f\n", angle);
	get_first_step(&first_step, angle, X_AXIS, goat);
	get_steps(&step, angle, X_AXIS);
	printf("FS.x = %f, FS.y = %f, S.x = %f, S.y = %f\n", first_step.x, first_step.y, step.x, step.y);
	while (is_inside_map(ew, data))
	{
		if (i == 0)
		{
			ew->x = goat->x + first_step.x;
			ew->y = goat->y + first_step.y;
		}
		else
		{
			ew->x = goat->x + first_step.x + i * step.x;
			ew->y = goat->y + first_step.y + i * step.y;
		}
		printf("Round %zu: ew->x = %f, ew->y = %f\n", i, ew->x, ew->y);
		printf("map[%d][%d] is %c\n", (int)round(ew->y), (int)ew->x, map[(int)round(ew->y)][(int)ew->x]);
		if (map[(int)round(ew->y)][(int)ew->x] == '1' && step.x > 0)
			return (EAST);
		else if (map[(int)round(ew->y)][(int)ew->x] == '1')
			return (WEST);
		i++;
	}
	return (PARALLEL);
}

double	calc_distance_from_wall(t_data *data, t_goat *goat, double ray_angle)
{
	t_point	ew;
	t_point	ns;
	
	ew.facing = dda_x_axis(&ew, data, goat, to_rad(goat->angle + ray_angle));
	ns.facing = dda_y_axis(&ns, data, goat, to_rad(goat->angle + ray_angle));
	if (dist_to_wall(ew, goat) > dist_to_wall(ns, goat))
		return (sqrt(pow(ns.x - goat->x, 2) + pow(ns.y - goat->y, 2)) * cos(to_rad(ray_angle)));
	else
		return (sqrt(pow(ew.x - goat->x, 2) + pow(ew.y - goat->y, 2)) * cos(to_rad(ray_angle)));
}

void	casting_rays(t_data *data, t_goat *goat)
{
	int32_t	xi;
	int32_t	yi;
	int32_t	top_wall;
	int32_t	bottom_wall;
	double	distance;
	
	xi = 0;
	// while (xi < WIDTH)
	while (xi < 1)
	{
		distance = calc_distance_from_wall(data, goat, FOV / 2 - (double)xi * FOV / (WIDTH - 1));
		printf("dist is %f\n", distance);	// delete
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
