/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:23:53 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/20 14:12:28 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	valid_color(t_color color)
{
	if (color.R > 255 || color.R < 0)
		return (FALSE);
	if (color.G > 255 || color.G < 0)
		return (FALSE);
	if (color.B > 255 || color.B < 0)
		return (FALSE);
	return (TRUE);
}
