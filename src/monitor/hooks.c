/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:41:36 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/23 10:48:59 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook_press(int key, t_global *global)
{
	if (key == 65307)
	{
		((t_xvar *)(global->mlx))->end_loop = 1;
		return (0);
	}
	if (key == 119)
		global->myself.w_press = TRUE;
	if (key == 115)
		global->myself.s_press = TRUE;
	if (key == 97)
		global->myself.a_press = TRUE;
	if (key == 100)
		global->myself.d_press = TRUE;
	if (key == 65363)
		global->myself.right_press = TRUE;
	if (key == 65361)
		global->myself.left_press = TRUE;
	if (key == 109 && global->myself.minimap == FALSE)
		global->myself.minimap = TRUE;
	else if (key == 109 && global->myself.minimap == TRUE)
		global->myself.minimap = FALSE;
	return (0);
}

int	key_hook_release(int key, t_global *global)
{
	if (key == 119)
		global->myself.w_press = FALSE;
	if (key == 115)
		global->myself.s_press = FALSE;
	if (key == 97)
		global->myself.a_press = FALSE;
	if (key == 100)
		global->myself.d_press = FALSE;
	if (key == 65363)
		global->myself.right_press = FALSE;
	if (key == 65361)
		global->myself.left_press = FALSE;
	return (0);
}

int	mouse_hook(int key, int x, int y, t_global *global)
{
	(void)x, (void)y;
	if (key == 5 && global->myself.fov_ratio <= 3)
		global->myself.fov_ratio *= 1.3;
	if (key == 4 && global->myself.fov_ratio >= 0.3)
		global->myself.fov_ratio /= 1.3;
	if (key == 2)
		global->myself.fov_ratio = FOV_RATIO;
	return (0);
}

int	destroy_hook(t_global *global)
{
	((t_xvar *)(global->mlx))->end_loop = 1;
	return (0);
}
