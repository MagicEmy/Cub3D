/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:17:23 by emlicame          #+#    #+#             */
/*   Updated: 2023/03/15 11:41:52 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	size_t	j;
	char	*ocean;
	char	*drop;

	i = 0;
	ocean = (char *) haystack;
	drop = (char *) needle;
	if (*needle == '\0')
		return ((char *)haystack);
	while (ocean[i] != '\0' && (size_t)i < len)
	{
		j = 0;
		while (ocean[i + j] == drop[j] && i + j < len)
		{
			j++;
			if (drop[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}
