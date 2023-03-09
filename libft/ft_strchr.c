/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:15:08 by emlicame          #+#    #+#             */
/*   Updated: 2023/03/08 19:21:42 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"

#include <string.h>


char	*ft_strchr(const char *s, int c)
{
	char	*string;

	c = c % 256;
	string = (char *)s;
	while (*string != c)
	{
		if (*string == '\0')
			return (NULL);
		string++;
	}
	return (string);
}

/*
#include <stdio.h>
int	main(void)
{
	int			c;
	const char	*s;

	c = 'u';
	s = "Bibuba";
	printf("|%s|\n", ft_strchr(s, 'u' + 256));
	printf("%s", strchr(s, 'u' + 256));
	// printf("|%s|\n", ft_strchr(s, 't'));
	// printf("%s", strchr(s, 't'));
	return (0);
}
*/