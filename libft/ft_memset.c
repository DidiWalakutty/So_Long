/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/10 14:25:50 by diwalaku      #+#    #+#                 */
/*   Updated: 2022/11/10 15:03:40 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*ptr;
	size_t			x;

	ptr = b;
	x = 0;
	while (x < len)
	{
		*ptr = c;
		ptr++;
		x++;
	}
	return (b);
}
