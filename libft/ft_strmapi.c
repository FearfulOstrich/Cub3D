/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:25:16 by aalleon           #+#    #+#             */
/*   Updated: 2022/03/04 13:13:12 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	cpt;

	str = malloc(ft_strlen((char *)s) + 1);
	if (!str)
		return (0);
	cpt = 0;
	while (s[cpt])
	{
		str[cpt] = f(cpt, s[cpt]);
		cpt++;
	}
	str[cpt] = '\0';
	return (str);
}
