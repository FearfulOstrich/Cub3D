/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <jbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:50:08 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/13 15:10:28 by jbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H_
# define _CUB3D_H_

# include <stdio.h>
# include	<stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

// # define NO 0;
// # define SO 1;
// # define WE 2;
// # define EA 3;

// textures[NO]

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

typedef	char*	t_texture;

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
	t_color		floor;
	t_color		ceiling;
	t_texture	NO;
	t_texture	SO;
	t_texture	WE;
	t_texture	EA;

}	t_global;

#endif
