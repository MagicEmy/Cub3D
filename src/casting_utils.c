/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   casting_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 11:04:01 by dmalacov      #+#    #+#                 */
/*   Updated: 2023/03/13 16:29:36 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3D_structures.h"
#include "cub3D_defines.h"

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

double	dist_to_wall(t_ray *ray, t_goat *goat)
{
	double	dx;
	double	dy;

	dx = fabs(ray->x - goat->x);
	dy = fabs(ray->y - goat->y);
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

int	is_wall(t_data *data, double x, double y)
{
	if (data->map[(int)floor(data->goat->y + y / 2)] \
	[(int)floor(data->goat->x + x / 2)] == '1')
		return (1);
	else if (data->map[(int)floor(data->goat->y + y)] \
	[(int)floor(data->goat->x + x)] == '1')
		return (1);
	else
		return (0);
}
