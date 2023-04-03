/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:28:00 by emlicame          #+#    #+#             */
/*   Updated: 2023/04/03 13:32:00 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	st_player_placement(t_parsing *parsing, int32_t y, int32_t x)
{
	parsing->player_y = y + 0.5;
	parsing->player_x = x + 0.5;
	if (parsing->map[y][x] == 'E')
		parsing->player_angle = E;
	if (parsing->map[y][x] == 'N')
		parsing->player_angle = N;
	if (parsing->map[y][x] == 'W')
		parsing->player_angle = W;
	if (parsing->map[y][x] == 'S')
		parsing->player_angle = S;
}

static void	st_check_walls_top_bottom(t_parsing *parsing, int32_t y)
{
	int32_t	x;

	x = 0;
	while (parsing->map[y][x])
	{
		if (parsing->map[y][x] != ' ' && parsing->map[y][x] != '1')
			error_exit(ERROR_INVALID_MAP_W);
		x++;
	}
}

static int	st_is_map_space(char c)
{
	if (c == ' ' || c == '\n')
		return (1);
	return (0);
}

static void	st_check_walls_middle(t_parsing *parsing, int32_t y, int32_t x)
{
	if (ft_strchr("0NSEW", parsing->map[y][x]))
	{
		if (ft_strchr("NSEW", parsing->map[y][x]))
			st_player_placement(parsing, y, x);
		if (st_is_map_space(parsing->map[y][x + 1]) || \
			st_is_map_space(parsing->map[y][x - 1]))
			error_exit(ERROR_INVALID_MAP_W);
		if (st_is_map_space(parsing->map[y - 1][x]) || \
			st_is_map_space(parsing->map[y - 1][x + 1]) || \
			st_is_map_space(parsing->map[y - 1][x - 1]))
			error_exit(ERROR_INVALID_MAP_W);
		if (st_is_map_space(parsing->map[y + 1][x]) || \
			st_is_map_space(parsing->map[y + 1][x + 1]) || \
			st_is_map_space(parsing->map[y + 1][x - 1]))
			error_exit(ERROR_INVALID_MAP_W);
	}
}

void	map_validation(t_parsing *parsing)
{
	int32_t	x;
	int32_t	y;

	y = 0;
	st_check_walls_top_bottom(parsing, y);
	y = 1;
	while (parsing->map[y + 1] != NULL)
	{
		x = 0;
		while (parsing->map[y][x])
		{
			st_check_walls_middle(parsing, y, x);
			x++;
		}
		y++;
	}
	st_check_walls_top_bottom(parsing, y);
}
