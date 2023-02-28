/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   casting_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 11:04:01 by dmalacov      #+#    #+#                 */
/*   Updated: 2023/02/28 13:24:12 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3D_structures.h"

double	to_rad(double angle)
{
	return (angle * M_PI / 180);
}


int	is_inside_map(t_point *pt, t_data *data)
{
	if (pt->x < 0 || pt->x >= data->map_width || pt->y < 0 || pt->y >= data->map_height)
		return (0);
	return (1);
}

double	dist_to_wall(t_point pt, t_goat *goat)
{
	return (sqrt(pow(pt.x - goat->x, 2) + pow(pt.y - goat->y, 2)));
}
