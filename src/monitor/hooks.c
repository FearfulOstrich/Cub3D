/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:41:36 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/22 15:28:16 by aalleon          ###   ########.fr       */
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
	printf("In mouse hook: %d\n", key);
	printf("\tFOV ratio address: %p\n", global);
	printf("current FOV ratio: %f\n", global->myself.FOV_ratio);
	return (0);
}

// int	mouse_hook(int key, t_global *global)
// {
// 	printf("currect FOV ratio: %f", global->myself.FOV_ratio);
// 	if (key == 5 && global->myself.FOV_ratio <= 3)
// 	{
// 		printf("Zoom out.");
// 		global->myself.FOV_ratio *= 1.3;
// 	}
// 	if (key == 4 && global->myself.FOV_ratio >= 0.3)
// 	{
// 		global->myself.FOV_ratio /= 1.3;
// 		printf("Zoom in");
// 	}
// 	return (0);
// }

int	destroy_hook(t_global *global)
{
	((t_xvar *)(global->mlx))->end_loop = 1;
	return (0);
}
