/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_equalizer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:10:34 by emlicame          #+#    #+#             */
/*   Updated: 2023/03/21 13:41:33 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int32_t	allignment_left(t_parsing *parsing)
{
	int32_t	y;
	int32_t	x;
	int32_t	max;

	y = 0;
	x = 0;
	while (parsing->map[y][x] == ' ')
		x++;
	max = x;
	while (parsing->map[y])
	{
		x = 0;
		while (parsing->map[y][x] == ' ')
			x++;
		if (max > x)
			max = x;
		y++;
	}
	return (max);
}

static void	get_map_size(t_parsing *parsing)
{
	int32_t	y;
	size_t	max;
	size_t	len;

	y = 0;
	max = 0;
	len = 0;
	while (parsing->map[y])
	{
		len = ft_strlen(parsing->map[y]);
		if (max < len)
			max = len;
		y++;
	}
	parsing->map_width = max;
	parsing->map_height = y;
}

static void	copy_and_fill_map(t_parsing *parsing, char **new_map, int32_t i, \
int32_t start)
{
	int32_t	x;
	int32_t	z;

	x = 0;
	z = start;
	while (parsing->map[i][z])
	{
		new_map[i][x] = parsing->map[i][z];
		x++;
		z++;
	}
	while (new_map[i][x])
		new_map[i][x++] = ' ';
}

void	map_equalizer(t_parsing *parsing)
{
	char	**new_map;
	int32_t	start;
	int32_t	i;

	i = 0;
	get_map_size(parsing);
	start = allignment_left(parsing);
	new_map = (char **)malloc(sizeof(char *) * (parsing->map_height + 1));
	if (!new_map)
		error_exit(ERROR_MALLOC);
	while (parsing->map[i])
	{
		new_map[i] = (char *)malloc(sizeof(char) * (parsing->map_width + 1));
		if (!new_map[i])
			error_exit(ERROR_MALLOC);
		new_map[i][parsing->map_width] = '\0';
		copy_and_fill_map(parsing, new_map, i, start);
		i++;
	}
	new_map[i] = NULL;
	ft_free_double_arr(parsing->map);
	parsing->map = new_map;
}
