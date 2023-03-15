/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:28:00 by emlicame          #+#    #+#             */
/*   Updated: 2023/03/15 19:15:02 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdlib.h>

static int	ft_is_map_space(char c)
{
	if (c == ' ' || c == '\n')
		return (1);
	return (0);
}

static void	check_walls_top_bottom(t_data *data, int y)
{
	int	x;

	x = 0;
	while (data->map[y][x])
	{
		if (data->map[y][x] != ' ' && data->map[y][x] != '1')
		{
			printf ("%c\n", data->map[y][x]);
			printf ("x %d y %d\n", x, y);
			error_exit(ERROR_INVALID_MAP_W);
		}
		// if (data->map[y][x] == ' ')
		// 	data->map[y][x] = '@';
		x++;
	}
}

static int	ft_is_map_space(char c)
{
	if (c == ' ' || c == '\n')
		return (1);
	return (0);
}

static void	check_walls_middle(t_data *data, int y, int x)
{
	if (ft_strchr("0NSEW", data->map[y][x]))
	{
		if (ft_strchr("NSEW", data->map[y][x]))
		{
			data->goat->x = x + 0.5;
			data->goat->y = y + 0.5;
			if (data->map[y][x] == 'E')
				data->goat->angle = E;
			if (data->map[y][x] == 'N')
				data->goat->angle = N;
			if (data->map[y][x] == 'W')
				data->goat->angle = W;
			if (data->map[y][x] == 'S')
				data->goat->angle = S;
		}
		if (ft_is_map_space(data->map[y][x + 1]))
			error_exit(ERROR_INVALID_MAP_W);
		if (ft_is_map_space(data->map[y][x - 1]))
			error_exit(ERROR_INVALID_MAP_W);
		if (ft_is_map_space(data->map[y - 1][x]))
			error_exit(ERROR_INVALID_MAP_W);
		if (ft_is_map_space(data->map[y + 1][x]))
			error_exit(ERROR_INVALID_MAP_W);
	}
}

void	map_validation(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	check_walls_top_bottom(data, y);
	y = 1;
	while (data->map[y + 1] != NULL)
	{
		x = 0;
		while (data->map[y][x])
		{
			check_walls_middle(data, y, x);
			// if (data->map[y][x] == ' ')
			// 	data->map[y][x] = '@';
			x++;
		}
		y++;
	}
	check_walls_top_bottom(data, y);
}
