/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:57:53 by emlicame          #+#    #+#             */
/*   Updated: 2023/03/13 15:43:41 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	texture_acquisition(t_data *data)
{
	data->texture.north = mlx_load_png(data->no_path);
	if (data->texture.north == NULL)
		error_exit(ERROR_PATH_TEXTURE);
	data->texture.south = mlx_load_png(data->so_path);
	if (data->texture.south == NULL)
		error_exit(ERROR_PATH_TEXTURE);
	data->texture.east = mlx_load_png(data->ea_path);
	if (data->texture.east == NULL)
		error_exit(ERROR_PATH_TEXTURE);
	data->texture.west = mlx_load_png(data->we_path);
	if (data->texture.west == NULL)
		error_exit(ERROR_PATH_TEXTURE);
}

static void	rgb_range_check(t_data *data)
{
	if (data->floor_red < 0 || data->floor_green < 0 || data->floor_blue < 0)
		error_exit(ERROR_RGB_ERR);
	if (data->floor_red > 255 || data->floor_green > 255 || \
	data->floor_blue > 255)
		error_exit(ERROR_RGB_ERR);
	if (data->ceiling_red < 0 || data->ceiling_green < 0 || \
	data->ceiling_blue < 0)
		error_exit(ERROR_RGB_ERR);
	if (data->ceiling_red > 255 || data->ceiling_green > 255 || \
	data->ceiling_blue > 255)
		error_exit(ERROR_RGB_ERR);
}

void	rgb_validation(t_data *data)
{
	char	**rgb;

	rgb = ft_split(data->floor, ',');
	if (!rgb)
		error_exit(ERROR_MALLOC);
	if (!rgb[0] || !rgb[1] || !rgb[2])
		error_exit(ERROR_RGB_ERR);
	data->floor_red = ft_atoi(rgb[0]);
	data->floor_green = ft_atoi(rgb[1]);
	data->floor_blue = ft_atoi(rgb[2]);
	ft_free_double_arr(rgb);
	rgb = ft_split(data->ceiling, ',');
	if (!rgb)
		error_exit(ERROR_MALLOC);
	if (!rgb[0] || !rgb[1] || !rgb[2])
		error_exit(ERROR_RGB_ERR);
	data->ceiling_red = ft_atoi(rgb[0]);
	data->ceiling_green = ft_atoi(rgb[1]);
	data->ceiling_blue = ft_atoi(rgb[2]);
	ft_free_double_arr(rgb);
	rgb_range_check(data);
}

void	check_map_syntax(t_data *data)
{
	int	x;
	int	y;
	int	orientation;

	x = 0;
	y = 0;
	orientation = 0;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (!ft_strchr(" 01NSEW", data->map[y][x]))
				error_exit(ERROR_INVALID_CHAR);
			if (ft_strchr("NSEW", data->map[y][x]))
				orientation++;
			x++;
		}
		x = 0;
		y++;
	}
	if (orientation > 1)
		error_exit(ERROR_PLAYER_COUNT);
}

void	cube_check_extension(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (ft_strncmp(&argv[len - 4], ".cub", 4) != 0)
		error_exit(ERROR_MAP_EXTENSION);
}
