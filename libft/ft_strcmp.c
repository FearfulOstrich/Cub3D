/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:31:23 by aalleon           #+#    #+#             */
/*   Updated: 2022/02/11 18:08:15 by a42              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	cpt;

	cpt = 0;
	while (s1[cpt] && s1[cpt] == s2[cpt])
		cpt++;
	return ((unsigned char)s1[cpt] - (unsigned char)s2[cpt]);
}
