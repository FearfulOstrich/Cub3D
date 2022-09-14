/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:01:34 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/14 16:52:58 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	get_dX0(t_character me, t_vector ray)
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

t_vector	get_dX(t_vector ray)
{
	if (ray.x == 0)
		return (v_create(0.0, INFINITY));
	return (v_scale(ray, 1 / fabs(ray.x)));
}

t_vector	get_dY0(t_character me, t_vector ray)
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

t_vector	get_dY(t_vector ray)
{
	if (ray.x == 0)
		return (v_create(0.0, INFINITY));
	return (v_scale(ray, 1 / fabs(ray.y)));
}

t_RC	init_RC_env(t_character me, int s)
{
	t_RC	env;

	printf("Initializing ray.\n");
	env.camX = (2 * (float)(s) / (WIN_W - 1)) - 1;
	printf("camX: %f\n", env.camX);
	env.ray = v_add(me.dir, v_scale(me.plane, me.FOV_ratio * env.camX));
	printf("ray looking towards: ( %f, %f )\n", env.ray.x, env.ray.y);
	env.dx0 = get_dX0(me, env.ray);
	printf("To first constant X: (%f, %f).\n", env.dx0.x, env.dx0.y);
	env.dx = get_dX(env.ray);
	printf("To next X: (%f, %f).\n", env.dx.x, env.dx.y);
	env.dy0 = get_dY0(me, env.ray);
	printf("To first constant Y: (%f, %f).\n", env.dy0.x, env.dy0.y);
	env.dy = get_dY(env.ray);
	printf("To next Y: (%f, %f).\n", env.dy.x, env.dy.y);

	return (env);
}
