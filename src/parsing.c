/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 16:40:34 by emlicame      #+#    #+#                 */
/*   Updated: 2023/03/08 18:15:32 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	info_sorting(char **path, t_data *data)
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

char	*get_line(char *argv, t_data *data)
{
	int		fd;
	char	*line;
	char	*map_line;

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
			map_line = gnl_ft_strjoin_free(map_line, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (map_line);
}

static void	cube_check_extension(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (ft_strncmp(&argv[len - 4], ".cub", 4) != 0)
		error_exit(ERROR_MAP_EXTENSION);
}

void	info_map_parsing(char *argv, t_data *data)
{
	int		i;
	char	*map_line;

	i = 0;
	cube_check_extension(argv);
	map_line = get_line(argv, data);
	if (ft_strncmp(map_line, "", 1) == 0)
		error_exit(ERROR_EMPTY_MAP);
	data->map = ft_split(map_line, '\n');
	free(map_line);
	if (!data->map)
		error_exit(ERROR_MALLOC);
	texture_acquisition(data);
	rgb_validation(data);
	// check_map_syntax(data);
	// map_validation(data);
	while (data->map[i])
		printf("%s\n", data->map[i++]);
}

/*
x parse the map
	x get the line, split (regular) the content and store in struct;
	- map is the last object to be written in the file, if not error
	-check if path is valid and if there is garbage before it
*/