/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_distance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:32:38 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/22 12:46:41 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	compute_distance(t_RC tools_RC, t_vector dir)
{
	float	cos_theta;
	float	distance;

	cos_theta = v_dot_product(tools_RC.ray, dir);
	// cos_theta /= v_norm(tools_RC.ray);
	// cos_theta /= v_norm(dir);
	distance = v_norm(tools_RC.wall.v_edge) * cos_theta;
	if (distance < 0.05)
		distance = 0.05;
	return (distance);
}
