/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D_bonus.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 12:16:55 by emlicame      #+#    #+#                 */
/*   Updated: 2023/04/03 18:07:30 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "cub3D_defines_bonus.h"
# include "cub3D_structures_bonus.h"
# include "libft.h"

/* casting_rays_bonus.c */
void	casting_rays(t_data *data);

/* casting_utils_bonus.c */
double	to_rad(double angle);
int		is_inside_map(t_ray *ray, t_data *data);
double	dist_to_wall(t_ray *ray, t_goat *goat);
int		is_accessible(t_data *data, double x, double y);
int		facing_what(t_point *step, int axis);

/* casting_get_bonus.c */
void	get_steps(t_dda_step *step, t_goat *goat, double angle, \
		int32_t axis);
void	get_steps_x(t_dda_step *step, double angle, t_goat *goat);
void	get_steps_y(t_dda_step *step, double angle, t_goat *goat);
void	get_line_steps(t_point *step, t_point a, t_point b);

/* drawing_basic_bonus.c */
void	draw_scene(t_data *data, t_ray *ray, t_coord idx);
void	draw_line(mlx_image_t *img, t_point a, t_point b, int32_t clr);
void	draw_bckground(t_data *data);

/* drawing_bonus.c */
void	draw_minimap(t_data *data);
void	draw_rays(t_data *data, t_ray *ray);

/* drawing_get_bonus.c */
int32_t	get_min(int32_t a, int32_t b);
void	get_xy_offset(t_data *data);
void	get_img_cleaned(mlx_image_t *img);

/* hooks_bonus.c */
void	go_left_right(int key, t_data *data);
void	go_fwd_bck(int key, t_data *data);
void	look_left_right(int key, t_data *data);
void	mouse_hook(double xpos, double ypos, void *param);
void	key_hooks(void *param);

/* textures_bonus.c */
int32_t	get_rgba(int r, int g, int b, int a);
void	texture_x_coord(t_coord *txt, t_ray *ray, mlx_texture_t *texture);
void	texture_put_pixel(t_data *data, t_coord *idx, t_coord *txt, \
		mlx_texture_t *tx);
/* main_bonus.c */
void	error_exit(char *text);

/* parsing_bonus.c */
void	parsing(char *argv, t_data *data);

/* info_file_safety_check_bonus.c */
int32_t	info_file_safety_check(t_parsing *parsing, char *line);

/* parsing_init_bonus.c  */
void	parsing_to_data(t_data *data, t_parsing *parsing);
void	parsing_stru_init(t_parsing *parsing);
void	parsing_free(t_parsing *parsing);

/* textures_bonus.c */
void	texture_acquisition(t_parsing *parsing, t_data *data);

/* rgb_validation_bonus.c  */
void	rgb_validation(t_parsing *parsing);

/* check_map_syntax_bonus.c */
void	check_map_syntax(t_parsing *parsing);

/* map_equalizer_bonus.c */
void	map_equalizer(t_parsing *parsing);

/* map_validation_bonus.c */
void	map_validation(t_parsing *parsing);

/* get_next_line */
char	*get_next_line(int fd);
char	*gnl_ft_strjoin_free(char *s1, char *s2);

/* get_next_line_utils.c */
int		check_where_newline(char *buff, int c);

#endif