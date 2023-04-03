/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_syntax.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:01:24 by emlicame          #+#    #+#             */
/*   Updated: 2023/04/03 17:41:47 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_map_syntax(t_parsing *parsing)
{
	int32_t	x;
	int32_t	y;
	int32_t	orientation;

	x = 0;
	y = 0;
	orientation = 0;
	while (parsing->map[y])
	{
		while (parsing->map[y][x])
		{
			if (!ft_strchr(" 01NSEW", parsing->map[y][x]))
				error_exit(ERROR_INVALID_CHAR);
			if (ft_strchr("NSEW", parsing->map[y][x]))
				orientation++;
			x++;
		}
		x = 0;
		y++;
	}
	if (orientation != 1)
		error_exit(ERROR_PLAYER_COUNT);
}
