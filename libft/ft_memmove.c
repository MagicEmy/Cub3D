/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:13:35 by emlicame          #+#    #+#             */
/*   Updated: 2023/03/15 11:39:43 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*s;
	char		*d;
	const char	*temp_src;
	char		*temp_dst;
	size_t		max;

	s = (char *)src;
	d = (char *)dst;
	max = len;
	if (!src && !dst)
		return (NULL);
	if (d < s)
	{
		while (max--)
			*(d++) = *(s++);
	}
	else
	{
		temp_src = s + (len - 1);
		temp_dst = d + (len - 1);
		while (max--)
			*(temp_dst--) = *(temp_src--);
	}
	return (dst);
}
