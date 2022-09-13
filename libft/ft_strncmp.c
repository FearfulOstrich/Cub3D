/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:31:23 by aalleon           #+#    #+#             */
/*   Updated: 2021/12/04 15:53:24 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cpt;

	if (n == 0)
		return (0);
	cpt = 0;
	while (s1[cpt] && s1[cpt] == s2[cpt] && cpt < n - 1)
		cpt++;
	return ((unsigned char)s1[cpt] - (unsigned char)s2[cpt]);
}
