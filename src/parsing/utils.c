/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:34:10 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/19 12:16:46 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_bool	get_path(char *tmp, char *str, char **dest)
{
	char	**tab;

	if (!tmp || !str)
		return (FALSE);
	tab = ft_split(tmp, ' ');
	if (ft_tab_len(tab) != 2)
		return (ft_free_tab(tab), FALSE);
	if (ft_strcmp(tab[0], str) != 0)
		return (ft_free_tab(tab), FALSE);
	*dest = ft_strdup(tab[1]);
	ft_free_tab(tab);
	return (TRUE);
}

t_bool	is_line_empty(char *str)
{
	char	*line_trimmed;

	line_trimmed = ft_strtrim(str, " \n");
	if (*line_trimmed != '\0')
		return (free(line_trimmed), FALSE);
	return (free(line_trimmed), TRUE);
}

t_bool	params_all_set(t_env env)
{
	if (env->NO.path && env->SO.path && env->WE.path && env->EA.path\
		&& env->floor.set && env->ceiling.set)
		return (TRUE);
	else
		return (FALSE);
}
