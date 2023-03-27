/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 17:15:08 by emlicame      #+#    #+#                 */
/*   Updated: 2023/03/27 17:12:01 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
