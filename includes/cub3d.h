/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:50:08 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/16 10:37:36 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H_
# define _CUB3D_H_

# include <stdio.h>
# include "mlx.h"
# include "mlx_int.h"
# include "libft.h"
# include "math.h"
#include "libft.h"

# define WIN_H		576
# define WIN_W		1024
# define UNIT_SIZE	64
# define FOV_RATIO	0.66
// Hook constants
# define ON_KEYDOWN		2
# define ON_MOUSEDOWN	4
# define ON_DESTROY		17

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

typedef struct s_env
{
	unsigned int	height;
	unsigned int	length;
	char			**map;
}	t_env;

typedef struct s_character
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	float		FOV_ratio;
}	t_character;

typedef struct s_global
{
	t_env		env;
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
	t_vector		v_edge;
	t_bool			horizontal;
	unsigned int	c_x;
	unsigned int	c_y;
}	t_edge;


// Window monitoring
t_bool  init_global_env(t_global *env);
void    del_global_env(t_global *env);
t_bool  monitor_env(t_global *env);
//// hooks
int	key_hook(int key, t_global	*global);
int	mouse_hook(int key, t_global	*global);
int	destroy_hook(t_global *global);

// Raycasting
t_RC		init_RC_env(t_character me, int s);
t_edge		find_wall(t_vector pos, t_RC tools_RC, t_env map);


// Vector utils
t_vector	v_create(float x, float y);
float		v_norm(t_vector v);
t_vector	v_add(t_vector v1, t_vector v2);
t_vector	v_scale(t_vector v, float alpha);

// Parsing
t_bool	valid_map(t_env map);
t_bool	valid_color(t_color color);
t_bool	valid_texture(char *text_path);

#endif
