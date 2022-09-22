/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <jbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:32:02 by jbouyer           #+#    #+#             */
/*   Updated: 2022/09/22 11:30:04 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

static t_bool	is_wall(t_vector pos, char **map)
{
	unsigned int	y;
	unsigned int	x;

	y = floor(pos.y);
	x = floor(pos.x);
	if (map[y][x] == '1')
		return (TRUE);
	return (FALSE);
}

static t_bool	is_feasible(t_vector pos, t_global *global)
{
	unsigned int	theta;
	t_vector		dv;

	theta = 0;
	while (theta < 360)
	{
		dv = v_scale(v_rotate(v_create(1, 0), theta), SAFE_RADIUS);
		if (is_wall(v_add(pos, dv), global->env.map) == TRUE)
			return (FALSE);
		theta += 5;
	}
	return (TRUE);
}

static t_vector	get_new_pos(t_vector step, t_global *global)
{
	t_vector	new_pos;

	new_pos = v_add(global->myself.pos, step);
	if (is_feasible(new_pos, global) == TRUE)
		return (new_pos);
	return (global->myself.pos);
}

void	update_pos(t_global *global)
{
	t_vector	direction;

	if (global->myself.w_press == TRUE && global->myself.a_press == FALSE)
	{
		direction = v_scale(global->myself.dir, TRANS_SPEED);
		global->myself.pos = get_new_pos(direction, global);
	}
	if (global->myself.a_press == TRUE && global->myself.w_press == FALSE)
	{
		direction = v_scale(v_rotate(global->myself.dir, -90), TRANS_SPEED);
		global->myself.pos = get_new_pos(direction, global);
	}
	if (global->myself.s_press == TRUE && global->myself.d_press == FALSE)
	{
		direction = v_scale(v_scale(global->myself.dir, -1), TRANS_SPEED);
		global->myself.pos = get_new_pos(direction, global);
	}
	if (global->myself.d_press == TRUE && global->myself.s_press == FALSE)
	{
		direction = v_scale(v_rotate(global->myself.dir, 90), TRANS_SPEED);
		global->myself.pos = get_new_pos(direction, global);
	}
}


void	update_dir(t_global *global)
{
	if (global->myself.right_press == TRUE)
		global->myself.dir = v_rotate(global->myself.dir,  ROT_SPEED);
	if (global->myself.left_press == TRUE)
		global->myself.dir = v_rotate(global->myself.dir, -ROT_SPEED);
}
