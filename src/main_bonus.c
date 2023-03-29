/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:13:21 by dmalacov          #+#    #+#             */
/*   Updated: 2023/03/29 15:40:35 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"
#include "colors.h"
#include <math.h>

void	error_exit(char *text)
{
	ft_putstr_fd(C_RED"\nE"C_YELLOW"RR"C_VIOLET"OR\t"C_BLUE, 2);
	ft_putendl_fd(text, 2);
	ft_putendl_fd(C_RESET, 2);
	exit(EXIT_FAILURE);
}

static void	st_init(t_data *data)
{
	data->goat = malloc(sizeof(t_goat));
	if (!data->goat)
		error_exit(ERROR_MALLOC);
	data->goat->dist_pp = WIDTH / 2 * tan(to_rad(FOV));
}

static void	st_img_init(t_data *data)
{
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img_mm = mlx_new_image(data->mlx, \
	get_min(WIDTH / 2, data->map_width * PPU + 2 * PAD), \
	get_min(HEIGHT / 4, data->map_height * PPU + 2 * PAD));
	if (!data->img || !data->img_mm)
		error_exit(ERROR_IMG);
}

void	free_everything(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->map[i])
		free(data->map[i++]);
	free(data->map);
	i = 0;
	while (i < 4)
		mlx_delete_texture(data->textures[i++]);
	free(data->textures);
	free(data->goat);
}

// void	checkleaks(void)
// {
// 	system("leaks -q cub3D");
// }

	// atexit(checkleaks);

int32_t	main(int argc, char **argv)
{
	t_data		data;

	if (!argv || argc != 2)
		error_exit(ERROR_ARGS);
	data.mlx = mlx_init(WIDTH, HEIGHT, "GOAT3D", true);
	if (!data.mlx)
		return (EXIT_FAILURE);
	st_init(&data);
	parsing(argv[1], &data);
	st_img_init(&data);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	draw_minimap(&data);
	casting_rays(&data);
	mlx_image_to_window(data.mlx, data.img, 0, 0);
	mlx_image_to_window(data.mlx, data.img_mm, PAD, data.mlx->height - \
	data.img_mm->height - PAD);
	mlx_loop_hook(data.mlx, key_hooks, &data);
	mlx_cursor_hook(data.mlx, mouse_hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	free_everything(&data);
	return (EXIT_SUCCESS);
}

// free what needs to be freed