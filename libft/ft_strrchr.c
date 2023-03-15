/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:17:38 by emlicame          #+#    #+#             */
/*   Updated: 2023/03/15 11:41:57 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*temp;

	temp = NULL;
	len = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + len);
	while (*s != '\0')
	{
		if ((unsigned char)(*s) == (unsigned char) c)
		{
			temp = (char *) s;
		}
		s++;
	}
	return (temp);
}
