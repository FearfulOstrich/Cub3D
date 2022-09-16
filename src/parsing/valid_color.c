/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:23:53 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/15 13:41:03 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	valid_color(t_color color)
{
	if (color.R > 255 || color.R < 0)
		return (0);
	if (color.G > 255 || color.G < 0)
		return (0);
	if (color.B > 255 || color.B < 0)
		return (0);
	return (1);
}
