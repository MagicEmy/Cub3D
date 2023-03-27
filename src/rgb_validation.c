/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:57:53 by emlicame          #+#    #+#             */
/*   Updated: 2023/03/27 15:23:33 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_rgb_format(char *str)
{
	int32_t		i;
	int32_t		comma;

	i = 0;
	comma = 0;
	while (str[i])
	{
		if (str[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		error_exit(ERROR_RGB_ERR);
	i--;
	if (str[i] == ',' || str[0] == ',')
		error_exit(ERROR_RGB_ERR);
	while (i > 0)
	{
		if (str[i] == ',')
		{
			if (str[i - 1] == ',')
				error_exit(ERROR_RGB_ERR);
		}
		i--;
	}
}

int32_t	ft_str_is_digit(char *str)
{
	int32_t	i;

	i = 0;
	if (str == NULL)
		error_exit(ERROR_RGB_ERR);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int32_t	rgb_parsing(char *info, t_parsing *parsing)
{
	char	**rgb;

	rgb = NULL;
	rgb = ft_split(info, ',');
	if (!rgb)
		error_exit(ERROR_MALLOC);
	if (!ft_str_is_digit(rgb[0]) || !ft_str_is_digit(rgb[1]) || \
	!ft_str_is_digit(rgb[2]))
		error_exit(ERROR_RGB_ERR);
	parsing->red = ft_atoi(rgb[0]);
	parsing->green = ft_atoi(rgb[1]);
	parsing->blue = ft_atoi(rgb[2]);
	ft_free_double_arr(rgb);
	rgb = NULL;
	if (parsing->red < 0 || parsing->green < 0 || parsing->blue < 0)
		error_exit(ERROR_RGB_ERR);
	if (parsing->red > 255 || parsing->green > 255 || parsing->blue > 255)
		error_exit(ERROR_RGB_ERR);
	return (get_rgba(parsing->red, parsing->green, parsing->blue, 255));
}

void	rgb_validation(t_parsing *parsing)
{
	int32_t		i;

	i = 0;
	check_rgb_format(parsing->floor);
	check_rgb_format(parsing->ceiling);
	parsing->floor_clr = rgb_parsing(parsing->floor, parsing);
	parsing->ceiling_clr = rgb_parsing(parsing->ceiling, parsing);
}
