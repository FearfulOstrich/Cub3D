/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <jbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:42:42 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/21 17:11:53 by jbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_walls(t_global *global)
{
	int			s;
	t_RC		tools_RC;

	s = -1;
	while (++s < WIN_W)
	{
		tools_RC = init_RC_env(*(global->myself), s);
		tools_RC.wall = find_wall(global->myself->pos, tools_RC, global->env);
		draw_column(tools_RC, global);
	}
	return ;
}
