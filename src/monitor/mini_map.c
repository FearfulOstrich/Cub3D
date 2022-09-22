/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <jbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:07:47 by jbouyer           #+#    #+#             */
/*   Updated: 2022/09/22 16:22:39 by jbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_width(t_global *global)
{
	int				x;
	unsigned int	y;
	int				tmp;

	y = 0;
	tmp = 0;
	while (y < global->env.height)
	{
		x = 0;
		while (global->env.map[y][x])
			x++;
		if (x > tmp)
			tmp = x;
		y++;
	}
	if (tmp * 16 < 0.9 * WIN_W && global->env.height * 16 < 0.9 * WIN_H)
		return (tmp);
	return (-1);
}

void	mini_map(t_global *global)
{
	unsigned int	j;
	int 			i;
	int			width;
	// t_img *img;
	
	j = 0;
	width = get_width(global);
	// img = mlx_new_image(global->mlx, 0.9 * WIN_H, 0.9 * WIN_W);
	if (width == -1)
		return;
	while (global->env.map[j / 16])
	{
		i = 0;
		while (global->env.map[j/16][i / 16])
		{
			if (global->env.map[j / 16][i / 16] == '1')
				pixel_put(global->img, i + (WIN_W - width * 16) / 2, j + (WIN_H - global->env.height*16) / 2, 0x00FFD700);
			// else 
				// pixel_put(global->img, i + (WIN_W - width * 16) / 2, j + (WIN_H - global->env.height*16) / 2, 0x000000000);
			i++;
		}
		j++;
	}
	// mlx_put_image_to_window(global->mlx, global->win, img, 0.05 * WIN_H, 0.05 * WIN_W);
}