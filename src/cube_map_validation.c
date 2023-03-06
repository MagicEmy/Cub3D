/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_map_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:40:34 by emlicame          #+#    #+#             */
/*   Updated: 2023/03/06 19:10:28 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_file_info(char *line, t_data *data)
{
	char	*set;
	int		i;

	i = 0;
	set = " \t\v\f\r\n";
	data->info_file = ft_split_multi(line, set);
	if (!data->info_file)
		error_exit(ERROR_MALLOC);
	if (!data->info_file[i])
		return (0);
	if (data->info_file[2])
		error_exit("garbage");
	if (ft_strncmp(data->info_file[i], "NO", 3) == 0)
	{
		if (data->no_path != NULL)
			error_exit("double");
		data->no_path = ft_strdup(data->info_file[i + 1]);
		if (!data->no_path)
			error_exit(ERROR_MALLOC);
		data->counter++;
	}
	else if (ft_strncmp(data->info_file[i], "SO", 3) == 0)
	{
		if (data->so_path != NULL)
			error_exit("double");
		data->so_path = ft_strdup(data->info_file[i + 1]);
		if (!data->so_path)
			error_exit(ERROR_MALLOC);
		data->counter++;
	}
	else if (ft_strncmp(data->info_file[i], "SO", 3) == 0)
	{
		if (data->so_path != NULL)
			error_exit("double");
		data->so_path = ft_strdup(data->info_file[i + 1]);
		if (!data->so_path)
			error_exit(ERROR_MALLOC);
		data->counter++;
	}
	else if (ft_strncmp(data->info_file[i], "EA", 3) == 0)
	{
		if (data->ea_path != NULL)
			error_exit("double");
		data->ea_path = ft_strdup(data->info_file[i + 1]);
		if (!data->ea_path)
			error_exit(ERROR_MALLOC);
		data->counter++;
	}
	else if (ft_strncmp(data->info_file[i], "WE", 3) == 0)
	{
		if (data->we_path != NULL)
			error_exit("double");
		data->we_path = ft_strdup(data->info_file[i + 1]);
		if (!data->we_path)
			error_exit(ERROR_MALLOC);
		data->counter++;
	}
	else if (ft_strncmp(data->info_file[i], "F", 2) == 0)
	{
		if (data->floor != NULL)
			error_exit("double");
		data->floor = ft_strdup(data->info_file[i + 1]);
		if (!data->floor)
			error_exit(ERROR_MALLOC);
		data->counter++;
	}
	else if (ft_strncmp(data->info_file[i], "C", 2) == 0)
	{
		if (data->ceiling != NULL)
			error_exit("double");
		data->ceiling = ft_strdup(data->info_file[i + 1]);
		if (!data->ceiling)
			error_exit(ERROR_MALLOC);
		data->counter++;
	}
	else
		error_exit("garbage");
	printf("data NO \t%s\n", data->no_path);
	printf("data SO \t%s\n", data->so_path);
	printf("data WE \t%s\n", data->we_path);
	printf("data EA \t%s\n", data->ea_path);
	printf("data F \t\t%s\n", data->floor);
	printf("data C \t\t%s\n", data->ceiling);
	printf("counter \t\t%d\n", data->counter);
	ft_free_double_arr(data->info_file);
	return (0);
}

char	*get_line(char *argv, t_data *data)
{
	char	*line;
	char	*map_line;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error_exit("File opening failed.");
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
		if (data->counter == 6)
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

void	cube_map_validation(char *argv, t_data *data)
{
	int		i;
	char	*map_line;
	
	i = 0;
	cube_check_extension(argv);
	data->info_file = NULL;
	data->no_path = NULL;
	data->so_path = NULL;
	data->ea_path = NULL;
	data->we_path = NULL;
	data->ceiling = NULL;
	data->floor = NULL;
	data->counter = 0;
	map_line = get_line(argv, data);
	if (ft_strncmp(map_line, "", 1) == 0)
		error_exit(ERROR_EMPTY_MAP);
	data->map = ft_split(map_line, '\n');
	free(map_line);
	if (!data->map)
		error_exit(ERROR_MALLOC);
	while (data->map[i])
		printf("%s\n", data->map[i++]);
	while (1)
		;
}

/*
x make a split function that get more than 1 char to check all kind of spaces
	- split by every kind of space and store in struct
- read lines and check if all the necessary info have been provided and stored 
	in the designated struct, if not error
- parse the map
	- get the line, split (regular) the content and store in struct;
	- map is the last object to be written in the file, if not error
-check if path is valid and if there is garbage before it
*/