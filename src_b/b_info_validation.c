/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_info_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:57:53 by emlicame          #+#    #+#             */
/*   Updated: 2023/03/22 16:31:39 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// static mlx_image_t	*text_to_image(mlx_t *mlx, char *png)
// {
// 	mlx_texture_t	*texture;
// 	mlx_image_t		*img;

// 	texture = mlx_load_png(png);
// 	if (texture == NULL)
// 		error_exit("Fail to read png file.");
// 	img = mlx_texture_to_image(mlx, texture);
// 	mlx_delete_texture(texture);
// 	if (img == NULL)
// 		error_exit("Fail to render image.");
// 	return (img);
// }

// void	get_images(t_data *data)
// {
// 	data->sprites.fire_1 = text_to_image(data->mlx, "textures/fire/fire_1.png");
// 	data->sprites.fire_2 = text_to_image(data->mlx, "images/asteroid.png");
// 	data->sprites.fire_3 = text_to_image(data->mlx, "images/asteroid.png");
// 	data->sprites.fire_4 = text_to_image(data->mlx, "images/asteroid.png");
// 	data->sprites.fire_5 = text_to_image(data->mlx, "images/asteroid.png");
// 	data->sprites.fire_6 = text_to_image(data->mlx, "images/asteroid.png");
// 	data->sprites.door_1 = text_to_image(data->mlx, "images/pc.png");
// }

void	texture_acquisition(t_parsing *parsing, t_data *data)
{
	ft_memset(data->textures, 0, sizeof(mlx_texture_t) * 4);
	data->textures[NORTH] = mlx_load_png(parsing->no_path);
	if (data->textures[NORTH] == NULL)
		error_exit(ERROR_PATH_TEXTURE);
	data->textures[SOUTH] = mlx_load_png(parsing->so_path);
	if (data->textures[SOUTH] == NULL)
		error_exit(ERROR_PATH_TEXTURE);
	data->textures[EAST] = mlx_load_png(parsing->ea_path);
	if (data->textures[EAST] == NULL)
		error_exit(ERROR_PATH_TEXTURE);
	data->textures[WEST] = mlx_load_png(parsing->we_path);
	if (data->textures[WEST] == NULL)
		error_exit(ERROR_PATH_TEXTURE);
}

static void	rgb_range_check(t_parsing *parsing)
{
	parsing->ceiling_clr = 0;
	parsing->floor_clr = 0;
	if (parsing->floor_red < 0 || parsing->floor_green < 0 || \
	parsing->floor_blue < 0)
		error_exit(ERROR_RGB_ERR);
	if (parsing->floor_red > 255 || parsing->floor_green > 255 || \
	parsing->floor_blue > 255)
		error_exit(ERROR_RGB_ERR);
	if (parsing->ceiling_red < 0 || parsing->ceiling_green < 0 || \
	parsing->ceiling_blue < 0)
		error_exit(ERROR_RGB_ERR);
	if (parsing->ceiling_red > 255 || parsing->ceiling_green > 255 || \
	parsing->ceiling_blue > 255)
		error_exit(ERROR_RGB_ERR);
	parsing->floor_clr = get_rgba(parsing->floor_red, parsing->floor_green, \
	parsing->floor_blue, 255);
	parsing->ceiling_clr = get_rgba(parsing->ceiling_red, \
	parsing->ceiling_green, parsing->ceiling_blue, 255);
}

void	rgb_validation(t_parsing *parsing)
{
	char	**rgb;

	rgb = NULL;
	rgb = ft_split(parsing->floor, ',');
	if (!rgb)
		error_exit(ERROR_MALLOC);
	if (!rgb[0] || !rgb[1] || !rgb[2])
		error_exit(ERROR_RGB_ERR);
	parsing->floor_red = ft_atoi(rgb[0]);
	parsing->floor_green = ft_atoi(rgb[1]);
	parsing->floor_blue = ft_atoi(rgb[2]);
	ft_free_double_arr(rgb);
	rgb = NULL;
	rgb = ft_split(parsing->ceiling, ',');
	if (!rgb)
		error_exit(ERROR_MALLOC);
	if (!rgb[0] || !rgb[1] || !rgb[2])
		error_exit(ERROR_RGB_ERR);
	parsing->ceiling_red = ft_atoi(rgb[0]);
	parsing->ceiling_green = ft_atoi(rgb[1]);
	parsing->ceiling_blue = ft_atoi(rgb[2]);
	ft_free_double_arr(rgb);
	rgb_range_check(parsing);
}
