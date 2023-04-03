/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   casting_rays_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/27 13:11:02 by dmalacov      #+#    #+#                 */
/*   Updated: 2023/04/03 18:00:56 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"
#include <math.h>

static int	st_hits_wall(t_data *data, t_ray *ray)
{
	if (ray->facing == NORTH && ray->y > 0 && data->map[(int)ray->y - 1] \
	[(int)floor(ray->x)] == '1')
		return (TRUE);
	if (ray->facing == WEST && ray->x > 0 && data->map[(int)floor(ray->y)] \
	[(int)ray->x - 1] == '1')
		return (TRUE);
	if ((ray->facing == EAST || ray->facing == SOUTH) && \
	data->map[(int)floor(ray->y)][(int)floor(ray->x)] == '1')
		return (TRUE);
	else
		return (FALSE);
}

static double	st_dda(t_ray *ray, t_data *data, double angle, \
int32_t axis)
{
	t_dda_step	step;
	size_t		i;

	i = 1;
	if ((axis == Y_AXIS && (angle == 0 || angle == M_PI)) || \
	(axis == X_AXIS && (angle == M_PI_2 || angle == 3 * M_PI_2)))
		return (PARALLEL);
	get_steps(&step, data->goat, angle, axis);
	ray->facing = facing_what(&step.next, axis);
	ray->x = data->goat->x + step.first.x;
	ray->y = data->goat->y + step.first.y;
	dist_to_wall(ray, data->goat);
	while (is_inside_map(ray, data))
	{
		if (st_hits_wall(data, ray))
			break ;
		ray->x = data->goat->x + step.first.x + i * step.next.x;
		ray->y = data->goat->y + step.first.y + i * step.next.y;
		dist_to_wall(ray, data->goat);
		i++;
	}
	if (ray->dist > 0 && ray->dist < STEP_LENGTH / 100)
		return (STEP_LENGTH / 100);
	else
		return (ray->dist);
}

static int32_t	which_wall(t_ray *ew, t_ray *ns, int32_t facing, \
double ray_angle)
{
	if (ew->dist == ns->dist && ew->dist >= 0 && (facing == NORTH || \
	facing == SOUTH))
	{
		ns->dist *= cos(to_rad(ray_angle));
		return (facing);
	}
	else if (ew->dist == ns->dist && ew->dist >= 0 && (facing == EAST || \
	facing == WEST))
	{
		ew->dist *= cos(to_rad(ray_angle));
		return (facing);
	}
	else if ((ew->dist > ns->dist || ew->dist < 0) && ns->dist >= 0)
	{
		ns->dist *= cos(to_rad(ray_angle));
		return (ns->facing);
	}
	else if (ew->dist >= 0)
	{
		ew->dist *= cos(to_rad(ray_angle));
		return (ew->facing);
	}
	else
		return (-1);
}

static t_ray	*st_calc_dist_from_wall(t_data *data, double ray_angle, \
int32_t facing)
{
	t_ray	*ew;
	t_ray	*ns;
	int32_t	wall;

	ew = malloc(sizeof(t_ray));
	ns = malloc(sizeof(t_ray));
	if (!ew || !ns)
		error_exit(ERROR_MALLOC);
	ew->dist = st_dda(ew, data, to_rad(data->goat->angle + ray_angle), X_AXIS);
	ns->dist = st_dda(ns, data, to_rad(data->goat->angle + ray_angle), Y_AXIS);
	wall = which_wall(ew, ns, facing, ray_angle);
	if (wall == NORTH || wall == SOUTH)
		return (free(ew), ns);
	else if (wall == EAST || wall == WEST)
		return (free(ns), ew);
	else
		error_exit(ERROR_RAYCAST);
	return (NULL);
}

void	casting_rays(t_data *data)
{
	t_coord	idx;
	t_ray	*ray;
	int32_t	facing;

	idx.x = 0;
	idx.y = 0;
	facing = -1;
	while (idx.x < WIDTH)
	{
		ray = st_calc_dist_from_wall(data, FOV / 2 - \
		(double)idx.x * FOV / WIDTH, facing);
		if (!ray)
			error_exit(ERROR_UNEXP);
		draw_scene(data, ray, idx);
		if (idx.x % 10 == 0 || idx.x % 9 == 0)
			draw_rays(data, ray);
		facing = ray->facing;
		free(ray);
		idx.x++;
	}
}
