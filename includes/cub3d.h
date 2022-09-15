/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <jbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:50:08 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/15 15:02:39 by jbouyer          ###   ########.fr       */
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
	int	R;
	int	G;
	int	B;
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
	t_color		floor;
	t_color		ceiling;
	t_texture	NO;
	t_texture	SO;
	t_texture	WE;
	t_texture	EA;
	t_env		env;
	t_character	*myself;
	void		*mlx;
	void		*win;
	t_img		*img;
}	t_global;

// Parsing
t_bool	valid_map(t_map map);
t_bool	valid_color(t_color color);
t_bool	valid_texture(char *text_path);

#endif
