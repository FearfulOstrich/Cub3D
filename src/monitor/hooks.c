/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <jbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:41:36 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/21 16:37:44 by jbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook_press(int key, t_global *global)
{
	if (key == 119)
		global->character.w_press = TRUE;
	if (key == 115)
		global->character.s_press = TRUE;
	if (key == 97)
		global->character.a_press = TRUE;
	if (key == 100)
		global->character.d_press = TRUE;
	if (key == 65363)
		global->character.right_press = TRUE;
	if (key == 65361)
		global->character.left_press = TRUE;
	return (0);
}

int	key_hook_release(int key, t_global *global)
{
	if (key == 119)
		global->character.w_press = FALSE;
	if (key == 115)
		global->character.s_press = FALSE;
	if (key == 97)
		global->character.a_press = FALSE;
	if (key == 100)
		global->character.d_press = FALSE;
	if (key == 65363)
		global->character.right_press = FALSE;
	if (key == 65361)
		global->character.left_press = FALSE;
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
