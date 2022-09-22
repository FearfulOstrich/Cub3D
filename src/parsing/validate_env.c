/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <jbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:09:43 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/22 12:32:04 by jbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	validate_env(t_env *env, void *mlx)
{
	if (valid_texture(&env->NO, mlx) == FALSE || \
		valid_texture(&env->SO, mlx) == FALSE || \
		valid_texture(&env->WE, mlx) == FALSE || \
		valid_texture(&env->EA, mlx) == FALSE)
		return (ft_putstr_fd("ERROR\nINVALID TEXTURE.\n", 1), FALSE);
	if (valid_color(env->floor) == FALSE || valid_color(env->ceiling) == FALSE)
		return (ft_putstr_fd("ERROR\nINVALID COLOR.\n", 1), FALSE);
	env->height = ft_tab_len(env->map);
	if (valid_map(*env) == FALSE)
		return (ft_putstr_fd("ERROR\nINVALID MAP.\n", 1), FALSE);
	return (TRUE);
}
