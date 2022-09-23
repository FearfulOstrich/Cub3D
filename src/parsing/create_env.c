/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:08:35 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/23 11:34:23 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_bool	fill_map(t_env *env, char *line)
{
	char	**new_grid;
	int		i;

	i = -1;
	new_grid = ft_calloc(ft_tab_len(env->map) + 2, sizeof(*new_grid));
	if (new_grid == NULL)
		return (FALSE);
	while (env->map[++i] != NULL)
		new_grid[i] = env->map[i];
	new_grid[i] = ft_strtrim(line, "\n");
	if (new_grid[i] == NULL)
		return (free(new_grid), FALSE);
	free(env->map);
	env->map = new_grid;
	return (TRUE);
}

static t_bool	set_params(char *str, t_env *env)
{
	char	*tmp;

	tmp = ft_strtrim(str, " \n");
	if (env->no.path == NULL && get_path(tmp, "NO", &env->no.path) == TRUE)
		return (free(tmp), TRUE);
	else if (env->so.path == NULL && get_path(tmp, "SO", &env->so.path) == TRUE)
		return (free(tmp), TRUE);
	else if (env->we.path == NULL && get_path(tmp, "WE", &env->we.path) == TRUE)
		return (free(tmp), TRUE);
	else if (env->ea.path == NULL && get_path(tmp, "EA", &env->ea.path) == TRUE)
		return (free(tmp), TRUE);
	else if (env->floor.set == False && \
			get_path(tmp, "F", &env->floor.input) == TRUE)
		return (free(tmp), set_color(&env->floor));
	else if (env->ceiling.set == False && \
			get_path(tmp, "C", &env->ceiling.input) == TRUE)
		return (free(tmp), set_color(&env->ceiling));
	else
		return (free(tmp), FALSE);
}

static char	*free_gnl(int fd, char *line)
{
	free(line);
	return (get_next_line(fd));
}

t_bool	create_env(int fd, t_env *env)
{
	char	*line;

	line = get_next_line(fd);
	while (line && params_all_set(*env) == FALSE)
	{
		if (is_line_empty(line) == FALSE)
			if (set_params(line, env) == FALSE)
				return (free(line), map_error());
		line = free_gnl(fd, line);
	}
	while (line && is_line_empty(line) == TRUE)
		line = free_gnl(fd, line);
	while (line && is_line_empty(line) == FALSE)
	{
		if (fill_map(env, line) == FALSE)
			return (free(line), map_error());
		line = free_gnl(fd, line);
	}
	if (line != NULL)
		return (free(line), TRUE);
	return (TRUE);
}
