/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   casting_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 11:04:01 by dmalacov      #+#    #+#                 */
/*   Updated: 2023/03/02 17:07:14 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3D_structures.h"
#include "cub3D_defines.h"
#include <stdio.h>	// DELETE

double	to_rad(double angle)
{
	if (angle == 360)
		angle = 0;
	return (angle * M_PI / 180);
}


int	is_inside_map(t_ray *ray, t_data *data)
{
	if (ray->x < 0 || ray->x > data->map_width - 1 || ray->y < 0 || \
	ray->y > data->map_height - 1)
		return (0);
	return (1);
}

double	dist_to_wall(t_ray *ray, t_goat *goat, t_point step)
{
	double	dx;
	double	dy;
	
	// if facing NORTH
	// 		dy += 1 (step.y is -1)
	// 		dx += abs(step.x)
	// if facing WEST
	// 		dx += abs(step.x)
	// 		dy += abs(step.y)

	//  OR
	// if facing NORTH
	// 		goat.y + 1
	// if facing WEST
	// 		goat.x + 1
	dx = fabs(ray->x - goat->x);
	dy = fabs(ray->y - goat->y);
	// if (ray->facing == NORTH)
	// 	dy += 1;
	// if (ray->facing == WEST)
	// 	dx += 1;
	(void)step.x;
	
	// if ((step.x < 0 && ray->facing == WEST) || (step.y < 0 && ray->facing == NORTH))
	// 	return (sqrt(pow(ray->x - goat->x, 2) + pow(ray->y - goat->y, 2)) \
	// 	* cos(to_rad(ray_angle)) + 1);
	// else
	return (sqrt(pow(dx, 2) + pow(dy, 2)));
}

int	facing_what(t_point *step, int axis)
{
	if (axis == X_AXIS && step->x > 0)
		return (EAST);
	else if (axis == X_AXIS)
		return (WEST);
	if (axis == Y_AXIS && step->y > 0)
		return (SOUTH);
	else
		return (NORTH);
}

int	is_wall(t_data *data, int x, int y)
{
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
	
	// printf("* is wall: map is %c\n", map[(int)round(data->goat->y) + y][(int)round(data->goat->x) + x]);
	if (map[(int)floor(data->goat->y) + y][(int)floor(data->goat->x) + x] \
	== '1')
		return (1);
	else
		return (0);
}
