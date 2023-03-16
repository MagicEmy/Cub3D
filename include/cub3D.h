/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 12:16:55 by emlicame      #+#    #+#                 */
/*   Updated: 2023/03/16 16:57:13 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "cub3D_defines.h"
# include "cub3D_structures.h"
# include "colors.h"

# include "MLX42/MLX42.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <memory.h>
# include <stdio.h>

/* casting_rays.c */
void	casting_rays(t_data *data);
/* casting_utils.c */
double	to_rad(double angle);
int		is_inside_map(t_ray *ray, t_data *data);
double	dist_to_wall(t_ray *ray, t_goat *goat);
int		is_accessible(t_data *data, double x, double y);
int		facing_what(t_point *step, int axis);
/* casting_get.c */
double	get_x(double y_side, double angle);
double	get_y(double x_side, double angle);
void	get_first_step(t_point *first_step, double angle, int axis, \
		t_goat *goat);
void	get_first_step(t_point *first_step, double angle, \
int axis, t_goat *goat);
void	get_steps(t_point *step, double angle, int axis);
void	get_line_steps(t_point *step, t_point a, t_point b);
/* drawing.c */
void	draw_scene(t_data *data, t_ray *ray, t_point idx);
void	draw_line(mlx_image_t *img, t_point a, t_point b, int32_t clr);
// void	draw_texture(t_data *data, t_ray *ray, int32_t wall_height, t_point idx); // perhaps static
/* drawing_bonus.c */
void	draw_minimap(t_data *data);
void	draw_rays(t_data *data, t_ray *ray);
/* hooks.c */
void	go_left_right(int key, t_data *data);
void	go_fwd_bck(int key, t_data *data);
void	look_left_right(int key, t_data *data);
void	mouse_hook(double xpos, double ypos, void *param);
void	print_goat_info(t_data *data);	// for debugging only
/* textures.c */
int32_t	get_rgba(int r, int g, int b, int a);
/* main.c */
void	error_exit(char *text);
/* cube_data_init.c */
t_data	*cube_data_init(void);
/* parsing.c */
char	*get_line(char *argv, t_data *data);
// t_data	*cube_data_init(void);

// char	*get_line(char *argv, t_data *data);
void	cube_check_extension(char *argv);
void	info_map_parsing(char *argv, t_data *data);
/* info_validation.c */
void	texture_acquisition(t_data *data);
void	rgb_validation(t_data *data);
void	check_map_syntax(t_data *data);
void	map_validation(t_data *data);
void	get_map_size(t_data *data);
void	map_equalizer(t_data *data);

//get_next_line
char	*get_next_line(int fd);
char	*gnl_ft_strjoin_free(char *s1, char *s2);
int		check_where_newline(char *buff, int c);

#endif