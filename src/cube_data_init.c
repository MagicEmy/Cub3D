/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_data_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:42:39 by emlicame          #+#    #+#             */
/*   Updated: 2023/03/07 16:53:51 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_data	*cube_data_init(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		error_exit(ERROR_MALLOC);
	data->map = NULL;
	data->info_file = NULL;
	data->no_path = NULL;
	data->so_path = NULL;
	data->ea_path = NULL;
	data->we_path = NULL;
	data->ceiling = NULL;
	data->floor = NULL;
	data->counter = 0;
	return (data);
}
