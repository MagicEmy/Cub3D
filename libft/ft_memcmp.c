/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: emlicame <emlicame@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 17:13:03 by emlicame      #+#    #+#                 */
/*   Updated: 2023/12/21 12:42:24 by emlicame      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;
	size_t			i;

	i = 0;
	string1 = (unsigned char *) s1;
	string2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (string1[i] == string2[i] && *string1 != '\0' && i < n - 1)
	{
		i++;
	}
	return (string1[i] - string2[i]);
}
