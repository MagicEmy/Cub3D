/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:40:34 by emlicame          #+#    #+#             */
/*   Updated: 2023/03/15 11:20:04 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <fcntl.h>

static void	info_sorting(char **path, t_data *data)
{
	int		i;

	i = 0;
	if (*path != NULL)
		error_exit("double");
	*path = ft_strdup(data->info_file[i + 1]);
	if (!path)
		error_exit(ERROR_MALLOC);
	data->counter++;
}

void	get_file_info(char *line, t_data *data)
{
	char	*set;

	set = " \t\v\f\r\n";
	data->info_file = ft_split_multi(line, set);
	if (!data->info_file)
		error_exit(ERROR_MALLOC);
	if (!data->info_file[0])
		return ;
	if (data->info_file[2])
		error_exit("garbage");
	if (ft_strncmp(data->info_file[0], "NO", 3) == 0)
		info_sorting(&data->no_path, data);
	else if (ft_strncmp(data->info_file[0], "SO", 3) == 0)
		info_sorting(&data->so_path, data);
	else if (ft_strncmp(data->info_file[0], "EA", 3) == 0)
		info_sorting(&data->ea_path, data);
	else if (ft_strncmp(data->info_file[0], "WE", 3) == 0)
		info_sorting(&data->we_path, data);
	else if (ft_strncmp(data->info_file[0], "F", 2) == 0)
		info_sorting(&data->floor, data);
	else if (ft_strncmp(data->info_file[0], "C", 2) == 0)
		info_sorting(&data->ceiling, data);
	else
		error_exit("garbage");
	ft_free_double_arr(data->info_file);
}

static void	check_if_valid_format(char	**line, char **map_line, \
t_data *data)
{
	if (!ft_str_is_space(*line) && data->map_end)
		error_exit(ERROR_INVALID_MAP);
	else if (!ft_str_is_space(*line))
	{
		*map_line = gnl_ft_strjoin_free(*map_line, *line);
		data->map_start = 1;
	}
	else if (ft_str_is_space(*line) && data->map_start)
		data->map_end = 1;
}

char	*get_line(char *argv, t_data *data)
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
		if (data->counter < 6)
			get_file_info(line, data);
		else
			check_if_valid_format(&line, &map_line, data);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (map_line);
}

void	info_map_parsing(char *argv, t_data *data)
{
	char	*map_line;
	int		len;

	len = ft_strlen(argv);
	if (ft_strncmp(&argv[len - 4], ".cub", 4) != 0)
		error_exit(ERROR_MAP_EXTENSION);
	map_line = get_line(argv, data);
	if (ft_strncmp(map_line, "", 1) == 0)
		error_exit(ERROR_EMPTY_MAP);
	data->map = ft_split(map_line, '\n');
	free(map_line);
	if (!data->map)
		error_exit(ERROR_MALLOC);
	check_map_syntax(data);
	texture_acquisition(data);
	rgb_validation(data);
	map_validation(data);
	get_map_size(data);
	map_equalizer(data);
}

	// cube_check_extension(argv);
	// int		i;

	// i = 0;
	// while (data->map[i])
	// 	printf("%s\n", data->map[i++]);