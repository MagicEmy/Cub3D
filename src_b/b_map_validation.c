/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_map_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:28:00 by emlicame          #+#    #+#             */
/*   Updated: 2023/03/22 15:11:34 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_map_syntax(t_parsing *parsing)
{
	int	x;
	int	y;
	int	orientation;

	x = 0;
	y = 0;
	orientation = 0;
	while (parsing->map[y])
	{
		while (parsing->map[y][x])
		{
			if (!ft_strchr(" 01NSEWD$", parsing->map[y][x]))
				error_exit(ERROR_INVALID_CHAR);
			if (ft_strchr("NSEW", parsing->map[y][x]))
				orientation++;
			x++;
		}
		x = 0;
		y++;
	}
	if (orientation > 1)
		error_exit(ERROR_PLAYER_COUNT);
}

static void	check_walls_top_bottom(t_parsing *parsing, int y)
{
	int	x;

	x = 0;
	while (parsing->map[y][x])
	{
		if (parsing->map[y][x] != ' ' && parsing->map[y][x] != '1')
			error_exit(ERROR_INVALID_MAP_W);
		x++;
	}
}

static int	ft_is_map_space(char c)
{
	if (c == ' ' || c == '\n')
		return (1);
	return (0);
}

static void	check_walls_middle(t_parsing *parsing, int y, int x)
{
	if (ft_strchr("0NSEW", parsing->map[y][x]))
	{
		if (ft_strchr("NSEW", parsing->map[y][x]))
		{
			parsing->player_x = x + 0.5;
			parsing->player_y = y + 0.5;
			if (parsing->map[y][x] == 'E')
				parsing->player_angle = E;
			if (parsing->map[y][x] == 'N')
				parsing->player_angle = N;
			if (parsing->map[y][x] == 'W')
				parsing->player_angle = W;
			if (parsing->map[y][x] == 'S')
				parsing->player_angle = S;
		}
		if (ft_is_map_space(parsing->map[y][x + 1]))
			error_exit(ERROR_INVALID_MAP_W);
		if (ft_is_map_space(parsing->map[y][x - 1]))
			error_exit(ERROR_INVALID_MAP_W);
		if (ft_is_map_space(parsing->map[y - 1][x]))
			error_exit(ERROR_INVALID_MAP_W);
		if (ft_is_map_space(parsing->map[y + 1][x]))
			error_exit(ERROR_INVALID_MAP_W);
	}
}

void	map_validation(t_parsing *parsing)
{
	int	x;
	int	y;

	y = 0;
	check_walls_top_bottom(parsing, y);
	y = 1;
	while (parsing->map[y + 1] != NULL)
	{
		x = 0;
		while (parsing->map[y][x])
		{
			check_walls_middle(parsing, y, x);
			x++;
		}
		y++;
	}
	check_walls_top_bottom(parsing, y);
}