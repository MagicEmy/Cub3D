/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:14:33 by emlicame          #+#    #+#             */
/*   Updated: 2023/03/15 11:40:07 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	lnum;

	lnum = n;
	if (lnum < 0)
	{
		ft_putchar_fd('-', fd);
		lnum = lnum * -1;
	}
	if (lnum > 9)
	{
		ft_putnbr_fd(lnum / 10, fd);
	}
	ft_putchar_fd(lnum % 10 + '0', fd);
}
