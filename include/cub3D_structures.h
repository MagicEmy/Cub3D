/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_structures.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:10:08 by dmalacov          #+#    #+#             */
/*   Updated: 2023/03/15 11:11:33 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCTURES_H
# define CUB3D_STRUCTURES_H

# include <stdint.h>
# include <stdlib.h>
# include "MLX42/MLX42.h"

typedef struct s_goat
{
	double	x;
	double	y;
	double	angle;
}	t_goat;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_ray
{
	double	x;
	double	y;
	double	dist;
	int		facing;
}	t_ray;

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

typedef struct s_texture
{
	mlx_texture_t		*north;
	mlx_texture_t		*south;
	mlx_texture_t		*east;
	mlx_texture_t		*west;
}	t_texture;

// t_file_info	file_info;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	char		*no_path;
	char		*so_path;
	char		*ea_path;
	char		*we_path;
	char		*floor;
	int32_t		floor_clr;
	int32_t		sky_clr;
	int32_t		floor_red;
	int32_t		floor_green;
	int32_t		floor_blue;
	char		*ceiling;
	int32_t		ceiling_red;
	int32_t		ceiling_green;
	int32_t		ceiling_blue;
	int32_t		counter;
	char		**info_file;
	char		**map;
	char		**the_map;
	size_t		map_width;
	size_t		map_height;
	int32_t		map_start;
	int32_t		map_end;
	t_texture	texture;
	t_goat		*goat;
}	t_data;

#endif
