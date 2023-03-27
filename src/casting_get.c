/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   casting_get.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: darina <darina@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/28 13:16:58 by dmalacov      #+#    #+#                 */
/*   Updated: 2023/03/27 12:18:01 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3D.h"

void	get_steps_x(t_dda_step *step, double angle, t_goat *goat)
{
	if (angle > M_PI_2 && angle < M_PI_2 * 3)
	{
		step->first.x = floor(goat->x) - goat->x;
		step->next.x = -1;
	}
	else if (angle < M_PI_2 || angle > M_PI_2 * 3)
	{
		step->first.x = ceil(goat->x) - goat->x;
		step->next.x = 1;
	}
	step->first.y = step->first.x * tan(angle) * -1;
	step->next.y = step->next.x * tan(angle) * -1;
}

void	get_steps_y(t_dda_step *step, double angle, t_goat *goat)
{
	if ((angle > 0 && angle < M_PI) || angle > 2 * M_PI)
	{
		step->first.y = floor(goat->y) - goat->y;
		step->next.y = -1;
	}
	else if (angle < 0 || (angle > M_PI && angle < M_PI * 2))
	{
		step->first.y = ceil(goat->y) - goat->y;
		step->next.y = 1;
	}
	step->first.x = step->first.y / tan(angle) * -1;
	step->next.x = step->next.y / tan(angle) * -1;
}

void	get_steps(t_dda_step *step, t_goat *goat, double angle, \
int32_t axis)
{
	if (axis == X_AXIS)
		get_steps_x(step, angle, goat);
	else
		get_steps_y(step, angle, goat);
}

void	get_line_steps(t_point *step, t_point a, t_point b)
{
	if (fabs(b.x - a.x) > fabs(b.y - a.y))
	{
		step->x = (b.x - a.x) / fabs(b.x - a.x);
		step->y = (b.y - a.y) / fabs(b.x - a.x);
	}
	else
	{
		step->x = (b.x - a.x) / fabs(b.y - a.y);
		step->y = (b.y - a.y) / fabs(b.y - a.y);
	}
}
