/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_equalizer_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:10:34 by emlicame          #+#    #+#             */
/*   Updated: 2023/03/29 16:36:34 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static int32_t	st_allignment_left_calc(t_parsing *parsing)
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

static void	st_get_map_size(t_parsing *parsing)
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

static void	st_copy_and_fill_map(t_parsing *parsing, char **new_map, int32_t i, \
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
	st_get_map_size(parsing);
	start = st_allignment_left_calc(parsing);
	new_map = (char **)malloc(sizeof(char *) * (parsing->map_height + 1));
	if (!new_map)
		error_exit(ERROR_MALLOC);
	while (parsing->map[i])
	{
		new_map[i] = (char *)malloc(sizeof(char) * \
		(parsing->map_width + 1 - start));
		if (!new_map[i])
			error_exit(ERROR_MALLOC);
		new_map[i][parsing->map_width - start] = '\0';
		st_copy_and_fill_map(parsing, new_map, i, start);
		i++;
	}
	new_map[i] = NULL;
	ft_free_double_arr(parsing->map);
	parsing->map = new_map;
	st_get_map_size(parsing);
}
