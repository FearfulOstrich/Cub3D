/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:01:34 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/13 17:52:22 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	get_dX0(t_character me, t_vector ray)
{
	float	dx;

	if (ray.x == 0.0)
		return (v_create(0.0, INFINITY));
	else if (ray.x > 0.0)
		dx = ceil(me.position.x) - me.position.x;
	else if (ray.x < 0.0)
		dx = floor(me.position.x) - me.position.x;
	return (v_scale(ray, dx / ray.x));
}

t_vector	get_dX(t_character me, t_vector ray)
{
	if (ray.x == 0)
		return (v_create(0.0, INFINITY))
	return (v_scale(ray, 1 / fabs(ray.x)));
}

t_vector	get_dY0(t_character me, t_vector ray)
{
	float	dy;

	if (ray.y == 0.0)
		return (v_create(INFINITY, 0.0));
	else if (ray.y > 0.0)
		dy = ceil(me.position.y) - me.position.y;
	else if (ray.y < 0.0)
		dy = floor(me.position.y) - me.position.y;
	return (v_scale(ray, dy / ray.y));
}

t_vector	get_dX(t_character me, t_vector ray)
{
	if (ray.x == 0)
		return (v_create(0.0, INFINITY))
	return (v_scale(ray, 1 / abs(ray.x)));
}

t_RC	init_RC_env(t_character me, int s)
{
	t_RC	env;

	env.camX = (2 * (float)(s) / RC_STEPS) - 1;
	env.ray = v_add(me.dir, v_scale(me.plane, me.FOV_ratio * s)
	env.dx0 = get_dX0(me, env.ray);
	env.dx0 = get_dX(me, env.ray);
	env.dy0 = get_dY0(me, env.ray);
	env.dy0 = get_dY(me, env.ray);

	return (env);
}
