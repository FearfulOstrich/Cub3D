/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:51:08 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/20 14:19:36 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	parse_file(char *fname, t_global *global)
{
	int		fd;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (FALSE);
	if (create_env(fd, &global->env) == FALSE)
		return (FALSE);
	close(fd);
	if (validate_env(&global->env, global->mlx) == FALSE)
		return (FALSE);
	return (TRUE);
}
