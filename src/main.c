/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 12:23:48 by emlicame      #+#    #+#                 */
/*   Updated: 2023/02/23 19:11:13 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "cub3D_structures.h"
#include <stdlib.h>

void	hooks(void *param)
{
	mlx_t	*mlx;
	
	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

void	init(t_data *data, t_goat *goat)
{
	goat->x = 14;
	goat->y = 5;
	goat->angle = 0;
	data->map = NULL;
	data->map_width = 30;
	data->map_height = 10;
	data->floor_clr = 0x25A703ff;
	data->sky_clr = 0x8FFFFDff;
}

int	main(int argc, char** argv)
{
	t_goat		goat;
	t_data		data;
	
	if (!argv || argc < 1)	// adjust!!!!!
		return (EXIT_SUCCESS);
	
	init(&data, &goat);
	
	if (!(data.mlx = mlx_init(WIDTH, HEIGHT, "GOAT3D", true)))
		return (EXIT_FAILURE);
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	casting_rays(&data, &goat);
	mlx_image_to_window(data.mlx, data.img, 0, 0);
	mlx_loop_hook(data.mlx, hooks, data.mlx);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}