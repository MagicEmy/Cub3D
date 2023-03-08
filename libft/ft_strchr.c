/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:15:08 by emlicame          #+#    #+#             */
/*   Updated: 2022/11/23 20:25:07 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"

#include <string.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	char	*string;

	string = (char *)s;
	while (*string != c)
	{
		if (*string == '\0')
			return (NULL);
		string++;
	}
	return (string);
}


// int	main(void)
// {
// 	int			c;
// 	const char	*s;

// 	c = 'u';
// 	s = "Bibuba";
// 	printf("|%s|\n", ft_strchr(s, 't' + 256));
// 	printf("%s", strchr(s, 't' + 256));
// 	// printf("|%s|\n", ft_strchr(s, 't' + 256));
// 	// printf("%s", strchr(s, 't' + 256));
// 	return (0);
// }