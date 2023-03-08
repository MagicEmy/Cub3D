/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   casting_rays.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 10:34:29 by dmalacov      #+#    #+#                 */
/*   Updated: 2023/03/08 17:22:47 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "cub3D_defines.h"
#include "cub3D.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int	hits_wall(t_data *data, t_ray *ray)
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
	
	(void)data;	// remove
	if (ray->facing == NORTH && map[(int)ray->y - 1][(int)floor(ray->x)] == '1')
		return (TRUE);
	if (ray->facing == WEST && map[(int)floor(ray->y)][(int)ray->x - 1] == '1')
		return (TRUE);
	if ((ray->facing == EAST || ray->facing == SOUTH) && \
	map[(int)floor(ray->y)][(int)floor(ray->x)] == '1')
		return (TRUE);
	else
		return (FALSE);
}

/* Digital Differential Analysis - walking along the y-axis */
double	dda_y_axis(t_ray *ns, t_data *data, double angle)
{
	t_point	step;
	t_point	first_step;
	size_t	i;

	if (angle == 0 || angle == M_PI)
		return (PARALLEL);
	data->map = NULL;	// DELETE
	i = 0;
	get_first_step(&first_step, angle, Y_AXIS, data->goat);
	get_steps(&step, angle, Y_AXIS);
	ns->facing = facing_what(&step, Y_AXIS);
	ns->x = data->goat->x + first_step.x;
	ns->y = data->goat->y + first_step.y;
	ns->dist = dist_to_wall(ns, data->goat, step);
	while (is_inside_map(ns, data))
	{
		if (hits_wall(data, ns))
			break ;
		ns->x = data->goat->x + first_step.x + i * step.x;
		ns->y = data->goat->y + first_step.y + i * step.y;
		ns->dist = dist_to_wall(ns, data->goat, step);
		i++;
	}
	return (ns->dist);
}

/* Digital Differential Analysis - walking along the x-axis */
double	dda_x_axis(t_ray *ew, t_data *data, double angle)
{
	t_point	step;
	t_point	first_step;
	size_t	i;

	if (angle == M_PI_2 || angle == 3 * M_PI_2)
		return (PARALLEL);
	data->map = NULL;	// DELETE
	i = 1;
	get_first_step(&first_step, angle, X_AXIS, data->goat);
	get_steps(&step, angle, X_AXIS);
	ew->facing = facing_what(&step, X_AXIS);
	ew->x = data->goat->x + first_step.x;
	ew->y = data->goat->y + first_step.y;
	ew->dist = dist_to_wall(ew, data->goat, step);
	while (is_inside_map(ew, data))
	{
		if (hits_wall(data, ew))
			break ;
		ew->x = data->goat->x + first_step.x + i * step.x;
		ew->y = data->goat->y + first_step.y + i * step.y;
		ew->dist = dist_to_wall(ew, data->goat, step);
		i++;
	}
	return (ew->dist);
}

t_ray	*calc_distance_from_wall(t_data *data, double ray_angle)
{
	t_ray	*ew;
	t_ray	*ns;
	
	ew = malloc(sizeof(t_ray));
	ns = malloc(sizeof(t_ray));
	if (!ew || !ns)
		exit(1);	// include error handling
	ew->dist = dda_x_axis(ew, data, to_rad(data->goat->angle + ray_angle));
	ns->dist = dda_y_axis(ns, data, to_rad(data->goat->angle + ray_angle));
	if ((ew->dist > ns->dist || ew->dist < 0) && ns->dist >= 0)
	{
		ns->dist *= cos(to_rad(ray_angle));
		return (free(ew), ns);
	}
	else if (ew->dist >= 0)
	{
		ew->dist *= cos(to_rad(ray_angle));
		return (free(ns), ew);
	}
	else	// only for debugging; include error handling
	{	
		printf("Sth went wrong - both ray distances are negative!");
		exit (1);
	}
}

void	casting_rays(t_data *data)
{
	t_point	idx;
	t_ray	*ray;
	t_point	goat;
	t_point	wall;
	
	idx.x = 0;
	idx.y = 0;
	goat.x = PADDING + PPU * data->goat->x;
	goat.y = PADDING + PPU * data->goat->y;
	while (idx.x < WIDTH)
	{
		draw_minimap(data, goat);
		ray = calc_distance_from_wall(data, FOV / 2 - \
		(double)idx.x * FOV / (WIDTH - 1));
		// printf("xi: %f - dist is %f\n", idx.x, ray->dist);	// delete
		wall.x = PADDING + PPU * ray->x;
		wall.y = PADDING + PPU * ray->y;
		if (wall.x >= WIDTH || wall.y >= HEIGHT)
		{
			// printf("ray angle: %f, ray hits at [%f,%f]\n", FOV / 2 - \
			// (double)idx.x * FOV / (WIDTH - 1), ray->x, ray->y);
			exit(1);	// include error handling
		}
		draw_scene(data, ray, idx);
		draw_line(data->img, goat, wall, 0xFFC300FF);
		idx.x++;
	}
}
