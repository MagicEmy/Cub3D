/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:16:55 by emlicame          #+#    #+#             */
/*   Updated: 2023/03/07 16:58:55 by emlicame         ###   ########.fr       */
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
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <memory.h>

void	error_exit(char *text);
t_data	*cube_data_init(void);

char	*get_line(char *argv, t_data *data);
void	info_map_parsing(char *argv, t_data *data);
void	rgb_validation(t_data *data);

void	casting_rays(mlx_image_t *img, int width, int height);

//get_next_line
char	*get_next_line(int fd);
char	*gnl_ft_strjoin_free(char *s1, char *s2);
int		check_where_newline(char *buff, int c);

#endif