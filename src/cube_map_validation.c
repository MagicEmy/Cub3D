/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_map_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:40:34 by emlicame          #+#    #+#             */
/*   Updated: 2023/02/27 16:09:39 by emlicame         ###   ########.fr       */
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
	char	*file_line;
	int		i;

	i = 0;
	cube_check_extension(argv);
	file_line = get_line(argv);
	if (!file_line)
		error_exit(ERROR_EMPTY_FILE);
	data->file_info.map = ft_split(file_line, ' ');
	free(file_line);
	if (!data->file_info.map)
		error_exit(ERROR_MALLOC);
	while (data->file_info.map[i])
		printf ("line: |%s|\n", data->file_info.map[i++]);
}


/*
- make a split function that get more than 1 char to check all spaces forms
- read lines and check if all the necessary info have been provided and stored 
	in the designated struct, if not error
- get the line, split the content and store in struct;
- parse the map
- split by every kind of space and store in struct
- map is the last object to be written in the file, if not error
*/