/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <jbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:27:54 by jbouyer           #+#    #+#             */
/*   Updated: 2022/09/21 17:24:08 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	color_to_int(t_color color)
{
	return (color.R << 16 | color.G << 8 | color.B);
}

void	draw_background(t_global *env)
{
	t_img	*img;

	// char	*grid[11] = {"1111111111",
	// 		"1001010001",
	// 		"1001010001",
	// 		"1001010001",
	// 		"1001010001",
	// 		"1000000001",
	// 		"1001010001",
	// 		"1001000001",
	// 		"1000010001",
	// 		"1111111111"};
	img = mlx_new_image(env->mlx, 1024, 576);
	printf("size line: %d\n", img->size_line);
	printf("bits per pixel: %d\n", img->bpp);
	printf("width: %d\n", img->width);
	printf("height: %d\n", img->height);
	int i;
	int	j;
	j = 0;
	while (j < img->height / 2)
	{
		i = 0;
		while (i < img->width)
		{
			pixel_put(img, i, j, 0x00FFFFFF);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(env->mlx, env->win, img, 0, 0);
	// mlx_loop(env->mlx);
}
