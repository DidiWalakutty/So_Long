/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 17:42:31 by diwalaku      #+#    #+#                 */
/*   Updated: 2022/10/14 20:10:34 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	x;

	x = 0;
	if (dstsize == 0)
	{
		return (ft_strlen(src));
	}
	while ((src[x] != '\0') && (x < dstsize - 1))
	{	
		dst[x] = src[x];
		x++;
	}	
	dst[x] = '\0';
	return (ft_strlen(src));
}
