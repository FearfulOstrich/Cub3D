/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <jbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:32:02 by jbouyer           #+#    #+#             */
/*   Updated: 2022/09/21 16:50:32 by jbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	update_pos(t_global *global)
{
	t_vector	direction;

	if (global->character.w_press == TRUE)
	{
		direction = v_scale(global->myself->dir, TRANS_SPEED);
		global->myself->pos = v_add(global->myself->pos, direction);
	}
	if (global->character.a_press == TRUE)
	{
		direction = v_scale(v_rotate(global->myself->dir, -90), TRANS_SPEED);
		global->myself->pos = v_add(global->myself->pos, direction);
	}
	if (global->character.s_press == TRUE)
	{
		direction = v_scale(v_scale(global->myself->dir, -1), TRANS_SPEED);
		global->myself->pos = v_add(global->myself->pos, direction);
	}
	if (global->character.d_press == TRUE)
	{
		direction = v_scale(v_rotate(global->myself->dir, 90), TRANS_SPEED);
		global->myself->pos = v_add(global->myself->pos, direction);
	}
}


void	update_dir(t_global *global)
{
	if (global->character.right_press == TRUE)
		global->myself->dir = v_rotate(global->myself->dir,  ROT_SPEED);
	if (global->character.left_press == TRUE)
		global->myself->dir = v_rotate(global->myself->dir, ROT_SPEED);
}