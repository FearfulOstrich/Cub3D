/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:19:46 by aalleon           #+#    #+#             */
/*   Updated: 2022/03/04 13:10:22 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	cpt;

	if (dstsize == 0)
		return (ft_strlen((char *)src));
	cpt = 0;
	while ((cpt < (dstsize - 1)) && src[cpt])
	{
		dst[cpt] = src[cpt];
		cpt++;
	}
	dst[cpt] = '\0';
	return (ft_strlen((char *)src));
}
