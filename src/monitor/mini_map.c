/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <jbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:07:47 by jbouyer           #+#    #+#             */
/*   Updated: 2022/09/22 17:09:47 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	draw_minimap_wall(int y, int x, t_global *global)
{
	unsigned int	i;
	unsigned int	j;

	j = -1;
	while (++j < TILE_SIZE)
	{
		i = -1;
		while (++i < TILE_SIZE)
		{
			if (i == 0 || j == 0 || i == TILE_SIZE - 1 || j == TILE_SIZE - 1)
				pixel_put();
		}
	}
}

static unsigned int	get_minimap(t_global *global)
{
	unsigned int	i;
	t_minimap		minimap;

	i = -1;
	minimap.height = global->env.height;
	minimap.width = 0;
	while (++i < minimap.height)
		if (ft_strlen(global->env.map[i]) > tmp)
			minimap.width = ft_strlen(global->env.map[i]);
	
	return (minimap);
}

void	draw_minimap(t_global *global)
{
	t_minimap		minimap;
	unsigned int	i;
	unsigned int	j;

	minimap = get_minimap(global);
	minimap.height = global->env.height;
	if (minimap.width * TILE_SIZE > 0.9 * WIN_W ||\
		minimap.height * TILE_SIZE > 0.9 * WIN_H)
		return ;
	j = -1;
	while (++j < minimap.height)
	{
		i = -1;
		while (global->env.map[j][++i] != '\0')
		{
			if (global->env.map[j][i] == ' ')
				continue ;
			else if (global->env.map[j][i] == '1')
				draw_minimap_wall(j, i, global, minimap);
			else
				draw_minimap_floor(j, i, global, minimap);
		}
	}
	draw_position();
	return ;
}
