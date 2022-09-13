/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:33:19 by aalleon           #+#    #+#             */
/*   Updated: 2022/03/04 13:12:24 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
		if (c == set[i++])
			return (1);
	return (0);
}

char	*ft_strtrim(const char *s, const char *set)
{
	size_t	l_s;
	size_t	start;
	size_t	end;
	char	*str;

	l_s = ft_strlen((char *)s);
	start = 0;
	end = l_s;
	while (ft_in_set(s[start], set))
		start++;
	if (start == end)
		return (ft_calloc(1, sizeof(str)));
	while (ft_in_set(s[end - 1], set))
		end--;
	str = malloc(end - start + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, s + start, end - start + 1);
	return (str);
}
