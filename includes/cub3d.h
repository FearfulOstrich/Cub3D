/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:50:08 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/13 17:57:02 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H_
# define _CUB3D_H_

# include <stdio.h>
# include "mlx.h"
# include "mlx_int.h"
# include "libft.h"
# include "math.h"

# define RC_STEPS	100;

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
	t_vector	plane;
	float		FOV_ratio;
}	t_character;

typedef struct s_global
{
	t_map		*map;
	t_character	*myself;
	void		*mlx;
	void		*win;
	t_img		*img;
}	t_global;

typedef struct s_RC
{
	float		camX;
	t_vector	ray;
	t_vector	dx0;
	t_vector	dx;
	t_vector	dy0;
	t_vector	dy;
}	t_RC;

typedef struct s_edge
{
	t_vector	v_edge;
	t_bool		horizontal;
}	t_edge;

#endif
