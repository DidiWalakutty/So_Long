/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 18:27:25 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/09/14 16:20:32 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

int		ft_isalpha(int d);
int		ft_isdigit(int d);
int		ft_isalnum(int d);
int		ft_isascii(int d);
int		ft_isprint(int d);
int		ft_toupper(int d);
int		ft_tolower(int d);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int d);
int		ft_strncmp(const char *s1, const char *s2, size_t d);
char	*ft_strrchr(const char *s, int d);
int		ft_atoi(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
void	ft_putnbr_fd(int n, int fd);
char	**ft_split(char const *str, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_itoa(int x);

char	*get_next_line(int fd);
char	*read_and_join(int fd, char *buffer, char *line);
size_t	find_length(const char *s);
char	*find_newline(char *s);
size_t	newline_in_buffer(char *buffer);
char	*gnl_ft_strjoin(char *line, char *buffer);
void	manage_buffer(char *dst, char *src);
void	copy_str(char *dst, char *src);
void	*gnl_ft_calloc(size_t count, size_t size);

int		ft_printf(const char *format, ...);
int		print_char(char c);
int		print_str(char *s);
int		print_nbr(int n);
int		print_uns_dec(unsigned int n);
int		print_lowerhex(unsigned long n);
int		print_upperhex(unsigned int n);
int		print_pointer(unsigned long ptr);

#endif