/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:16:33 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/23 10:52:08 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	show_env(t_env	env)
{
	unsigned int	i;

	printf("NO texture path: %s\n", env.no.path);
	printf("SO texture path: %s\n", env.so.path);
	printf("WE texture path: %s\n", env.we.path);
	printf("EA texture path: %s\n", env.ea.path);
	printf("Floor color: (%d, %d, %d)\n", \
		env.floor.r, env.floor.g, env.floor.b);
	printf("Ceiling color: (%d, %d, %d) \n ", \
		env.ceiling.r, env.ceiling.g, env.ceiling.b);
	i = -1;
	printf("map:\n");
	if (env.map != NULL)
		while (++i < ft_tab_len(env.map))
			printf("%s\n", env.map[i]);
	return ;
}
