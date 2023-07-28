/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/12 19:37:20 by diwalaku      #+#    #+#                 */
/*   Updated: 2022/11/12 20:02:27 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;
	size_t			x;

	str = (unsigned char *) s;
	ch = (unsigned char) c;
	x = 0;
	while (x < n)
	{
		if (str[x] == ch)
			return (str + x);
		x++;
	}
	return (0);
}
