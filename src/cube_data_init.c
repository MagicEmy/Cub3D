/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_data_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:42:39 by emlicame          #+#    #+#             */
/*   Updated: 2023/02/22 16:42:40 by emlicame         ###   ########.fr       */
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
	return (data);
}
