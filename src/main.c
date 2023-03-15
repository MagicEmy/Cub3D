/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:23:48 by emlicame          #+#    #+#             */
/*   Updated: 2023/03/15 11:29:15 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "cub3D_structures.h"
#include <stdlib.h>
#include <math.h>

void	error_exit(char *text)
{
	ft_putstr_fd(C_RED"\nE"C_YELLOW"RR"C_VIOLET"OR\t"C_BLUE, 2);
	ft_putendl_fd(text, 2);
	ft_putendl_fd(C_RESET, 2);
	exit(EXIT_FAILURE);
}

void	key_hooks(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.action != MLX_PRESS && keydata.action != MLX_REPEAT)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		return (mlx_close_window(data->mlx));
	if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_A)
		go_left_right(keydata.key, data);
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S)
		go_fwd_bck(keydata.key, data);
	if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_LEFT)
		look_left_right(keydata.key, data);
	if (keydata.key == MLX_KEY_G)
		print_goat_info(data);
}

void	init(t_data *data, t_goat *goat)
{
	goat->x = 16.5;
	goat->y = 2.5;
	goat->angle = 90;
	data->map = NULL;
	data->map_width = 23;
	data->map_height = 11;
	data->floor_clr = 0x74A15Aff;
	data->sky_clr = 0xCAEAFFff;
	data->goat = goat;
	data->nsew_clr[NORTH] = 0xC474EFFF;
	data->nsew_clr[SOUTH] = 0xEF74DDFF;
	data->nsew_clr[EAST] = 0xEF749FFF;
	data->nsew_clr[WEST] = 0xEF8774FF;
	mlx_get_mouse_pos(data->mlx, &data->cursor_x, &data->cursor_y);
	data->info_file = NULL;
	data->no_path = NULL;
	data->so_path = NULL;
	data->ea_path = NULL;
	data->we_path = NULL;
	data->ceiling = NULL;
	data->floor = NULL;
	data->map_start = 0;
	data->map_end = 0;
	data->counter = 0;
}

/* this is a work in progress function that I used for understanding textures */
// void	show_textures(t_data *data)
// {
// 	size_t			i;
// 	unsigned int	colour;

// 	i = 0;
// 	// printf("NO w %d h %d\n", data->texture.north->width, data->texture.north->height);
// 	// printf("SO w %d h %d\n", data->texture.south->width, data->texture.south->height);
// 	// printf("WE w %d h %d\n", data->texture.west->width, data->texture.west->height);
// 	// printf("EA w %d h %d\n", data->texture.east->width, data->texture.east->height);
// 	while (i < data->texture.south->width * data->texture.south->height * \
// 	data->texture.south->bytes_per_pixel)
// 	{
// 		colour = get_rgba(data->texture.south->pixels[i], \
// 		data->texture.south->pixels[i + 1], data->texture.south->pixels[i + 2], \
// 		data->texture.south->pixels[i + 3]);
// 		printf("%u, ", colour);
// 		i += data->texture.south->bytes_per_pixel;
// 		if ((i / data->texture.south->bytes_per_pixel) % data->texture.south->width == 0)
// 			printf("\n");
// 	}
// }

int32_t	main(int argc, char **argv)
{
	t_goat		goat;
	t_data		data;

	if (!argv || argc != 2)
		error_exit(ERROR_ARGS);
	data.mlx = mlx_init(WIDTH, HEIGHT, "GOAT3D", true);
	if (!data.mlx)
		return (EXIT_FAILURE);
	init(&data, &goat);
	info_map_parsing(argv[1], &data);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img_mm = mlx_new_image(data.mlx, WIDTH / 2, HEIGHT / 4);
	draw_minimap(&data);
	casting_rays(&data);
	// show_textures(&data);
	mlx_image_to_window(data.mlx, data.img, 0, 0);
	mlx_image_to_window(data.mlx, data.img_mm, PADDING, data.mlx->height - \
	data.img_mm->height - PADDING);
	mlx_key_hook(data.mlx, key_hooks, &data);
	mlx_cursor_hook(data.mlx, mouse_hook, &data);	// move to bonus
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	// free what needs to be freed
	return (EXIT_SUCCESS);
}
	// free what needs to be freed
