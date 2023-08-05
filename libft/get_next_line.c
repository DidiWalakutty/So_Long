/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/21 22:05:13 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/08/05 11:28:04 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	copy_str(char *dst, char *src)
{
	size_t	x;

	x = 0;
	while (src[x])
	{
		dst[x] = src[x];
		if (src[x] == '\n')
			return ;
		x++;
	}
}

char	*gnl_ft_strjoin(char *line, char *buffer)
{
	size_t	len_l;
	size_t	len_b;
	char	*new;

	len_l = find_length(line);
	len_b = find_length(buffer);
	new = gnl_ft_calloc((len_l + len_b + 1), sizeof(char));
	if (!new)
		return (free(line), NULL);
	copy_str(new, line);
	copy_str(&new[len_l], buffer);
	free(line);
	return (new);
}

char	*read_and_join(int fd, char *buffer, char *line)
{
	ssize_t		read_bytes;

	read_bytes = 1;
	if (buffer[0] != '\0')
	{
		line = gnl_ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
	}
	while (!find_newline(buffer) && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			buffer[0] = '\0';
			return (free(line), NULL);
		}
		buffer[read_bytes] = '\0';
		line = gnl_ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = gnl_ft_calloc(1, sizeof(char));
	if (!line)
		return (NULL);
	line = read_and_join(fd, buffer, line);
	if (!line)
		return (NULL);
	if (buffer[0] != '\0')
		manage_buffer(buffer, find_newline(buffer));
	if (find_length(line) == 0)
		return (free(line), NULL);
	return (line);
}
