/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_structures.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:10:08 by dmalacov          #+#    #+#             */
/*   Updated: 2023/03/23 17:44:59 by emlicame         ###   ########.fr       */
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
	double	dist_pp;
}	t_goat;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_coord
{
	int32_t	x;
	int32_t	y;
}	t_coord;

typedef struct s_ray
{
	double	x;
	double	y;
	double	dist;
	int		facing;
}	t_ray;

typedef struct s_images
{
	mlx_image_t		*fire_0;
	mlx_image_t		*fire_1;
	mlx_image_t		*fire_2;
	mlx_image_t		*fire_3;
	mlx_image_t		*fire_4;
	mlx_image_t		*fire_5;
	mlx_image_t		*fire[6];
	mlx_image_t		*door_1;
}	t_images;

typedef struct s_parsing
{
	char			**map;
	size_t			map_width;
	size_t			map_height;
	char			**info_file;
	int32_t			red;
	int32_t			green;
	int32_t			blue;
	unsigned int	ceiling_clr;
	unsigned int	floor_clr;
	int32_t			map_start;
	int32_t			map_end;
	int32_t			counter;
	char			*set;
	char			*no_path;
	char			*so_path;
	char			*ea_path;
	char			*we_path;
	char			*ceiling;
	char			*floor;
	double			player_x;
	double			player_y;
	double			player_angle;
}	t_parsing;

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_image_t		*img_mm;	// minimap -> move to bonus
	unsigned int	floor_clr;
	unsigned int	ceiling_clr;
	unsigned int	nsew_clr[4];		// for testing; will be deleted
	mlx_texture_t	*textures[4];
	t_images		sprites;
	char			**map;
	size_t			map_width;
	size_t			map_height;
	t_goat			*goat;
	int32_t			cursor_x;
	int32_t			cursor_y;
}	t_data;

#endif
