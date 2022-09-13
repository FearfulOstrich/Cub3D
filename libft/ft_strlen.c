/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:06:38 by aalleon           #+#    #+#             */
/*   Updated: 2022/03/04 13:07:45 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

ssize_t	ft_strlen_nl(char *s)
{
	size_t	cpt;

	cpt = 0;
	while (s[cpt] && s[cpt] != '\n')
		cpt++;
	if (s[cpt] == '\n')
		return (cpt + 1);
	return (cpt);
}
