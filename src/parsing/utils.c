/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:34:10 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/20 12:44:32 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int	check_color(char *color)
{
	unsigned int	i;

	i = -1;
	while (++i < ft_strlen(color))
		if (color[i] != '-' && (color[i] < '0' || color[i] > '9'))
			return (-1);
	return (ft_atoi(color));
}

t_bool	set_color(t_color *color)
{
	char	**rgb;

	rgb = ft_split(color->input, ',');
	if (rgb == NULL)
		return (FALSE);
	if (ft_tab_len(rgb) != 3)
		return (ft_free_tab(rgb), FALSE);
	color->R = check_color(rgb[0]);
	color->G = check_color(rgb[1]);
	color->B = check_color(rgb[2]);
	color->set = TRUE;
	ft_free_tab(rgb);
	return (TRUE);
}

t_bool	get_path(char *line, char *ref, char **dest)
{
	char	**tab;

	if (line == NULL)
		return (FALSE);
	tab = ft_split(line, ' ');
	if (tab == NULL)
		return (FALSE);
	if (ft_tab_len(tab) != 2)
		return (ft_free_tab(tab), FALSE);
	if (ft_strcmp(tab[0], ref) != 0)
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
	if (env.NO.path && env.SO.path && env.WE.path && env.EA.path\
		&& env.floor.set && env.ceiling.set)
		return (TRUE);
	else
		return (FALSE);
}
