/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:26:37 by aalleon           #+#    #+#             */
/*   Updated: 2022/03/04 13:18:22 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_buffer(char *container, char *buffer, int fd)
{
	char	*tmp;
	int		res;

	res = 1;
	while (!ft_strchr(container, '\n') && res)
	{
		res = read(fd, buffer, BUFFER_SIZE);
		if (res == -1)
			return (0);
		buffer[res] = '\0';
		tmp = ft_strjoin(container, buffer);
		free(container);
		if (!tmp)
			return (0);
		container = tmp;
	}
	return (container);
}

char	*ft_read_next_line(int fd, char *cache)
{
	char	*buf;
	char	*container;

	if (!cache)
		container = ft_strdup("");
	else
		container = ft_strdup(cache);
	buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
	if (!buf || !container)
		return (0);
	container = read_buffer(container, buf, fd);
	free(buf);
	return (container);
}

char	*ft_extract_line(char *container)
{
	char	*line;
	int		cpt;

	cpt = -1;
	if (!*container)
	{
		free(container);
		return (0);
	}
	line = malloc(sizeof(*line) * (ft_strlen_nl(container) + 1));
	if (!line)
	{
		free(container);
		return (0);
	}
	while (++cpt < ft_strlen_nl(container))
		line[cpt] = container[cpt];
	line[cpt] = '\0';
	return (line);
}

void	ft_update_cache(char *container, char *cache)
{
	int		cpt;

	ft_bzero(cache, BUFFER_SIZE);
	cpt = ft_strlen_nl(container) - 1;
	while (++cpt < ft_strlen(container))
		cache[cpt - ft_strlen_nl(container)] = container[cpt];
}

char	*get_next_line(int fd)
{
	static char	cache[BUFFER_SIZE];
	char		*container;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > FOPEN_MAX)
		return (0);
	container = ft_read_next_line(fd, cache);
	if (!container)
		return (0);
	line = ft_extract_line(container);
	if (!line)
		return (0);
	ft_update_cache(container, cache);
	free(container);
	return (line);
}
