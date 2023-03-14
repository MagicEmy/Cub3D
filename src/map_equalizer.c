/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_equalizer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:10:34 by emlicame          #+#    #+#             */
/*   Updated: 2023/03/14 18:20:25 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdlib.h>

void	get_map_size(t_data *data)
{
	int		y;
	size_t	max;
	size_t	len;

	y = 0;
	max = 0;
	len = 0;
	while (data->map[y])
	{
		len = ft_strlen(data->map[y]);
		if (max < len)
			max = len;
		y++;
	}
	data->map_width = max;
	data->map_height = y;
}

static void	copy_and_fill_map(t_data *data, char **new_map, int i)
{
	int	x;

	x = 0;
	while (data->map[i][x])
	{
		new_map[i][x] = data->map[i][x];
		x++;
	}
	while (new_map[i][x])
		new_map[i][x++] = '1';
}

void	map_equalizer(t_data *data)
{
	char	**new_map;
	int		i;
	int		x;

	i = 0;
	new_map = (char **)malloc(sizeof(char *) * (data->map_height + 1));
	if (!new_map)
		error_exit(ERROR_MALLOC);
	while (data->map[i])
	{
		x = 0;
		new_map[i] = (char *)malloc(sizeof(char) * (data->map_width + 1));
		if (!new_map[i])
			error_exit(ERROR_MALLOC);
		new_map[i][data->map_width] = '\0';
		copy_and_fill_map(data, new_map, i);
		i++;
	}
	new_map[i] = NULL;
	ft_free_double_arr(data->map);
	data->map = new_map;
}
