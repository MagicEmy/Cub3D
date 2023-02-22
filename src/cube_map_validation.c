/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_map_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:40:34 by emlicame          #+#    #+#             */
/*   Updated: 2023/02/22 16:51:00 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	cube_check_extension(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (ft_strncmp(&argv[len - 4], ".cub", 4) != 0)
		error_exit(ERROR_MAP_EXTENSION);
}

void	cube_map_validation(char *argv, t_data *data)
{
	(void)data;
	cube_check_extension(argv);
}
