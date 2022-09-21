/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <jbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:50:08 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/21 15:56:51 by jbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H_
# define _CUB3D_H_

# include <stdio.h>
# include "mlx.h"
# include "mlx_int.h"
# include "libft.h"
# include "math.h"
# include "libft.h"

// boolean constants
# define TRUE	1
# define FALSE	0
// Image dimensions constants
# define WIN_H		576
# define WIN_W		1024
# define MINIMAP_H	100
# define MINIMAP_W	150
// Rendering constants
# define UNIT_SIZE	64
# define FOV_RATIO	0.66
# define HEIGHT_MOD	1
// Hook constants
# define ON_KEYPRESS	2
# define ON_KEYRELEASE	3
# define ON_MOUSEDOWN	4
# define ON_DESTROY		17
# define PI	3.14159265358

typedef struct s_pos
{
	unsigned int	x;
	unsigned int	y;
}	t_pos;

typedef struct s_vector
{
	float	x;
	float	y;
}	t_vector;

typedef struct s_pos
{
	unsigned int	x;
	unsigned int	y;
}	t_pos;

typedef struct s_color
{
	char	*input;
	int		R;
	int		G;
	int		B;
	t_bool	set;
}	t_color;

// typedef char*	t_texture;
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
	char			**map;
	t_texture		NO;
	t_texture		SO;
	t_texture		WE;
	t_texture		EA;
	t_color			floor;
	t_color			ceiling;
}	t_env;

typedef struct s_character
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	float		FOV_ratio;
	t_bool		w_press;
	t_bool		a_press;
	t_bool		s_press;
	t_bool		d_press;
	t_bool		right_press;
	t_bool		left_press;
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
	int			s;
	t_edge		wall;
	int			wall_height;
}	t_RC;

typedef struct s_edge
{
	t_vector		v_edge;
	t_bool			horizontal;
	unsigned int	c_x;
	unsigned int	c_y;
}	t_edge;

// Parsing
t_bool	valid_map(t_env env);
t_bool	valid_color(t_color color);
t_bool	valid_texture(t_texture *texture, void *mlx);
t_bool	set_color(t_color *color);
t_bool	get_path(char *tmp, char *str, char **dest);
t_bool	is_line_empty(char *str);
t_bool	params_all_set(t_env env);
t_bool	map_error(void);
t_bool	create_env(int fd, t_env *env);
t_bool	validate_env(t_env *env, void *mlx);
t_bool	parse_file(char *fname, t_global *global);

// Window monitoring
void	mini_map(t_global *env);
void	draw_background(t_global *env);
t_bool	init_mlx(t_global *global);
t_b=======
/*   Updated: 2022/09/21 14:29:28 by aalleon          ###   ########.fr       */
>>>>>>> a2907cdad90fcf37a289fd239cee092ccd92fc71
ector	v_add(t_vector v1, t_vector v2);
t_vector	v_scale(t_vector v, float alpha);
t_vector	v_rotate(t_vector v, int angle);

//Debug utils
void	show_env(t_env env);

// Draw utils
void	pixel_put(t_img *img, int x, int y, int color);

// mem utils
void    clean_global(t_global *global);
#endif
