/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:28:37 by aalleon           #+#    #+#             */
/*   Updated: 2022/01/06 17:38:54 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			cpt;
	unsigned char	*str;

	str = (unsigned char *) b;
	cpt = 0;
	while (cpt < len)
	{
		str[cpt] = (unsigned char) c;
		cpt++;
	}
	return (b);
}
