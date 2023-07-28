/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 19:49:22 by diwalaku      #+#    #+#                 */
/*   Updated: 2022/11/10 15:04:35 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t d)
{
	unsigned int	x;

	x = 0;
	if (d == 0)
	{
		return (0);
	}
	while ((s1[x] == s2[x]) && (x < d - 1) && s1[x])
	{
		x++;
	}
	return ((unsigned char)(s1[x]) - (unsigned char)(s2[x]));
}
