/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:38:55 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/20 13:00:37 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Init all variables that will be malloc and set flag for colors.
static void	init_global(t_global *global)
{
	global->mlx = NULL;
	global->win = NULL;
	global->img = NULL;
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
}

int	main(int argc, char *argv[])
{
	t_global	global;

	if (argc < 2 || argc > 3)
		return (ft_putstr_fd("cub3D takes only one argument.\n", 1), 1);
	init_global(&global);
	if (parse_file(argv[1], &global) == FALSE)
		return (clean_global(&global), 2);
	show_env(global.env);
	/*if (init_character(&global) == 0)
		return (print("Error.\n"), 3);
	if (monitor(&global) == 0)
		return (print("Error.\n"), 4);*/
	clean_global(&global);
	return (0);
}
