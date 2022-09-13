/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:58:53 by aalleon           #+#    #+#             */
/*   Updated: 2022/03/04 12:29:42 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	l_nbr;

	l_nbr = n;
	if (l_nbr < 0)
	{
		ft_putchar_fd('-', fd);
		l_nbr *= -1;
	}
	if (l_nbr > 9)
		ft_putnbr_fd(l_nbr / 10, fd);
	ft_putchar_fd('0' + l_nbr % 10, fd);
}
