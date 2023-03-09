/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 12:23:48 by emlicame      #+#    #+#                 */
/*   Updated: 2023/03/08 19:00:16 by dmalacov      ########   odam.nl         */
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


void    key_hooks(mlx_key_data_t keydata, void *param)
{

	t_data  *data;
	data = (t_data *)param;
	if (keydata.action != MLX_PRESS && keydata.action != MLX_REPEAT)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		return (mlx_close_window(data->mlx));
	if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_A)
		go_left_right(keydata.key, data);
	if (keydata.key == MLX_KEY_W  || keydata.key == MLX_KEY_S)
		go_up_down(keydata.key, data);
	if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_LEFT)
		look_left_right(keydata.key, data);
	casting_rays(data);
	// printf("Goat coordinates: %f, %f\n", data->goat->x, data->goat->y);
	// printf("Goat angle: %f\n", data->goat->angle);
}

void	init(t_data *data, t_goat *goat)
{
	goat->x = 16.5;
	goat->y = 5.5;
	goat->angle = 90;
	data->map = NULL;
	data->map_width = 23;
	data->map_height = 11;
	data->floor_clr = 0x25A703ff;
	data->sky_clr = 0x8FFFFDff;
	data->goat = goat;
}

int32_t	main(int argc, char **argv)
{
	t_goat		goat;
	t_data		data;
	
	if (!argv || argc != 2)
		error_exit(ERROR_ARGS);
	
	init(&data, &goat);
	info_map_parsing(argv[1], &data);
	if (!(data.mlx = mlx_init(WIDTH, HEIGHT, "GOAT3D", true)))
		return (EXIT_FAILURE);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	casting_rays(&data);
	mlx_image_to_window(data.mlx, data.img, 0, 0);
	mlx_key_hook(data.mlx, key_hooks, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
  
	// free what needs to be freed
	
	return (EXIT_SUCCESS);
}
