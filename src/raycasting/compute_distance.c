/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_distance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:32:38 by aalleon           #+#    #+#             */
/*   Updated: 2022/09/21 09:29:56 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	compute_distance(t_RC tools_RC, t_vector dir)
{
	float	cos_theta;

	cos_theta = v_dot_product(tools_RC.ray, dir);
	return (v_norm(tools_RC.wall.v_edge) * cos_theta);
}