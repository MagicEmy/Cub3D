/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 12:16:55 by emlicame      #+#    #+#                 */
/*   Updated: 2023/02/28 13:24:27 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "cub3D_defines.h"
# include "cub3D_structures.h"
# include "colors.h"

# include "MLX42/MLX42.h"
// # include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <memory.h>

/* casting_rays.c */
void	casting_rays(t_data *data, t_goat *goat);
/* casting_utils.c */
double	to_rad(double angle);
int		is_inside_map(t_point *pt, t_data *data);
double	dist_to_wall(t_point pt, t_goat *goat);
/* casting_get.c */
double	get_x(double y_side, double angle);
double	get_y(double x_side, double angle);
void	get_first_step(t_point *first_step, double angle, int axis, t_goat *goat);
void	get_steps(t_point *step, double angle, int axis);

#endif