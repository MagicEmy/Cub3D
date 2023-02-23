/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   casting_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmalacov <dmalacov@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 11:04:01 by dmalacov      #+#    #+#                 */
/*   Updated: 2023/02/23 16:59:53 by dmalacov      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double	to_rad(double angle)
{
	return (angle * M_PI / 180);
}