/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:44:03 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/21 16:24:15 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	v_create(float x, float y)
{
	t_vector	res;

	res.x = x;
	res.y = y;
	return (res);
}

float	v_norm(t_vector v)
{
	float	res;

	res = v.x * v.x + v.y * v.y;
	res = sqrt(res);
	return (res);
}

t_vector	v_add(t_vector v1, t_vector v2)
{
	t_vector	res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	return (res);
}

t_vector	v_scale(t_vector v, float alpha)
{
	t_vector	res;

	res.x = alpha * v.x;
	res.y = alpha * v.y;
	return (res);
}

// angle in degrees
t_vector	v_rotate(t_vector v, int angle)
{
	t_vector	res;
	float		rad_angle;

	rad_angle = PI * angle * 2.0 / 360.0;
	res.x = v.x * cos(rad_angle) + v.y * (-sin(rad_angle));
	res.y = v.x * sin(rad_angle) + v.y * cos(rad_angle);
	return (res);
}
