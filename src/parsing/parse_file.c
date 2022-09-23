/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:51:08 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/23 11:30:10 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_bool	is_map_ok(char *tmp)
{
	int		i;
	int		j;
	char	*str;

	i = ft_strlen(tmp) - 4;
	j = 0;
	str = ".cub";
	while (tmp[i])
	{
		if (str[j] != tmp[i])
			return (FALSE);
		i++;
		j++;
	}
	return (TRUE);
}

t_bool	parse_file(char *fname, t_global *global)
{
	int		fd;

	if (is_map_ok(fname) == FALSE)
		return (ft_putstr_fd("ERROR\ncorrect map format: *.cub.\n", 1), FALSE);
	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("ERROR\nMAP NOT FOUND.\n", 1), FALSE);
	if (create_env(fd, &global->env) == FALSE)
		return (ft_putstr_fd("Environment could not be created.\n", 1), FALSE);
	close(fd);
	if (validate_env(&global->env, global->mlx) == FALSE)
		return (ft_putstr_fd("Environment is not valid.", 1), FALSE);
	return (TRUE);
}
