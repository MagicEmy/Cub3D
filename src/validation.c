/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:50:25 by emlicame          #+#    #+#             */
/*   Updated: 2023/03/19 18:52:59 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	rgb_range_check(t_parsing *parsing)
{
	parsing->ceiling_clr = 0;
	parsing->floor_clr = 0;
	if (parsing->floor_red < 0 || parsing->floor_green < 0 || \
	parsing->floor_blue < 0)
		error_exit(ERROR_RGB_ERR);
	if (parsing->floor_red > 255 || parsing->floor_green > 255 || \
	parsing->floor_blue > 255)
		error_exit(ERROR_RGB_ERR);
	if (parsing->ceiling_red < 0 || parsing->ceiling_green < 0 || \
	parsing->ceiling_blue < 0)
		error_exit(ERROR_RGB_ERR);
	if (parsing->ceiling_red > 255 || parsing->ceiling_green > 255 || \
	parsing->ceiling_blue > 255)
		error_exit(ERROR_RGB_ERR);
	parsing->floor_clr = get_rgba(parsing->floor_red, parsing->floor_green, \
	parsing->floor_blue, 255);
	parsing->ceiling_clr = get_rgba(parsing->ceiling_red, \
	parsing->ceiling_green, parsing->ceiling_blue, 255);
}

void	rgb_validation(t_parsing *parsing)
{
	char	**rgb;
	int		color;
	
	rgb = NULL;
	rgb = ft_split(parsing->floor, ',');
	if (!rgb)
		error_exit(ERROR_MALLOC);
	if (!rgb[0] || !rgb[1] || !rgb[2])
		error_exit(ERROR_RGB_ERR);
	color = get_rgba(rgb[0], rgb[1], rgb[2], 255);
	parsing->floor_red = ft_atoi(rgb[0]);
	parsing->floor_green = ft_atoi(rgb[1]);
	parsing->floor_blue = ft_atoi(rgb[2]);
	ft_free_double_arr(rgb);
	rgb = ft_split(parsing->ceiling, ',');
	if (!rgb)
		error_exit(ERROR_MALLOC);
	if (!rgb[0] || !rgb[1] || !rgb[2])
		error_exit(ERROR_RGB_ERR);
	parsing->ceiling_red = ft_atoi(rgb[0]);
	parsing->ceiling_green = ft_atoi(rgb[1]);
	parsing->ceiling_blue = ft_atoi(rgb[2]);
	ft_free_double_arr(rgb);
	rgb_range_check(parsing);
}
