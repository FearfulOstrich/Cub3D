/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:31:08 by aalleon           #+#    #+#             */
/*   Updated: 2022/02/04 10:26:05 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	cpt;
	char	*str_dst;
	char	*str_src;

	if (!dst && !src)
		return (0);
	str_dst = (char *) dst;
	str_src = (char *) src;
	cpt = 0;
	while (cpt < n)
	{
		str_dst[cpt] = str_src[cpt];
		cpt++;
	}
	return (dst);
}
