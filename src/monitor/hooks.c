/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <jbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:41:36 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/16 15:08:24 by jbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int key, t_global *global)
{
	if (key == 65307)
		((t_xvar *)(global->mlx))->end_loop = 1;
	if (key == 119)
		global->myself->pos = v_add(global->myself->dir, global->myself->pos);
	if (key == 115)
		global->myself->pos = v_add(global->myself->pos, v_scale(global->myself->dir, -1));
	if (key == 97)
	{
		global->myself->dir = v_rotate(global->myself->dir, -90);
		global->myself->pos = v_add(global->myself->dir, global->myself->pos);
	}
	if (key == 100)
	{
		global->myself->dir = v_rotate(global->myself->dir, 90);
		global->myself->pos = v_add(global->myself->dir, global->myself->pos);
	}
	if (key == 65363)
		global->myself->dir = v_rotate(global->myself->dir,  1); //changer ici la valeur du 1 par je ne sais quoi 
	if (key == 65361)
		global->myself->dir = v_rotate(global->myself->dir, 1); //changer ici la valeur du 1 par je ne sais quoi.
	else
		printf("%d\n", key);
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
	del_global_env(global);
	return (0);
}
