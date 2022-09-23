/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:01:35 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/23 10:51:07 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_texture_color(t_texture texture, float h_ratio, float w_ratio)
{
	char	*pix;
	t_pos	pix_pos;

	pix_pos.x = texture.img->width * w_ratio;
	pix_pos.y = texture.img->height * (0.5 + h_ratio);
	pix = texture.img->data;
	pix += pix_pos.y * texture.img->size_line;
	pix += pix_pos.x * (texture.img->bpp / 8);
	return (*(int *)pix);
}

static t_texture	get_texture(t_raycast tools_rc, t_global *global)
{
	if (tools_rc.wall.horizontal)
	{
		if (tools_rc.ray.y < 0)
			return (global->env.so);
		else
			return (global->env.no);
	}
	if (tools_rc.ray.x > 0)
		return (global->env.we);
	return (global->env.ea);
}

static float	get_w_ratio(t_raycast tools_rc, t_global *global)
{
	t_vector	wall_pos;

	wall_pos = v_add(global->myself.pos, tools_rc.wall.v_edge);
	if (tools_rc.wall.horizontal)
	{
		if (tools_rc.ray.y < 0)
			return (wall_pos.x - floor(wall_pos.x));
		else
			return (1.0 - (wall_pos.x - floor(wall_pos.x)));
	}
	if (tools_rc.ray.x > 0)
		return (wall_pos.y - floor(wall_pos.y));
	return (1 - (wall_pos.y - floor(wall_pos.y)));
}

static void	draw_texture_pixel(int h, t_raycast tools_rc, t_global *global)
{
	t_texture	texture;
	float		h_ratio;
	float		w_ratio;
	int			pix_color;

	h_ratio = ((float)h) / tools_rc.wall_height;
	w_ratio = get_w_ratio(tools_rc, global);
	texture = get_texture(tools_rc, global);
	pix_color = get_texture_color(texture, h_ratio, w_ratio);
	if (h < WIN_H / 2 && h >= -WIN_H / 2)
		pixel_put(global->img, tools_rc.s, (WIN_H / 2) + h, pix_color);
	return ;
}

void	draw_column(t_raycast tools_rc, t_global *global)
{
	float	distance;
	int		i;

	distance = compute_distance(tools_rc, global->myself.dir);
	tools_rc.wall_height = (WIN_H / distance) * \
							(FOV_RATIO / global->myself.fov_ratio);
	i = (-tools_rc.wall_height / 2) - 1;
	while (++i < tools_rc.wall_height / 2)
		draw_texture_pixel(i, tools_rc, global);
}
