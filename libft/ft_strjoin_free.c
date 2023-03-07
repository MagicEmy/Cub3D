/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:47:43 by emlicame          #+#    #+#             */
/*   Updated: 2023/03/07 12:48:25 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	x;
	size_t	total_len;
	size_t	i;
	char	*new_string;

	i = 0;
	x = 0;
	if (!s1 && !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_string = (char *)malloc(sizeof(char) * total_len);
	if (!new_string)
		return (new_string);
	while (s1[x])
		new_string[i++] = s1[x++];
	while (*s2)
		new_string[i++] = *s2++;
	free(s1);
	new_string[i] = '\0';
	return (new_string);
}
