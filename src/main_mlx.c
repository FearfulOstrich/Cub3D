/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <jbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:46:35 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/22 12:21:42 by jbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	t_global	global_env;

	init_global_env(&global_env);
	global_env.myself = malloc(sizeof(t_character) * 1);
	global_env.myself->pos.x = 1;
	global_env.myself->pos.y = 1;
	global_env.myself->dir.x = 1;
	global_env.myself->dir.y = 0;
	monitor(&global_env);
	return (0);
}
