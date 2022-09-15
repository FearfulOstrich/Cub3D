/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:04:25 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/15 10:23:11 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.g"

t_bool	valid_tile(char c)
{
	if (c == '0')
		return (1);
	else if (c == '1')
		return (1);
	else if (c == 'N')
		return (1);
	else if (c == 'S')
		return (1);
	else if (c == 'E')
		return (1);
	else if (c == 'W')
		return (1);
	else
		return (0);
}

t_bool	valid_neighbors(char **grid, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (i++ < 2)
	{
		j = -1;
		while (j++ < 2)
			if (valid_tile(grid[x + i][y + j]) == 0)
				return (0);
	}
	return (1);
}

t_bool	valid_tile(t_map map, int x, int y)
{
	if (map.grid[x][y] != '1')
	{
		if ((x == 0) || (x == map.height - 1))
			return (0);
		if ((y == 0) || (y == map.width - 1))
			return (0);
		return (neighbours_valid(map.grid, x, y));
	}
	return (1);
}

t_bool	valid_map(t_map map)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	j = -1;
	while (++i < map.height)
	{
		while (++j < map.width)
		{
			if ((map.grid[i][j] != ' ') && valid_tile(map.grid, i, j) == 0)
				return (0);
		}
	}
	return (1);
}
