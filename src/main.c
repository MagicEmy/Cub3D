/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 12:23:48 by emlicame      #+#    #+#                 */
/*   Updated: 2023/02/28 19:25:57 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "cub3D_structures.h"
#include <stdlib.h>
#include <stdio.h> 	//DELETE

void    key_hooks(mlx_key_data_t keydata, void *param)
{
    t_data  *data;
    data = (t_data *)param;
    if (keydata.action != MLX_PRESS && keydata.action != MLX_REPEAT)
        return ;
    if (keydata.key == MLX_KEY_ESCAPE)
        return (mlx_close_window(data->mlx));
    if (keydata.key == MLX_KEY_D && !is_wall(data, 1, 0))
       data->goat->x += 1;
    if (keydata.key == MLX_KEY_A && !is_wall(data, -1, 0))
        data->goat->x -= 1;
    if (keydata.key == MLX_KEY_W && !is_wall(data, 0, -1))
        data->goat->y -= 1;
    if (keydata.key == MLX_KEY_S && !is_wall(data, 0, 1))
        data->goat->y += 1;
    if (keydata.key == MLX_KEY_RIGHT)
	{
        data->goat->angle -= 15;
		if (data->goat->angle < 0)
			data->goat->angle += 360;
	}
    if (keydata.key == MLX_KEY_LEFT)
	{
       data->goat->angle += 15;
		if (data->goat->angle >= 360)
			data->goat->angle -= 360;
	}
	casting_rays(data, data->goat);
	printf("Goat coordinates: %f, %f\n", data->goat->x, data->goat->y);
	printf("Goat angle: %f\n", data->goat->angle);
}

void	init(t_data *data, t_goat *goat)
{
	goat->x = 19;
	goat->y = 7;
	goat->angle = 90;
	data->map = NULL;
	data->map_width = 30;
	data->map_height = 10;
	data->floor_clr = 0x25A703ff;
	data->sky_clr = 0x8FFFFDff;
	data->goat = goat;
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
	mlx_key_hook(data.mlx, key_hooks, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}