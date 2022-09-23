/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:38:55 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/23 11:01:35 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Init all variables that will be malloc and set flag for colors.
static t_bool	init_global(t_global *global)
{
	global->env.map = ft_calloc(1, sizeof(*(global->env.map)));
	global->env.no.path = NULL;
	global->env.no.img = NULL;
	global->env.so.path = NULL;
	global->env.so.img = NULL;
	global->env.we.path = NULL;
	global->env.we.img = NULL;
	global->env.ea.path = NULL;
	global->env.ea.img = NULL;
	global->env.floor.input = NULL;
	global->env.floor.set = FALSE;
	global->env.ceiling.input = NULL;
	global->env.ceiling.set = FALSE;
	global->mlx = mlx_init();
	if (global->mlx == NULL)
		return (FALSE);
	global->img = NULL;
	global->win = NULL;
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
	if (init_character(&global) == FALSE)
		return (clean_global(&global), 4);
	if (init_mlx(&global) == FALSE)
		return (clean_global(&global), 5);
	if (monitor(&global) == FALSE)
		return (clean_global(&global), 6);
	clean_global(&global);
	return (0);
}
