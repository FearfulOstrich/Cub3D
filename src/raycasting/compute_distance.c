/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_distance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:32:38 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/23 10:38:37 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	compute_distance(t_raycast tools_rc, t_vector dir)
{
	float	cos_theta;
	float	distance;

	cos_theta = v_dot_product(tools_rc.ray, dir);
	distance = v_norm(tools_rc.wall.v_edge) * cos_theta;
	if (distance < 0.05)
		distance = 0.05;
	return (distance);
}
