/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:12:24 by aalleon           #+#    #+#             */
/*   Updated: 2022/03/04 13:09:13 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	cpt;
	size_t	l_needle;

	cpt = 0;
	if (!*needle)
		return ((char *)haystack);
	l_needle = ft_strlen((char *)needle);
	if (l_needle > len)
		return (0);
	while (cpt <= len - l_needle && haystack[cpt])
	{
		if (!ft_strncmp(haystack + cpt, needle, l_needle))
			return ((char *)haystack + cpt);
		cpt++;
	}
	return (0);
}
