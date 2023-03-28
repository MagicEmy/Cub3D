/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:17:52 by emlicame          #+#    #+#             */
/*   Updated: 2023/03/28 16:06:49 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	parsing_free(t_parsing *parsing)
{
	free (parsing->floor);
	free (parsing->ceiling);
	free (parsing->no_path);
	free (parsing->so_path);
	free (parsing->ea_path);
	free (parsing->we_path);
}

void	parsing_to_data(t_data *data, t_parsing *parsing)
{
	data->map_width = parsing->map_width;
	data->map_height = parsing->map_height;
	data->map = parsing->map;
	data->ceiling_clr = parsing->ceiling_clr;
	data->floor_clr = parsing->floor_clr;
	data->goat->x = parsing->player_x;
	data->goat->y = parsing->player_y;
	data->goat->angle = parsing->player_angle;
}

void	parsing_stru_init(t_parsing *parsing)
{
	parsing->map = NULL;
	parsing->map_width = 0;
	parsing->map_height = 0;
	parsing->info_file = NULL;
	parsing->floor = NULL;
	parsing->ceiling = NULL;
	parsing->red = 0;
	parsing->green = 0;
	parsing->blue = 0;
	parsing->ceiling_clr = 0;
	parsing->floor_clr = 0;
	parsing->no_path = NULL;
	parsing->so_path = NULL;
	parsing->ea_path = NULL;
	parsing->we_path = NULL;
	parsing->map_start = 0;
	parsing->map_end = 0;
	parsing->set = " \t\v\f\r\n";
	parsing->counter = 0;
	parsing->player_x = 0;
	parsing->player_y = 0;
	parsing->player_angle = 0;
}
