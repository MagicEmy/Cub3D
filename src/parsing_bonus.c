/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:40:34 by emlicame          #+#    #+#             */
/*   Updated: 2023/03/29 15:51:30 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"
#include <fcntl.h>

static void	st_info_sorting(char **path, t_parsing *parsing)
{
	if (*path != NULL)
		error_exit(ERROR_DOUBLE_ENTRY);
	*path = ft_strdup(parsing->info_file[1]);
	if (!path)
		error_exit(ERROR_MALLOC);
	parsing->counter++;
}

static void	get_file_info(char *line, t_parsing *parsing)
{
	if (!info_file_safety_check(parsing, line))
		return ;
	if (ft_strncmp(parsing->info_file[0], "NO", 3) == 0)
		st_info_sorting(&parsing->no_path, parsing);
	else if (ft_strncmp(parsing->info_file[0], "SO", 3) == 0)
		st_info_sorting(&parsing->so_path, parsing);
	else if (ft_strncmp(parsing->info_file[0], "EA", 3) == 0)
		st_info_sorting(&parsing->ea_path, parsing);
	else if (ft_strncmp(parsing->info_file[0], "WE", 3) == 0)
		st_info_sorting(&parsing->we_path, parsing);
	else if (ft_strncmp(parsing->info_file[0], "F", 2) == 0)
		st_info_sorting(&parsing->floor, parsing);
	else if (ft_strncmp(parsing->info_file[0], "C", 2) == 0)
		st_info_sorting(&parsing->ceiling, parsing);
	else
		error_exit(ERROR_INVALID_INFO);
	ft_free_double_arr(parsing->info_file);
}

static void	check_if_valid_format(char	**line, char **map_line, \
t_parsing *parsing)
{
	if (!ft_str_is_space(*line) && parsing->map_end)
		error_exit(ERROR_INVALID_MAP);
	else if (!ft_str_is_space(*line))
	{
		*map_line = gnl_ft_strjoin_free(*map_line, *line);
		parsing->map_start = 1;
	}
	else if (ft_str_is_space(*line) && parsing->map_start)
		parsing->map_end = 1;
}

static char	*st_get_line(char *argv, t_parsing *parsing)
{
	int		fd;
	char	*map_line;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error_exit(ERROR_OPEN_FAIL);
	map_line = ft_strdup("");
	if (!map_line)
		error_exit(ERROR_MALLOC);
	line = get_next_line(fd);
	if (!line)
		error_exit(ERROR_EMPTY_FILE);
	while (line)
	{
		if (parsing->counter < 6)
			get_file_info(line, parsing);
		else
			check_if_valid_format(&line, &map_line, parsing);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (map_line);
}

void	parsing(char *argv, t_data *data)
{
	t_parsing	parsing;
	char		*map_line;
	int			len;

	len = ft_strlen(argv);
	if (ft_strncmp(&argv[len - 4], ".cub", 4) != 0)
		error_exit(ERROR_MAP_EXTENSION);
	parsing_stru_init(&parsing);
	map_line = st_get_line(argv, &parsing);
	if (ft_strncmp(map_line, "", 1) == 0)
		error_exit(ERROR_INVALID_INFO);
	parsing.map = ft_split(map_line, '\n');
	free(map_line);
	if (!parsing.map)
		error_exit(ERROR_MALLOC);
	check_map_syntax(&parsing);
	texture_acquisition(&parsing, data);
	rgb_validation(&parsing);
	map_equalizer(&parsing);
	map_validation(&parsing);
	parsing_to_data(data, &parsing);
	parsing_free(&parsing);
}
