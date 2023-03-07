/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_structures.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:10:08 by dmalacov          #+#    #+#             */
/*   Updated: 2023/03/07 17:29:38 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCTURES_H
# define CUB3D_STRUCTURES_H

# include "MLX42/MLX42.h"
# include <stdint.h>

typedef struct s_goat
{
	int32_t	x;
	int32_t	y;
	double	angle;
}	t_goat;

typedef struct s_file_info
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*floor;
	char	*ceiling;
	char	**map;
}	t_file_info;

typedef struct s_data
{
	mlx_t		*mlx;
	// t_file_info	file_info;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	char		*floor;
	int			floor_red;
	int			floor_green;
	int			floor_blue;
	char		*ceiling;
	int			ceiling_red;
	int			ceiling_green;
	int			ceiling_blue;
	int			counter;
	char		**info_file;
	char		**map;
}	t_data;

#endif
