/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:28:29 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/14 16:51:21 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_init_win_img(t_global *env)
{
	env->win = mlx_new_window(env->mlx, WIN_W, WIN_H, "cub3D");
	if (!env->win)
	return ;
	env->img = mlx_new_image(env->mlx, WIN_W, WIN_H);
	return ;
}

t_bool  init_global_env(t_global *env)
{
	env->mlx = NULL;
	env->win = NULL;
	env->img = NULL;
	env->mlx = mlx_init();
	if (env->mlx == NULL)
		return (0);
	ft_init_win_img(env);
	if (env->win == NULL || env->img == NULL)
		return (0);
	return (1);
}
