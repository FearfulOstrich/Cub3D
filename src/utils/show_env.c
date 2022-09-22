/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <jbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:16:33 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/22 12:31:10 by jbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	show_env(t_env	env)
{
	unsigned int	i;

	printf("NO texture path: %s\n", env.NO.path);
	printf("SO texture path: %s\n", env.SO.path);
	printf("WE texture path: %s\n", env.WE.path);
	printf("EA texture path: %s\n", env.EA.path);
	printf("Floor color: (%d, %d, %d)\n", \
		env.floor.R, env.floor.G, env.floor.B);
	printf("Ceiling color: (%d, %d, %d) \n ", \
		env.ceiling.R, env.ceiling.G, env.ceiling.B);
	i = -1;
	printf("map:\n");
	if (env.map != NULL)
		while (++i < ft_tab_len(env.map))
			printf("%s\n", env.map[i]);
	return ;
}
