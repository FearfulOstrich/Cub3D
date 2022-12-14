/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:40:32 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/23 11:06:27 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_next_frame(t_global *global)
{
	global->counter++;
	update_pos(global);
	update_dir(global);
	draw_background(global);
	draw_walls(global);
	mlx_put_image_to_window(global->mlx, global->win, global->img, 0, 0);
	return (0);
}

t_bool	monitor(t_global *global)
{
	mlx_hook(global->win, ON_KEYPRESS, 1L << 0, key_hook_press, global);
	mlx_hook(global->win, ON_KEYRELEASE, 1L << 1, key_hook_release, global);
	mlx_hook(global->win, ON_DESTROY, 0L, destroy_hook, global);
	mlx_loop_hook(global->mlx, render_next_frame, global);
	mlx_loop(global->mlx);
	return (TRUE);
}
