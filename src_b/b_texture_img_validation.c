/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_texture_img_validation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:57:53 by emlicame          #+#    #+#             */
/*   Updated: 2023/03/23 17:43:34 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static mlx_image_t	*text_to_img(mlx_t *mlx, char *png)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(png);
	if (texture == NULL)
		error_exit("Fail to read png file.");
	img = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	if (img == NULL)
		error_exit("Fail to render image.");
	return (img);
}

void	get_images(t_data *data)
{
	data->sprites.fire[0] = text_to_img(data->mlx, "textures/fire/fire_0.png");
	data->sprites.fire[1] = text_to_img(data->mlx, "textures/fire/fire_1.png");
	data->sprites.fire[2] = text_to_img(data->mlx, "textures/fire/fire_2.png");
	data->sprites.fire[3] = text_to_img(data->mlx, "textures/fire/fire_3.png");
	data->sprites.fire[4] = text_to_img(data->mlx, "textures/fire/fire_4.png");
	data->sprites.fire[5] = text_to_img(data->mlx, "textures/fire/fire_5.png");
}

// data->sprites.fire_0 = text_to_image(data->mlx, "textures/fire/fire_0.png");

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
