/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   casting_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 11:04:01 by dmalacov      #+#    #+#                 */
/*   Updated: 2023/03/20 16:29:46 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3D_structures.h"
#include "cub3D_defines.h"
#include <stdio.h>	// delete

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
		return (FALSE);
	return (TRUE);
}

void	dist_to_wall(t_ray *ray, t_goat *goat)
{
	double	dx;
	double	dy;

	dx = fabs(ray->x - goat->x);
	dy = fabs(ray->y - goat->y);
	ray->dist = sqrt(pow(dx, 2) + pow(dy, 2));
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

int	is_accessible(t_data *data, double x, double y)
{
	t_point	pos;

	pos.x = data->goat->x;
	pos.y = data->goat->y;
	if (floor(pos.x) != floor(pos.x + x) && floor(pos.y) != floor(pos.y + y) && \
	(data->map[(int)floor(pos.y + y)][(int)floor(pos.x)] == '1' && \
	data->map[(int)floor(pos.y)][(int)floor(pos.x + x)] == '1'))
		return (FALSE);
	if (data->map[(int)floor(pos.y + y / 2)][(int)floor(pos.x + x / 2)] == '1' \
	|| data->map[(int)floor(pos.y + y)][(int)floor(pos.x + x)] == '1')
		return (FALSE);
	else
		return (TRUE);
}
