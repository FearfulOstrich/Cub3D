/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:38:55 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/22 08:59:36 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Init all variables that will be malloc and set flag for colors.
static t_bool	init_global(t_global *global)
{
	global->env.map = ft_calloc(1, sizeof(*(global->env.map)));
	global->env.NO.path = NULL;
	global->env.NO.img = NULL;
	global->env.SO.path = NULL;
	global->env.SO.img = NULL;
	global->env.WE.path = NULL;
	global->env.WE.img = NULL;
	global->env.EA.path = NULL;
	global->env.EA.img = NULL;
	global->env.floor.input = NULL;
	global->env.floor.set = FALSE;
	global->env.ceiling.input = NULL;
	global->env.ceiling.set = FALSE;
	if (init_mlx(global) == FALSE)
		return (FALSE);
	global->counter = 0;
	return (TRUE);
}

int	main(int argc, char *argv[])
{
	t_global	global;

	if (argc < 2 || argc > 3)
		return (ft_putstr_fd("cub3D takes only one argument.\n", 1), 1);
	if (init_global(&global) == FALSE)
		return (clean_global(&global), 2);
	if (parse_file(argv[1], &global) == FALSE)
		return (clean_global(&global), 3);
	show_env(global.env);
	if (init_character(&global) == FALSE)
		return (clean_global(&global), 4);
	show_character(global.myself);
	if (monitor(&global) == FALSE)
		return (clean_global(&global), 5);
	clean_global(&global);
	return (0);
}
