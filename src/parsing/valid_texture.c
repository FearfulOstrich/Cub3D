/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <jbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:41:49 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/22 12:32:16 by jbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	valid_texture(t_texture *texture, void *mlx)
{
	texture->img = mlx_xpm_file_to_image(mlx, texture->path, \
										&texture->width, &texture->height);
	if (texture->img == NULL)
		return (FALSE);
	return (TRUE);
}
