/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:33:50 by aalleon           #+#    #+#             */
/*   Updated: 2022/04/07 10:39:27 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Compute length of table given it ends with NULL pointer.
ssize_t	ft_tab_len(char **tab)
{
	int	size;

	size = 0;
	while (tab[size])
		size++;
	return (size);
}
