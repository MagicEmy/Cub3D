/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_bonus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/27 13:13:21 by dmalacov      #+#    #+#                 */
/*   Updated: 2023/03/27 16:51:09 by dmalacov      ########   odam.nl         */
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

void	init(t_data *data, t_goat *goat)
{
	goat->dist_pp = WIDTH / 2 * tan(to_rad(FOV));
	data->goat = goat;
	data->offset.x = 0;
	data->offset.y = 0;
	mlx_get_mouse_pos(data->mlx, &data->cursor_x, &data->cursor_y);
}

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
	parsing(argv[1], &data);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img_mm = mlx_new_image(data.mlx, \
	get_min(WIDTH / 2, data.map_width * PPU + 2 * PAD), \
	get_min(HEIGHT / 4, data.map_height * PPU + 2 * PAD));
	draw_minimap(&data);
	casting_rays(&data);
	mlx_image_to_window(data.mlx, data.img, 0, 0);
	mlx_image_to_window(data.mlx, data.img_mm, PAD, data.mlx->height - \
	data.img_mm->height - PAD);
	mlx_loop_hook(data.mlx, key_hooks, &data);
	mlx_cursor_hook(data.mlx, mouse_hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	// free what needs to be freed
	return (EXIT_SUCCESS);
}
