/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:41:49 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/15 12:07:02 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	valid_texture(t_texture *texture, t_global global)
{
	texture->img = mlx_xpm_file_to_image(global.mlx, texture->path,\
										&texture->width, &texture->height);
	if (texture->img == NULL)
		return (0);
	return (1);
}
