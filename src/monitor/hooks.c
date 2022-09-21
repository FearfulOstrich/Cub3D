/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <jbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:41:36 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/21 17:05:48 by jbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook_press(int key, t_global *global)
{
	if (key == 119)
		global->myself->w_press = TRUE;
	if (key == 115)
		global->myself->s_press = TRUE;
	if (key == 97)
		global->myself->a_press = TRUE;
	if (key == 100)
		global->myself->d_press = TRUE;
	if (key == 65363)
		global->myself->right_press = TRUE;
	if (key == 65361)
		global->myself->left_press = TRUE;
	return (0);
}

int	key_hook_release(int key, t_global *global)
{
	if (key == 119)
		global->myself->w_press = FALSE;
	if (key == 115)
		global->myself->s_press = FALSE;
	if (key == 97)
		global->myself->a_press = FALSE;
	if (key == 100)
		global->myself->d_press = FALSE;
	if (key == 65363)
		global->myself->right_press = FALSE;
	if (key == 65361)
		global->myself->left_press = FALSE;
	return (0);
}
/* Key codes
W -> 119
A -> 97
S -> 115
D -> 100

right arrow -> 65363
left arrow -> 65361

M -> 109
*/

int	mouse_hook(int key, t_global *global)
{
	(void)global;
	printf("%d\n", key);
	return (0);
}

/* Mouse codes
Scroll up -> 4
Scroll down -> 5
*/

int	destroy_hook(t_global *global)
{
	(void)global;
	printf("TODO: Destroy hook.\n");
	// del_global_env(global);
	return (0);
}
