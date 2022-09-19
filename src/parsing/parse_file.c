/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:51:08 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/19 12:19:20 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static t_bool	set_params(char *str, t_env *env)
{
	char	*tmp;
	char	*path;

	tmp = ft_strtrim(str, " ");
	if (tmp == 0)
		return (FALSE);
	else if (env->NO.path == NULL && get_path(tmp, "NO", &env->NO.path) == TRUE)
		return (free(tmp), TRUE);
	else if (env->SO.path == NULL && get_path(tmp, "SO", &env->SO.path) == TRUE)
		return (free(tmp), TRUE);
	else if (env->WE.path == NULL && get_path(tmp, "WE", &env->WE.path) == TRUE)
		return (free(tmp), TRUE);
	else if (env->EA.path == NULL && get_path(tmp, "EA", &env->EA.path) == TRUE)
		return (free(tmp), TRUE);
	else if (get_path(tmp, "F") != 0)
		return (set_color(get_path(tmp, "F"), global, 'F'));
	else if (get_path(tmp, "C") != 0)
		return (set_color(get_path(tmp, "C"), global, 'C'));
	else
		return (-1);
	return (0);
}

static t_bool	create_env(int fd, t_env *env)
{
	char	*line;

	line = "";
	while (line && params_all_set(*env) == FALSE)
	{
		line = get_next_line(fd);
		if (is_line_empty(line) == FALSE)
			if (set_params(line, env) != 0)
				return (-1, ft_putstr_fd("Error params\n", 1));
		free(line);
	}
}

t_bool	parse_file(char *fname, t_global *global)
{
	int	fd;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (1);
	return (create_env(fd, &global->env);
}
