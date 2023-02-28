/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   casting_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 11:04:01 by dmalacov      #+#    #+#                 */
/*   Updated: 2023/02/28 18:59:47 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3D_structures.h"
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

double	dist_to_wall(t_ray *ray, t_goat *goat)
{
	return (sqrt(pow(ray->x - goat->x, 2) + pow(ray->y - goat->y, 2)));
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
