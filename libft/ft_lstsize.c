/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:12:48 by emlicame          #+#    #+#             */
/*   Updated: 2023/03/15 11:39:24 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		elements;

	elements = 0;
	if (lst)
		current = lst;
	else
		return (0);
	while (current != NULL)
	{
		elements++;
		current = current->next;
	}
	return (elements);
}
