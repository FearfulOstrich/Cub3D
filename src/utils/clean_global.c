/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_global.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <jbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:51:04 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/22 12:28:53 by jbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	clean_texture(t_texture *texture, void *mlx)
{
	if (texture->path != NULL)
		free(texture->path);
	if (texture->img != NULL)
		mlx_destroy_image(mlx, texture->img);
	return ;
}

static void	clean_env(t_env *env, void *mlx)
{
	if (env->map != NULL)
		ft_free_tab(env->map);
	clean_texture(&env->NO, mlx);
	clean_texture(&env->SO, mlx);
	clean_texture(&env->WE, mlx);
	clean_texture(&env->EA, mlx);
	if (env->floor.input != NULL)
		free(env->floor.input);
	if (env->ceiling.input != NULL)
		free(env->ceiling.input);
	return ;
}

void	clean_global(t_global *global)
{
	clean_env(&global->env, global->mlx);
	// clean_character();
	if (global->img != NULL)
		mlx_destroy_image(global->mlx, global->img);
	if (global->win != NULL)
		mlx_destroy_window(global->mlx, global->win);
	if (global->mlx != NULL)
	{
		mlx_destroy_display(global->mlx);
		free(global->mlx);
	}
	return ;
}
