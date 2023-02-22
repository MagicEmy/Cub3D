/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 12:23:48 by emlicame      #+#    #+#                 */
/*   Updated: 2023/02/22 12:54:59 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdlib.h>

void	hooks(void *param)
{
	mlx_t	*mlx;
	
	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

int	main(int argc, char** argv)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	
	if (!argv || argc < 1)	// adjust!!!!!
		return (EXIT_SUCCESS);
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "GOAT3D", true)))
		return (EXIT_FAILURE);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	casting_rays(img, WIDTH, HEIGHT);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop_hook(mlx, hooks, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}