/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a42 <a42@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:04:38 by a42               #+#    #+#             */
/*   Updated: 2022/02/19 11:55:09 by a42              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap_int(int *i, int *j)
{
	int	buf;

	buf = *i;
	*i = *j;
	*j = buf;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = i;
		while (j && (tab[j] < tab[j - 1]))
		{
			ft_swap_int(tab + j, tab + j - 1);
			j--;
		}
		i++;
	}
}
