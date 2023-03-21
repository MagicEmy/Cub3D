/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:23:48 by emlicame          #+#    #+#             */
/*   Updated: 2023/03/21 12:15:11 by emlicame         ###   ########.fr       */
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

void	init(t_data *data, t_goat *goat)
{
	goat->dist_pp = WIDTH / 2 * tan(to_rad(FOV));
	data->floor_clr = 0x3A776Bff;
	data->ceiling_clr = 0xC4FFFEff;
	data->goat = goat;
	data->nsew_clr[NORTH] = 0xC474EFFF;	// will be removed now that textures work
	data->nsew_clr[SOUTH] = 0xEF74DDFF;	// will be removed now that textures work
	data->nsew_clr[EAST] = 0xEF749FFF;	// will be removed now that textures work
	data->nsew_clr[WEST] = 0xEF8774FF;	// will be removed now that textures work
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
