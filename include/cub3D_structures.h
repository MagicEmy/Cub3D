/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D_structures.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 13:10:08 by dmalacov      #+#    #+#                 */
/*   Updated: 2023/02/23 19:07:00 by dmalacov      ########   odam.nl         */
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
	int		facing;
}	t_point;

typedef struct s_data
{
    mlx_t		*mlx;
	mlx_image_t	*img;
    char		**map;
	int32_t		map_width;
	int32_t		map_height;
	int32_t		floor_clr;
	int32_t		sky_clr;
}	t_data;

#endif
