/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_file_safety_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:30:11 by emlicame          #+#    #+#             */
/*   Updated: 2023/03/29 16:30:13 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int32_t	info_file_safety_check(t_parsing *parsing, char *line)
{
	int32_t	i;

	i = 0;
	parsing->info_file = ft_split_multi(line, parsing->set);
	if (!parsing->info_file)
		error_exit(ERROR_MALLOC);
	if (!parsing->info_file[0])
	{
		ft_free_double_arr(parsing->info_file);
		return (0);
	}
	while (parsing->info_file[i])
		i++;
	if (i != 2)
		error_exit(ERROR_INVALID_INFO);
	return (1);
}
