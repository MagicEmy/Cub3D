/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   casting_rays.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 10:34:29 by dmalacov      #+#    #+#                 */
/*   Updated: 2023/03/13 17:47:30 by dmalacov      ########   odam.nl         */
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
	if (ray->facing == NORTH && data->map[(int)ray->y - 1] \
	[(int)floor(ray->x)] == '1')
		return (TRUE);
	if (ray->facing == WEST && data->map[(int)floor(ray->y)] \
	[(int)ray->x - 1] == '1')
		return (TRUE);
	if ((ray->facing == EAST || ray->facing == SOUTH) && \
	data->map[(int)floor(ray->y)][(int)floor(ray->x)] == '1')
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
	i = 0;
	get_first_step(&first_step, angle, Y_AXIS, data->goat);
	get_steps(&step, angle, Y_AXIS);
	ns->facing = facing_what(&step, Y_AXIS);
	ns->x = data->goat->x + first_step.x;
	ns->y = data->goat->y + first_step.y;
	ns->dist = dist_to_wall(ns, data->goat);
	while (is_inside_map(ns, data))
	{
		if (hits_wall(data, ns))
			break ;
		ns->x = data->goat->x + first_step.x + i * step.x;
		ns->y = data->goat->y + first_step.y + i * step.y;
		ns->dist = dist_to_wall(ns, data->goat);
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
	i = 1;
	get_first_step(&first_step, angle, X_AXIS, data->goat);
	get_steps(&step, angle, X_AXIS);
	ew->facing = facing_what(&step, X_AXIS);
	ew->x = data->goat->x + first_step.x;
	ew->y = data->goat->y + first_step.y;
	ew->dist = dist_to_wall(ew, data->goat);
	while (is_inside_map(ew, data))
	{
		if (hits_wall(data, ew))
			break ;
		ew->x = data->goat->x + first_step.x + i * step.x;
		ew->y = data->goat->y + first_step.y + i * step.y;
		ew->dist = dist_to_wall(ew, data->goat);
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
		error_exit(ERROR_MALLOC);
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
	else
		error_exit(ERROR_RAYCAST);
	return (NULL);	// check
}

void	casting_rays(t_data *data)
{
	t_point	idx;
	t_ray	*ray;

	idx.x = 0;
	idx.y = 0;
	while (idx.x < WIDTH)
	{
		ray = calc_distance_from_wall(data, FOV / 2 - \
		(double)idx.x * FOV / (WIDTH - 1));
		draw_scene(data, ray, idx);
		draw_rays(data, ray);
		idx.x++;
	}
}
