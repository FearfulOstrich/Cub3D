/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <jbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:21:45 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/22 12:06:38 by jbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	update_edge(t_edge *edge, t_RC tools_RC)
{
	t_vector	next_x;
	t_vector	next_y;

	next_x = v_add(tools_RC.dx0, v_scale(tools_RC.dx, edge->c_x));
	next_y = v_add(tools_RC.dy0, v_scale(tools_RC.dy, edge->c_y));
	if (v_norm(next_x) > v_norm(next_y))
	{
		edge->v_edge = next_y;
		edge->horizontal = TRUE;
		edge->c_y++;
	}
	else
	{
		edge->v_edge = next_x;
		edge->horizontal = FALSE;
		edge->c_x++;
	}
	return ;
}

static t_bool	is_wall(t_vector pos, t_edge edge, t_env env)
{
	unsigned int	ix_x;
	unsigned int	ix_y;

	if (edge.horizontal)
	{
		ix_x = floor(v_add(pos, edge.v_edge).x);
		if (edge.v_edge.y < 0)
			ix_y = round(v_add(pos, edge.v_edge).y) - 1;
		else
			ix_y = round(v_add(pos, edge.v_edge).y);
	}
	else
	{
		ix_y = floor(v_add(pos, edge.v_edge).y);
		if (edge.v_edge.x > 0)
			ix_x = round(v_add(pos, edge.v_edge).x);
		else
			ix_x = round(v_add(pos, edge.v_edge).x) - 1;
	}
	if (env.map[ix_y][ix_x] == '1')
		return (TRUE);
	return (FALSE);
}

static t_edge	init_edge(t_RC tools_RC)
{
	t_edge	edge;

	edge.c_x = 0;
	edge.c_y = 0;
	if (v_norm(tools_RC.dx0) > v_norm(tools_RC.dy0))
	{
		edge.v_edge = tools_RC.dy0;
		edge.c_y++;
		edge.horizontal = TRUE;
	}
	else
	{
		edge.v_edge = tools_RC.dx0;
		edge.c_x++;
		edge.horizontal = FALSE;
	}
	return (edge);
}

t_edge	find_wall(t_vector pos, t_RC tools_RC, t_env env)
{
	t_edge			edge;

	edge = init_edge(tools_RC);
	while (1)
	{
		if (is_wall(pos, edge, env))
			return (edge);
		update_edge(&edge, tools_RC);
	}
}
