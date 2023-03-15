/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_multi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:14:53 by emlicame          #+#    #+#             */
/*   Updated: 2023/03/15 11:40:21 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free_mem_multi(char **split)
{
	int	x;

	x = 0;
	while (split[x])
	{
		free(split[x]);
		x++;
	}
	free(split);
	return (1);
}

int	ft_alloc_copy_multi(char const *s, char *set, char **split, size_t w_c)
{
	size_t		len;
	size_t		index;
	size_t		i;

	i = 0;
	index = 0;
	while (index < w_c)
	{
		len = 0;
		while (!ft_char_set(s[i + len], set) && s[i + len] != '\0')
		{
			len++;
			if (ft_char_set(s[i + len], set) || s[i + len] == '\0')
			{
				split[index] = ft_substr(s, i, len);
				if (!split[index++])
					ft_free_mem_multi(split);
			}
		}
		i += len + 1;
	}
	split[index] = 0;
	return (0);
}

size_t	ft_count_words(char const *s, char *set)
{
	int		i;
	size_t	w_c;

	i = 0;
	w_c = 0;
	while (s[i])
	{
		if (!ft_char_set(s[i], set))
			w_c++;
		while (!ft_char_set(s[i], set) && s[i])
			i++;
		while (ft_char_set(s[i], set) && s[i])
			i++;
	}
	return (w_c);
}

char	**ft_split_multi(char const *s, char *set)
{
	char	**split;
	size_t	w_c;

	if (!s)
		return (NULL);
	w_c = ft_count_words(s, set);
	split = (char **)ft_calloc((w_c + 1), (sizeof(char *)));
	if (!split)
		return (NULL);
	if (ft_alloc_copy_multi(s, set, split, w_c))
		return (0);
	return (split);
}
