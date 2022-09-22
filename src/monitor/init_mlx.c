/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <jbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:28:29 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/22 17:03:09 by jbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	init_mlx(t_global *global)
{
	global->win = mlx_new_window(global->mlx, WIN_W, WIN_H, "cub3D");
	if (global->win == NULL)
		return (FALSE);
	global->img = mlx_new_image(global->mlx, WIN_W, WIN_H);
	if (global->img == NULL)
		return (FALSE);
	return (TRUE);
}
