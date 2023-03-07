/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:57:53 by emlicame          #+#    #+#             */
/*   Updated: 2023/03/07 18:33:54 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rgb_range_check(t_data *data)
{
	if (data->floor_red < 0 || data->floor_green < 0 || data->floor_blue < 0)
		error_exit(ERROR_RGB_ERR);
	if (data->floor_red > 255 || data->floor_green > 255 || \
	data->floor_blue > 255)
		error_exit(ERROR_RGB_ERR);
	if (data->ceiling_red < 0 || data->ceiling_green < 0 || \
	data->ceiling_blue < 0)
		error_exit(ERROR_RGB_ERR);
	if (data->ceiling_red > 255 || data->ceiling_green > 255 || \
	data->ceiling_blue > 255)
		error_exit(ERROR_RGB_ERR);
}

void	rgb_validation(t_data *data)
{
	char	**rgb;

	rgb = ft_split(data->floor, ',');
	if (!rgb)
		error_exit(ERROR_MALLOC);
	if (!rgb[0] || !rgb[1] || !rgb[2])
		error_exit(ERROR_RGB_ERR);
	data->floor_red = ft_atoi(rgb[0]);
	data->floor_green = ft_atoi(rgb[1]);
	data->floor_blue = ft_atoi(rgb[2]);
	ft_free_double_arr(rgb);
	rgb = ft_split(data->ceiling, ',');
	if (!rgb)
		error_exit(ERROR_MALLOC);
	if (!rgb[0] || !rgb[1] || !rgb[2])
		error_exit(ERROR_RGB_ERR);
	data->ceiling_red = ft_atoi(rgb[0]);
	data->ceiling_green = ft_atoi(rgb[1]);
	data->ceiling_blue = ft_atoi(rgb[2]);
	ft_free_double_arr(rgb);
	rgb_range_check(data);
}
