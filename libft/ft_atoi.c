/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 17:31:58 by diwalaku      #+#    #+#                 */
/*   Updated: 2022/11/10 15:05:08 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	x;
	int	n;
	int	multx;

	x = 0;
	n = 0;
	multx = 1;
	while (str[x] && (str[x] == '\t' || str[x] == '\n' || str[x] == '\v' || \
	str[x] == '\f' || str[x] == '\r' || str[x] == ' '))
		x++;
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			multx *= -1;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		n = (n * 10) + (str[x] - '0');
		x++;
	}
	n *= multx;
	return (n);
}
