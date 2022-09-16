/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:51:04 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/14 16:54:18 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    del_global_env(t_global *env)
{
	if (env->img != NULL)
		mlx_destroy_image(env->mlx, env->img);
	if (env->win != NULL)
		mlx_destroy_window(env->mlx, env->win);
	if (env->mlx != NULL)
	{
		mlx_destroy_display(env->mlx);
		free(env->mlx);
	}
	return ;
}
