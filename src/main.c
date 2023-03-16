/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 12:23:48 by emlicame      #+#    #+#                 */
/*   Updated: 2023/03/16 18:34:19 by dmalacov      ########   odam.nl         */
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

void	key_hooks(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		return (mlx_close_window(data->mlx));
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		go_left_right(MLX_KEY_D, data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		go_left_right(MLX_KEY_A, data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		go_fwd_bck(MLX_KEY_W, data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		go_fwd_bck(MLX_KEY_S, data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		look_left_right(MLX_KEY_RIGHT, data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		look_left_right(MLX_KEY_LEFT, data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_G))
		print_goat_info(data);
}

void	init(t_data *data, t_goat *goat)
{
	goat->x = 16.5;
	goat->y = 2.5;
	goat->angle = 90;
	goat->dist_pp = WIDTH / 2 * tan(to_rad(FOV));
	data->map = NULL;
	data->map_width = 23;
	data->map_height = 11;
	data->floor_clr = 0x3A776Bff;
	data->sky_clr = 0xC4FFFEff;
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
	data->set = " \t\v\f\r\n";
	data->map_start = 0;
	data->map_end = 0;
	data->counter = 0;
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
	info_map_parsing(argv[1], &data);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img_mm = mlx_new_image(data.mlx, WIDTH / 2, HEIGHT / 4);
	draw_minimap(&data);
	casting_rays(&data);
	mlx_image_to_window(data.mlx, data.img, 0, 0);
	mlx_image_to_window(data.mlx, data.img_mm, PADDING, data.mlx->height - \
	data.img_mm->height - PADDING);
	mlx_loop_hook(data.mlx, key_hooks, &data);
	mlx_cursor_hook(data.mlx, mouse_hook, &data);	// move to bonus
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	// free what needs to be freed
	return (EXIT_SUCCESS);
}
