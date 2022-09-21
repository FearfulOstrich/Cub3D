/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:30:43 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/21 16:51:54 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	show_character(t_character myself)
{
	printf("Hello !\n");
	printf("I'm positionned in (%f, %f)\n", myself.pos.x, myself.pos.y);
	printf("And i'm looking toward (%f, %f)\n", myself.dir.x, myself.dir.y);
	return ;
}
