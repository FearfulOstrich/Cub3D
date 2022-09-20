/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <jbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:07:47 by jbouyer           #+#    #+#             */
/*   Updated: 2022/09/20 17:30:03 by jbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel; //bpp
// 	int		line_length; //size_line
// 	int		endian;
// }				t_data;

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->data + (y * img->size_line + x * (img->bpp) / 8);
	*(unsigned int*)dst = color;
}

void	mini_map(t_global *env)
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
	img = mlx_new_image(env->mlx, 150, 100);
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
			printf("i, j = (%d, %d)\n", i, j);
			pixel_put(img, i, j, 0x00FF0000);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(env->mlx, env->win, img, 0, 0);
	mlx_loop(env->mlx);
}