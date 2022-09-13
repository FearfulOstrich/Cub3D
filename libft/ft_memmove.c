/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:35:05 by aalleon           #+#    #+#             */
/*   Updated: 2021/12/08 14:48:23 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	cpt;

	if (!dest && !src)
		return (0);
	cpt = 0;
	if (dest > src)
	{
		while (++cpt <= len)
			((char *) dest)[len - cpt] = ((char *) src)[len - cpt];
	}
	else
	{
		while (++cpt <= len)
			((char *) dest)[cpt - 1] = ((char *) src)[cpt - 1];
	}
	return (dest);
}
