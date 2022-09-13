/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:48:00 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/13 14:13:08 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H_
# define _LIBFT_H_

# include <stddef.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFFER_SIZE 32

// custom types.
typedef unsigned int	t_bool;
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// Boolean character checks
t_bool	ft_isalpha(int c);
t_bool	ft_islower(int c);
t_bool	ft_isupper(int c);
t_bool	ft_isdigit(int c);
t_bool	ft_issign(int c);
t_bool	ft_isalnum(int c);
t_bool	ft_isascii(int c);
t_bool	ft_isprint(int c);

// Int utils
int		ft_min(int x, int y);
int		ft_max(int x, int y);

// String utils
ssize_t	ft_strlen(char *str);
ssize_t	ft_strlen_nl(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strrchr(char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strtrim(const char *s, const char *set);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	**ft_split(const char *s, char c);
ssize_t	ft_tab_len(char **tab);

// Character modification
int		ft_toupper(int c);
int		ft_tolower(int c);

// malloc functions
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_chardup(const char c);
void	ft_free_tab(char **tab);

// memory utils
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

// conversions
int		ft_atoi(const char *str);
char	*ft_itoa(int n);

// Mappers & iterators
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

// printers
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// tab utils
void	ft_sort_int_tab(int *tab, int size);

// GNL
char	*get_next_line(int fd);

// List functions
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
#endif
