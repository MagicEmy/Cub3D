/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:17:47 by emlicame          #+#    #+#             */
/*   Updated: 2023/03/15 11:42:05 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	size_t	left;
	size_t	right;
	char	*trimmed;

	left = 0;
	while ((s1[left]) && (ft_check_in_set(s1[left], set)))
		left++;
	right = ft_strlen(s1);
	while (right > left && (ft_check_in_set(s1[right - 1], set)))
		right--;
	trimmed = (char *)malloc (sizeof (*s1) * (right - left + 1));
	if (!trimmed)
		return (NULL);
	i = 0;
	while (left < right)
	{
		trimmed[i] = s1[left];
		left++;
		i++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}
