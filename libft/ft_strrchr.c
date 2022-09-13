/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:55:28 by aalleon           #+#    #+#             */
/*   Updated: 2022/03/04 12:24:47 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	char	*new_s;

	new_s = s + ft_strlen(s);
	while (new_s >= s)
	{
		if (*new_s == (char) c)
			return (new_s);
		new_s--;
	}
	return (0);
}
