/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:42:42 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/13 17:33:24 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	draw(t_global	*global)
{
	int			s;
	t_vector	wall;
	t_RC		env_RC;

	s = -1;
	while (++s < RC_STEPS + 1)
	{
		env_RC = init_RC_env(*(global->myself), s);
		wall = find_wall(global->position, env_RC, global->map);
	}
}
