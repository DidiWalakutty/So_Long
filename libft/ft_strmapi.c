/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 21:03:56 by diwalaku      #+#    #+#                 */
/*   Updated: 2022/11/21 18:12:43 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	x;
	size_t	len;
	char	*new;

	x = 0;
	len = ft_strlen(s);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!s || !f || !new)
		return (0);
	while (s[x])
	{
		new[x] = f(x, s[x]);
		x++;
	}
	new[x] = '\0';
	return (new);
}
