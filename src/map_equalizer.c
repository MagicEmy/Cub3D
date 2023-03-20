/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_equalizer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:10:34 by emlicame          #+#    #+#             */
/*   Updated: 2023/03/19 17:39:51 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	get_map_size(t_parsing *parsing)
{
	int		y;
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

static void	copy_and_fill_map(t_parsing *parsing, char **new_map, int i)
{
	int	x;

	x = 0;
	while (parsing->map[i][x])
	{
		new_map[i][x] = parsing->map[i][x];
		x++;
	}
	while (new_map[i][x])
		new_map[i][x++] = ' ';
}

void	map_equalizer(t_parsing *parsing)
{
	char	**new_map;
	int		i;
	int		x;

	i = 0;
	get_map_size(parsing);
	new_map = (char **)malloc(sizeof(char *) * (parsing->map_height + 1));
	if (!new_map)
		error_exit(ERROR_MALLOC);
	while (parsing->map[i])
	{
		x = 0;
		new_map[i] = (char *)malloc(sizeof(char) * (parsing->map_width + 1));
		if (!new_map[i])
			error_exit(ERROR_MALLOC);
		new_map[i][parsing->map_width] = '\0';
		copy_and_fill_map(parsing, new_map, i);
		i++;
	}
	new_map[i] = NULL;
	ft_free_double_arr(parsing->map);
	parsing->map = new_map;
}
