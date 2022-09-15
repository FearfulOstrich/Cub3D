/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:50:08 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/15 11:41:13 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H_
# define _CUB3D_H_

# include <stdio.h>
#include "libft.h"

typedef struct s_vector
{
	float	x;
	float	y;
}	t_vector;

typedef struct s_color
{
	unsigned char	R;
	unsigned char	G;
	unsigned char	B;
}	t_color;

typedef struct s_texture
{
	char	*path;
	int		width;
	int		height;
	t_img	*img;
}	t_texture;

typedef struct s_map
{
	unsigned int	height;
	unsigned int	length;
	char			**map;
}	t_map;

typedef struct s_character
{
	t_vector	position;
	t_vector	direction;
	float		camera_ratio;
}	t_character;

typedef struct s_global
{
	t_map		*map;
	t_character	*pov;
}	t_global;

// Parsing
t_bool	valid_map(t_map map);
t_bool	valid_color(t_color color);
t_bool	valid_texture(char *text_path);

#endif
