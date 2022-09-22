/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <jbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:07:47 by jbouyer           #+#    #+#             */
/*   Updated: 2022/09/22 17:26:14 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_minimap_wall(int y, int x, t_global *global,\
									t_minimap minimap)
{
	unsigned int	j;
	unsigned int	i;
	unsigned int	pix_x;
	unsigned int	pix_y;

	j = -1;
	while (++j < TILE_SIZE)
	{
		i = -1;
		while (++i < TILE_SIZE)
		{
			pix_x = minimap.offset_width + x * TILE_SIZE + i;
			pix_y = minimap.offset_height + y * TILE_SIZE + j;
			if (i == 0 || j == 0 || i == TILE_SIZE - 1 || j == TILE_SIZE - 1)
				pixel_put(global->img, pix_x, pix_y, WALL_C1);
			else
				pixel_put(global->img, pix_x, pix_y, WALL_C2);
		}
	}
	return ;
}

static void	draw_minimap_floor(int y, int x, t_global *global,\
								t_minimap minimap)
{
	unsigned int	j;
	unsigned int	i;
	unsigned int	pix_x;
	unsigned int	pix_y;

	j = -1;
	while (++j < TILE_SIZE)
	{
		i = -1;
		while (++i < TILE_SIZE)
		{
			pix_x = minimap.offset_width + x * TILE_SIZE + i;
			pix_y = minimap.offset_height + y * TILE_SIZE + j;
			pixel_put(global->img, pix_x, pix_y, FLOOR_C);
		}
	}
	return ;
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
	minimap.offset_width = (WIN_W - minimap.width) / 2;
	minimap.offset_height = (WIN_H - minimap.height) / 2;
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
	// draw_position();
	return ;
}
