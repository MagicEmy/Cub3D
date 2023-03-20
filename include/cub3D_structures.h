/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D_structures.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 13:10:08 by dmalacov      #+#    #+#                 */
/*   Updated: 2023/03/20 17:42:16 by dmalacov      ########   odam.nl         */
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
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_image_t		*img_mm;	// minimap -> move to bonus
	char			*no_path;	// these can be local variables (a struct perhaps)
	char			*so_path;	// these can be local variables (a struct perhaps)
	char			*ea_path;	// these can be local variables (a struct perhaps)
	char			*we_path;	// these can be local variables (a struct perhaps)
	char			*floor;		// these can be local variables (a struct perhaps)
	unsigned int	floor_clr;
	unsigned int	sky_clr;
	unsigned int	nsew_clr[4];		// for testing; will be deleted
	char			*ceiling;	// these can be local variables (a struct perhaps)
	char			**info_file;
	char			**map;
	char			*set;			// can be local var in the function
	size_t			map_width;
	size_t			map_height;
	t_texture		texture;
	t_goat			*goat;
	int32_t			cursor_x;
	int32_t			cursor_y;
	int32_t			floor_red;		// these can be local variables (struct perhaps)
	int32_t			floor_green;	// these can be local variables (struct perhaps)
	int32_t			floor_blue;		// these can be local variables (struct perhaps)
	int32_t			ceiling_red;	// these can be local variables (struct perhaps)
	int32_t			ceiling_green;	// these can be local variables (struct perhaps)
	int32_t			ceiling_blue;	// these can be local variables (struct perhaps)
	int32_t			counter;		// can be local var in the function
	int32_t			map_start;		// can be local var in the function
	int32_t			map_end;		// can be local var in the function
}	t_data;

#endif
