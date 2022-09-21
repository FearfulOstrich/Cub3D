/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_distance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:32:38 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/21 13:36:01 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	compute_distance(t_RC tools_RC, t_vector dir)
{
	float	cos_theta;

	cos_theta = v_dot_product(tools_RC.ray, dir) / v_norm(tools_RC.ray);
	return (v_norm(tools_RC.wall.v_edge) * cos_theta);
}
