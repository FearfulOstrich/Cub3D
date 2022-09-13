/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:24:01 by aalleon           #+#    #+#             */
/*   Updated: 2021/11/25 17:09:41 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			cpt;
	unsigned char	*str;

	str = (unsigned char *) s;
	cpt = 0;
	while (cpt < n)
	{
		if (str[cpt] == (unsigned char) c)
			return (str + cpt);
		cpt++;
	}
	return (0);
}
