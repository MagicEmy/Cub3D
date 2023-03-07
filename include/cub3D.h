/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 12:16:55 by emlicame      #+#    #+#                 */
/*   Updated: 2023/03/07 19:59:38 by dmalacov      ########   odam.nl         */
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
void	casting_rays(t_data *data);
/* casting_utils.c */
double	to_rad(double angle);
int		is_inside_map(t_ray *ray, t_data *data);
double	dist_to_wall(t_ray *ray, t_goat *goat, t_point step);
int		is_wall(t_data *data, double x, double y);
int		facing_what(t_point *step, int axis);
/* casting_get.c */
double	get_x(double y_side, double angle);
double	get_y(double x_side, double angle);
void	get_first_step(t_point *first_step, double angle, int axis, t_goat *goat);
void	get_steps(t_point *step, double angle, int axis);
/* drawing.c */
void	draw_scene(t_data *data, t_ray *ray, t_point idx);
void	draw_line(mlx_image_t *img, t_point a, t_point b, int32_t clr);
/* drawing_bonus.c */
void	draw_minimap(t_data *data, t_point goat);
/* hooks.c */
void	go_left_right(int key, t_data *data);
void	go_up_down(int key, t_data *data);
void	look_left_right(int key, t_data *data);
#endif