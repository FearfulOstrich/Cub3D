/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:42:42 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/23 10:37:41 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_walls(t_global *global)
{
	int			s;
	t_raycast	tools_rc;

	s = -1;
	while (++s < WIN_W)
	{
		tools_rc = init_rc_env(global->myself, s);
		tools_rc.wall = find_wall(global->myself.pos, tools_rc, global->env);
		draw_column(tools_rc, global);
	}
	return ;
}
