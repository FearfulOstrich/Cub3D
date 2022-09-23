/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:20:41 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/23 10:47:09 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_vector	get_dir_vector(char c)
{
	t_vector	dir;

	dir.x = 0;
	dir.y = 0;
	if (c == 'N')
		dir.y = -1;
	else if (c == 'S')
		dir.y = 1;
	else if (c == 'W')
		dir.x = -1;
	else
		dir.x = 1;
	return (dir);
}

static t_bool	is_pos(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (TRUE);
	return (FALSE);
}

t_bool	init_vectors(t_character *myself, t_env env)
{
	unsigned int	i;
	unsigned int	j;
	t_bool			set_pos;

	set_pos = FALSE;
	j = -1;
	while (++j < env.height)
	{
		i = -1;
		while (++i < ft_strlen(env.map[j]))
		{
			if (is_pos(env.map[j][i]) == TRUE)
			{
				if (set_pos == TRUE)
					return (FALSE);
				myself->pos.x = (float)i + 0.5;
				myself->pos.y = (float)j + 0.5;
				myself->dir = get_dir_vector(env.map[j][i]);
				set_pos = TRUE;
			}
		}
	}
	if (set_pos == FALSE)
		return (FALSE);
	return (TRUE);
}

t_bool	init_character(t_global *global)
{
	t_character	myself;

	if (init_vectors(&myself, global->env) == FALSE)
		return (map_error());
	myself.plane = v_rotate(myself.dir, 90);
	myself.fov_ratio = FOV_RATIO;
	myself.w_press = FALSE;
	myself.a_press = FALSE;
	myself.s_press = FALSE;
	myself.d_press = FALSE;
	myself.right_press = FALSE;
	myself.left_press = FALSE;
	myself.minimap = FALSE;
	global->myself = myself;
	return (TRUE);
}
