/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:38:55 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/19 12:14:16 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_global(t_global *global)
{
	global->env.NO.path = NULL;
	global->env.SO.path = NULL;
	global->env.WE.path = NULL;
	global->env.EA.path = NULL;
	global->env->floor->set = 0;
	global->env->ceiling->set = 0;
}

int	main(int argc, char *argv[])
{
	t_global	global;

	if (argc < 2 || argc > 3)
		return (print_error("cub3D takes only one argument.\n"), 1);
	init_global(&global);
	if (parse_file(argv[1], &global) == 0)
		return (print_error("Error.\n"), 2);
	if (init_character(&global) == 0)
		return (print("Error.\n"), 3);
	if (monitor(&global) == 0)
		return (print("Error.\n"), 4);
	destroy_global(global);
	return (0);
}
