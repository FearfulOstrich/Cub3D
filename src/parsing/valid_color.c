/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:23:53 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/23 10:47:58 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	valid_color(t_color color)
{
	if (color.r > 255 || color.r < 0)
		return (FALSE);
	if (color.g > 255 || color.g < 0)
		return (FALSE);
	if (color.b > 255 || color.b < 0)
		return (FALSE);
	return (TRUE);
}
