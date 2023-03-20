/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:10:08 by dmalacov          #+#    #+#             */
/*   Updated: 2023/03/19 17:38:38 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSER_H
# define CUB3D_PARSER_H

# include "cub3D_defines.h"
# include "cub3D_structures.h"
# include "colors.h"

# include "MLX42/MLX42.h"
# include "libft.h"

typedef struct s_parsing
{
	char			**map;
	size_t			map_width;
	size_t			map_height;
	char			**info_file;
	int32_t			floor_red;
	int32_t			floor_green;
	int32_t			floor_blue;
	unsigned int	ceiling_clr;
	unsigned int	floor_clr;
	int32_t			ceiling_red;
	int32_t			ceiling_green;
	int32_t			ceiling_blue;
	int32_t			map_start;
	int32_t			map_end;
	int32_t			counter;
	char			*set;
	char			*ceiling;
	char			*no_path;
	char			*so_path;
	char			*ea_path;
	char			*we_path;
	char			*floor;
	double			player_x;
	double			player_y;
	double			player_angle;
}	t_parsing;

/* parsing.c */
void	info_map_parsing(char *argv, t_data *data);

/* parsing_init.c  */
void	parsing_to_data(t_data *data, t_parsing *parsing);
void	parsing_stru_init(t_parsing *parsing);

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