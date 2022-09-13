/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:34:36 by aalleon           #+#    #+#             */
/*   Updated: 2022/03/04 12:25:24 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char) c)
			return (s);
		s++;
	}
	if (*s == (char) c)
		return (s);
	return (0);
}