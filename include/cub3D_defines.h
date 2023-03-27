/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D_defines.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 12:19:05 by emlicame      #+#    #+#                 */
/*   Updated: 2023/03/27 13:03:05 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DEFINES_H
# define CUB3D_DEFINES_H

/* general stuff */
# define TRUE 1
# define FALSE 0

# define WIDTH 640
# define HEIGHT 480
# define IMG_WIDTH 640
# define IMG_HEIGHT 480
# define UNIT 125

/* for calculations */
# define X_AXIS 0
# define Y_AXIS 1
# define FOV 60
# define STEP_LENGTH 0.05

/* walls */
# define WALL_HEIGHT 120
# define PARALLEL -1

/* colours */
# define WALL_OUTLINE 0xFFFFFFFF
# define WALL_FILL 0x4302C7FF
# define GOAT_CLR 0xFF00FFFF

enum	e_wall_sides
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
};

# define E 0
# define N 90
# define W 180
# define S 270

/* for drawing */
# define PPU 10			// bonus
# define PAD 10

/* error handling */
# define BUFFER_SIZE			1

# define ERROR_ARGS				"Amount of arguments not valid."
# define ERROR_MALLOC			"Memory allocation failed."
# define ERROR_OPEN_FAIL		"File opening failed."
# define ERROR_MAP_EXTENSION	"Wrong map extension."
# define ERROR_EMPTY_MAP		"Empty map."
# define ERROR_INVALID_INFO		"Insufficient or wrong information provided."
# define ERROR_INVALID_FILE		"Invalid file."
# define ERROR_EMPTY_FILE		"Empty file."
# define ERROR_DOUBLE_ENTRY		"Double entry."
# define ERROR_NO_RGB			"RGB input missing."
# define ERROR_RGB_ERR			"Wrong RGB input."
# define ERROR_PATH_TEXTURE		"Invalid path to texture."
# define ERROR_INVALID_CHAR		"Invalid char in map."
# define ERROR_RAYCAST			"Something went wrong while casting rays."
# define ERROR_INVALID_MAP		"Invalid map format."
# define ERROR_INVALID_MAP_W	"Invalid map, map is not enclosed in walls."
# define ERROR_PLAYER_COUNT		"Amount of Player starting position is not 1."
# define ERROR_UNEXP			"Unexpected error."

#endif