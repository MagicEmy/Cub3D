/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:23:48 by emlicame          #+#    #+#             */
/*   Updated: 2023/03/09 18:06:31 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	error_exit(char *text)
{
	ft_putstr_fd(C_RED"\nE"C_YELLOW"RR"C_VIOLET"OR\t"C_BLUE, 2);
	ft_putendl_fd(text, 2);
	ft_putendl_fd(C_RESET, 2);
	exit(EXIT_FAILURE);
}

void	hooks(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

int32_t	main(int argc, char **argv)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_data		*data;

	if (!argv || argc != 2)
		error_exit(ERROR_ARGS);
	data = cube_data_init();
	info_map_parsing(argv[1], data);
	mlx = mlx_init(WIDTH, HEIGHT, "GOAT3D", true);
	if (!mlx)
		return (EXIT_FAILURE);
	data->mlx = mlx;
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	casting_rays(img, WIDTH, HEIGHT);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop_hook(mlx, hooks, mlx);
	mlx_loop(mlx);
	free(data);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
