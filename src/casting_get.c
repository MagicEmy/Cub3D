/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   casting_get.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: darina <darina@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/28 13:16:58 by dmalacov      #+#    #+#                 */
/*   Updated: 2023/02/28 13:24:32 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3D.h"

double	get_x(double y_side, double angle)
{
	return (y_side / tan(angle) * -1);
}

double	get_y(double x_side, double angle)
{
	return (x_side * tan(angle) * -1);
}

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