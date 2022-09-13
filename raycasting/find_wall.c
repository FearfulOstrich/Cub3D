/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:21:45 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/13 18:03:20 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	init_edge(t_RC env)
{
	t_edge	edge;

	if (v_norm(env.dx0) > v_norm(env.dY0))
	{
		edge.v_edge = env.dY0;
		edge.horizontal = 1;
	}
	else
	{
		edge.v_edge = env.dX0;
		edge.horizontal = 0;
	}
	return (edge);
}

t_bool	is_wall(t_vector pos, t_edge edge, t_map map)
{
	int	ix_x;
	int	ix_y;

	if (edge.horizontal)
	{
		ix_x = floor(v_add(pos, edge.v_edge).x);
		if (v_edge.y < 0)
			ix_y = round(v_add(pos, edge.v_edge).y) - 1;
		else
			ix_y = round(v_add(pos, edge.v_edge).y);
	}
	else
	{
		ix_y = floor(v_add(pos, edge.v_edge).y);
		if (v_edge.x > 0)
			ix_x = round(v_add(pos, edge.v_edge).x);
		else
			ix_x = round(v_add(pos, edge.v_edge).x) - 1;
	}
	if (map.map[ix_y][ix_x] == '1')
		return (1);
	return (0);
}

t_edge	find_wall(t_vector pos, t_RC env, t_map map)
{
	t_edge	edge;

	edge = init_edge(env);
	while (1)
	{
		if (is_wall(pos, edge, map))
			return (edge);
		edge = update_edge(edge, env);
	}
}
