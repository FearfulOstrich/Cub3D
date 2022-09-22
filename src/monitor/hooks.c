/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <jbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:41:36 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/22 15:52:31 by jbouyer          ###   ########.fr       */
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

int	mouse_hook(int key, t_global *global)
{
	(void)global;
	printf("%d\n", key);
	return (0);
}

int	destroy_hook(t_global *global)
{
	((t_xvar *)(global->mlx))->end_loop = 1;
	return (0);
}
