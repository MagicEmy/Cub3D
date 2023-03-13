/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D_structures.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 13:10:08 by dmalacov      #+#    #+#                 */
/*   Updated: 2023/03/13 16:51:14 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCTURES_H
# define CUB3D_STRUCTURES_H

# include <stdint.h>
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

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_image_t		*img_mm;	// minimap -> move to bonus
	// t_file_info	file_info;
	char			*no_path;
	char			*so_path;
	char			*ea_path;
	char			*we_path;
	char			*floor;
	unsigned int	floor_clr;
	unsigned int	sky_clr;
	unsigned int	nsew_clr[4];		// for testing; will be deleted
	int				floor_red;
	int				floor_green;
	int				floor_blue;
	char			*ceiling;
	int				ceiling_red;
	int				ceiling_green;
	int				ceiling_blue;
	int				counter;
	char			**info_file;
	char			**map;
	int32_t			map_width;
	int32_t			map_height;
	t_texture		texture;
	t_goat			*goat;
	int32_t			cursor_x;
	int32_t			cursor_y;
}	t_data;

#endif
