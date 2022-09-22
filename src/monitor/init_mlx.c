/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <jbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:28:29 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/22 12:36:34 by jbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_init_win_img(t_global *env)
{
	env->win = mlx_new_window(env->mlx, WIN_W, WIN_H, "cub3D");
	if (!env->win)
		return ;
	env->img = mlx_new_image(env->mlx, WIN_W, WIN_H);
	return ;
}

t_bool	init_mlx(t_global *global)
{
	global->mlx = NULL;
	global->win = NULL;
	global->img = NULL;
	global->mlx = mlx_init();
	if (global->mlx == NULL)
		return (FALSE);
	ft_init_win_img(global);
	if (global->win == NULL || global->img == NULL)
		return (FALSE);
	return (TRUE);
}
