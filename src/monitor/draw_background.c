/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <jbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:27:54 by jbouyer           #+#    #+#             */
/*   Updated: 2022/09/23 10:48:49 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	color_to_int(t_color color)
{
	return (color.r << 16 | color.g << 8 | color.b);
}

void	draw_background(t_global *global)
{
	int	i;
	int	j;

	j = 0;
	while (j < WIN_H)
	{
		i = 0;
		while (i < WIN_W)
		{
			if (j < WIN_H / 2)
				pixel_put(global->img, i, j, color_to_int(global->env.ceiling));
			else
				pixel_put(global->img, i, j, color_to_int(global->env.floor));
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(global->mlx, global->win, global->img, 0, 0);
}
