/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:04:25 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/21 17:09:25 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_bool	valid_char(char c)
{
	if (c == '0')
		return (TRUE);
	else if (c == '1')
		return (TRUE);
	else if (c == 'N')
		return (TRUE);
	else if (c == 'S')
		return (TRUE);
	else if (c == 'E')
		return (TRUE);
	else if (c == 'W')
		return (TRUE);
	else
		return (FALSE);
}

t_bool	check_neighbors(char **map, unsigned int y, unsigned int x)
{
	int	i;
	int	j;

	i = -1;
	while (i++ < 2)
	{
		j = -1;
		while (j++ < 2)
		{
			if (abs(i) + abs(j) != 1)
				continue ;
			if (ft_strlen(map[y + i]) <= x)
				return (FALSE);
			if (valid_char(map[y + i][x + j]) == FALSE)
				return (FALSE);
		}
	}
	return (TRUE);
}

t_bool	valid_tile(t_env env, unsigned int y, unsigned int x)
{
	if (valid_char(env.map[y][x] == FALSE))
		return (FALSE);
	if (env.map[y][x] != '1')
	{
		if ((y == 0) || (y == env.height - 1))
			return (FALSE);
		if ((x == 0) || (x == ft_strlen(env.map[y]) - 1))
			return (FALSE);
		return (check_neighbors(env.map, y, x));
	}
	return (TRUE);
}

t_bool	valid_map(t_env env)
{
	unsigned int	i;
	unsigned int	j;

	j = -1;
	while (++j < env.height)
	{
		i = -1;
		while (++i < ft_strlen(env.map[j]))
			if ((env.map[j][i] != ' ') && valid_tile(env, j, i) == FALSE)
				return (FALSE);
	}
	return (TRUE);
}
