/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:40:32 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/22 09:05:39 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_next_frame(t_global *global)
{
	global->counter++;
	update_pos(global);
	update_dir(global);
	printf("[%d]pos(%f,%f)dir(%f,%f)\n", global->counter, global->myself.pos.x,\
			global->myself.pos.y, global->myself.dir.x, global->myself.dir.y);
	draw_background(global);
	draw_walls(global);
	// minimap();
	return (0);
}

t_bool  monitor(t_global *global)
{
	mlx_hook(global->win, ON_KEYPRESS, 1L << 0, key_hook_press, global);
	mlx_hook(global->win, ON_KEYRELEASE, 1L << 1, key_hook_release, global);
	// mlx_hook(global->win, ON_MOUSEDOWN, 1L << 2, mouse_hook, global);
	mlx_hook(global->win, ON_DESTROY, 0L, destroy_hook, global);
	mlx_put_image_to_window(global->mlx, global->win, global->img, 0, 0);
	mlx_loop_hook(global->mlx, render_next_frame, global);
	mlx_loop(global->mlx);
	return (TRUE);
}
