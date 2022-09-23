/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:01:34 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/23 10:53:12 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	get_dx0(t_character me, t_vector ray)
{
	float	dx;

	dx = 0.0;
	if (ray.x == 0.0)
		return (v_create(0.0, INFINITY));
	else if (ray.x > 0.0)
		dx = ceil(me.pos.x) - me.pos.x;
	else if (ray.x < 0.0)
		dx = floor(me.pos.x) - me.pos.x;
	return (v_scale(ray, dx / ray.x));
}

t_vector	get_dx(t_vector ray)
{
	if (ray.x == 0)
		return (v_create(0.0, INFINITY));
	return (v_scale(ray, 1 / fabs(ray.x)));
}

t_vector	get_dy0(t_character me, t_vector ray)
{
	float	dy;

	dy = 0.0;
	if (ray.y == 0.0)
		return (v_create(INFINITY, 0.0));
	else if (ray.y > 0.0)
		dy = ceil(me.pos.y) - me.pos.y;
	else if (ray.y < 0.0)
		dy = floor(me.pos.y) - me.pos.y;
	return (v_scale(ray, dy / ray.y));
}

t_vector	get_dy(t_vector ray)
{
	if (ray.x == 0)
		return (v_create(0.0, INFINITY));
	return (v_scale(ray, 1 / fabs(ray.y)));
}

t_raycast	init_rc_env(t_character me, int s)
{
	t_raycast	env;

	env.cam_x = (2 * (float)(s) / (WIN_W - 1)) - 1;
	env.ray = v_add(me.dir, v_scale(me.plane, me.fov_ratio * env.cam_x));
	env.dx0 = get_dx0(me, env.ray);
	env.dx = get_dx(env.ray);
	env.dy0 = get_dy0(me, env.ray);
	env.dy = get_dy(env.ray);
	env.s = s;
	return (env);
}
