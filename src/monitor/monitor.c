/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:40:32 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/14 17:07:07 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool  monitor_env(t_global *env)
{
	mlx_hook(env->win, ON_KEYDOWN, 1L << 0, key_hook, env);
	mlx_hook(env->win, ON_MOUSEDOWN, 1L << 2, mouse_hook, env);
	mlx_hook(env->win, ON_DESTROY, 0L, destroy_hook, env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_loop(env->mlx);
	return (1);
}
