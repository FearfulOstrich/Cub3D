/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 20:53:46 by aalleon           #+#    #+#             */
/*   Updated: 2022/03/04 12:32:52 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_char(long int n)
{
	size_t	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t		n_char;
	long int	nbr;
	char		*str;

	if (!n)
		return (ft_strdup("0"));
	nbr = n;
	n_char = ft_count_char(nbr);
	str = malloc(n_char + 1);
	if (!str)
		return (0);
	str[n_char--] = '\0';
	if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
	}
	while (nbr)
	{
		str[n_char--] = '0' + nbr % 10;
		nbr /= 10;
	}
	return (str);
}
