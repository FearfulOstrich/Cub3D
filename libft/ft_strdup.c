/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:26:15 by aalleon           #+#    #+#             */
/*   Updated: 2022/03/04 13:11:23 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chardup(const char c)
{
	char	*dest;

	if (!c)
		return (ft_calloc(1, sizeof(*dest)));
	dest = ft_calloc(2, sizeof(*dest));
	if (!dest)
		return (0);
	dest[0] = c;
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		str_len;

	str_len = ft_strlen((char *)s1);
	dest = malloc(sizeof(*dest) * (str_len + 1));
	if (!dest)
		return (0);
	ft_strlcpy(dest, s1, str_len + 1);
	return (dest);
}
