/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalleon <aalleon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 20:17:57 by aalleon           #+#    #+#             */
/*   Updated: 2022/03/04 12:33:47 by aalleon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(const char *s, char c)
{
	int	size;
	int	cpt;

	size = 0;
	cpt = 0;
	if (s[cpt++] != c)
		size++;
	while (s[cpt])
	{
		if (s[cpt - 1] == c && s[cpt] != c)
			size++;
		cpt++;
	}
	return (size);
}

int	ft_dup_next_word(const char *s, char c, char **tab, int i)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	tab[i] = malloc(len + 1);
	if (!tab[i])
		return (-1);
	ft_strlcpy(tab[i], s, len + 1);
	while (s[len] == c)
		len++;
	return (len);
}

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	ft_trimchr(const char *s, char c)
{
	int	cpt;

	cpt = 0;
	while (s[cpt] == c)
		cpt++;
	return (cpt);
}

char	**ft_split(const char *s, char c)
{
	int		n_word;
	char	**tab;
	int		i;
	int		cpt;

	if (!*s)
		return (ft_calloc(1, sizeof(tab)));
	cpt = ft_trimchr(s, c);
	n_word = ft_count_words(s, c);
	tab = ft_calloc(n_word + 1, sizeof(*tab));
	if (!tab)
		return (0);
	i = 0;
	while (i < n_word)
	{
		cpt += ft_dup_next_word(s + cpt, c, tab, i);
		if (!tab[i])
		{
			ft_free_tab(tab);
			return (0);
		}
		i++;
	}
	return (tab);
}
