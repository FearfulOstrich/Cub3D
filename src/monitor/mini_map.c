/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <jbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:07:47 by jbouyer           #+#    #+#             */
/*   Updated: 2022/09/22 12:33:47 by jbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	mini_map(t_global *env)
// {
// 	t_img	*img;
// 	char	*grid[11] = {"1111111111",
// 			"1001010001",
// 			"1001010001",
// 			"1001010001",
// 			"1001010001",
// 			"1000000001",
// 			"1001010001",
// 			"1001000001",
// 			"1000010001",
// 			"1111111111"};
// 	int	j;
// 	int i;
	
// 	img = mlx_new_image(env->mlx, 300, 400);
// 	printf("size line: %d\n", img->size_line);
// 	printf("bits per pixel: %d\n", img->bpp);
// 	printf("width: %d\n", img->width);
// 	printf("height: %d\n", img->height);
// 	j = 0;
// 	while (grid[j / 20])
// 	{
// 		i = 0;
// 		while (grid[i / 20])
// 		{
// 			if (grid[i / 20][j / 20] == '1')
// 				pixel_put(img, i, j, 0x00FF0000);
// 			else 
// 				pixel_put(img, i, j, 0x000000000);
// 			i++;
// 		}
// 		j++;
// 	}
// 	mlx_put_image_to_window(env->mlx, env->win, img, 0, 0);
// 	mlx_loop(env->mlx);
// }