/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:16:55 by emlicame          #+#    #+#             */
/*   Updated: 2023/02/22 16:48:07 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "cub3D_defines.h"
# include "colors.h"

# include "MLX42/MLX42.h"
# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <memory.h>

typedef struct s_data
{
	mlx_t	*mlx;
	char	**map;
}	t_data;

void	error_exit(char *text);
t_data	*cube_data_init(void);
void	cube_map_validation(char *argv, t_data *data);

void	casting_rays(mlx_image_t *img, int width, int height);

#endif