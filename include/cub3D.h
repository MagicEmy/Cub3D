/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:16:55 by emlicame          #+#    #+#             */
/*   Updated: 2023/03/27 12:18:23 by emlicame         ###   ########.fr       */
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
void	get_first_step(t_point *first_step, double angle, int axis, \
		t_goat *goat);
void	get_first_step(t_point *first_step, double angle, \
int axis, t_goat *goat);
void	get_steps(t_point *step, double angle, int axis);
void	get_line_steps(t_point *step, t_point a, t_point b);
/* drawing.c */
void	draw_scene(t_data *data, t_ray *ray, t_coord idx);
void	draw_line(mlx_image_t *img, t_point a, t_point b, int32_t clr);
/* drawing_bonus.c */
void	draw_minimap(t_data *data);
void	draw_rays(t_data *data, t_ray *ray);
/* drawing_get_bonus.c */
int32_t	get_min(int32_t a, int32_t b);
void	get_xy_offset(t_data *data);

/* hooks.c */
void	go_left_right(int key, t_data *data);
void	go_fwd_bck(int key, t_data *data);
void	look_left_right(int key, t_data *data);
void	mouse_hook(double xpos, double ypos, void *param);
void	key_hooks(void *param);
void	print_goat_info(t_data *data);	// for debugging only
/* textures.c */
int32_t	get_rgba(int r, int g, int b, int a);
void	texture_x_coord(t_coord *txt, t_ray *ray, mlx_texture_t *texture);
void	texture_put_pixel(t_data *data, t_coord *idx, t_coord *txt, \
		mlx_texture_t *tx);
/* main.c */
void	error_exit(char *text);

/* parsing.c */
void	parsing(char *argv, t_data *data);

/* parsing_init.c  */
void	parsing_to_data(t_data *data, t_parsing *parsing);
void	parsing_stru_init(t_parsing *parsing);
void	parsing_free(t_parsing *parsing);

/* info_validation.c */
void	texture_acquisition(t_parsing *parsing, t_data *data);
void	rgb_validation(t_parsing *parsing);
void	check_map_syntax(t_parsing *parsing);

/* map_equalizer.c */
void	map_equalizer(t_parsing *parsing);

/* map_validation.c */
void	map_validation(t_parsing *parsing);

//get_next_line
char	*get_next_line(int fd);
char	*gnl_ft_strjoin_free(char *s1, char *s2);
int		check_where_newline(char *buff, int c);

#endif