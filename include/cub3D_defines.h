/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D_defines.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 12:19:05 by emlicame      #+#    #+#                 */
/*   Updated: 2023/03/07 17:52:11 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_DEFINES_H
# define CUB3D_DEFINES_H

# define WIDTH 640 * 2
# define HEIGHT 480 * 2

# define IMG_WIDTH 640
# define IMG_HEIGHT 480

/* for calculations */
# define X_AXIS 0
# define Y_AXIS 1
# define FOV 60

/* walls */
# define WALL_HEIGHT HEIGHT/3
# define PARALLEL -1

# define WALL_CLR 0x4302C7FF

enum	e_wall_sides
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
};

/* for drawing */
# define PPU 15
# define PADDING 10

/* error handling */
# define ERROR_MALLOC			"Memory allocation failed."
# define ERROR_MAP_EXTENSION	"Wrong map extension."
# define ERROR_EMPTY_FILE		"Empty file."

#endif