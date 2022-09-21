/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:42:42 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/21 09:27:53 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_column(t_RC tools_RC, t_global *global)
{
	unsigned int	distance;
	unsigned int	height;

	distance = compute_distance(tools_RC, global->myself->dir);
	height = distance * something;

}

t_bool	draw_walls(t_global	*global)
{
	int			s;
	t_RC		tools_RC;

	s = -1;
	while (++s < WIN_W)
	{
		tools_RC = init_RC_env(*(global->myself), s);
		tools_RC.wall = find_wall(global->myself->pos, tools_RC, global->map);
		draw_column(tools_RC, global);
	}
}
