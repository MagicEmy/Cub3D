/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:13:38 by emlicame          #+#    #+#             */
/*   Updated: 2023/03/09 15:14:08 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_is_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_is_space(str[i]))
			return (0);
		i++;
	}
	return (1);
}
