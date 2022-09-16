/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <jbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:59:58 by jbouyer           #+#    #+#             */
/*   Updated: 2022/09/16 10:39:04 by jbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/cub3d.h"

static int	check_empty_line(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (!str || str[0] == '\n')
		return(1);
	while(str[i])
	{
		if(str[i] == ' ')
			flag++;
		i++;
	}
	if (flag == i -1)
		return (1);
	return (0);
}

int	texture_not_set(t_global *global)
{
	if (global->NO && global->SO && global->WE && global->EA \
		&& global->floor.R && global->ceiling.R)
		return(1);
	else
		return(0);
}

char *get_path(char *tmp, char *str)
{
	char	*path;
	int			i;

	if (!tmp || !str)
		return (0);
	path = ft_strnstr(tmp, str, ft_strlen(str));
	if (!path)
		return (0);
	i = ft_strlen(str);
	while (path[i] == ' ')
		i++;
	if (i != 0)
		path = ft_substr(path, i, ft_strlen(path) - i);
	return (path);
}

int	set_color(char *str, t_global *global, char c)
{
	int			i;
	char	**tmp;

	i = 0;
	while(str[i] == 'F' || str[i] == 'C')
		i++;
	str = ft_substr(str, i, ft_strlen(str) - i);
	str = ft_strtrim(str, " ");
	tmp = ft_split(str, ',');
	while(tmp[i])
		i++;
	if (i != 3)
		return(-1);
	if (c == 'F' && !global->floor.R)
	{
		global->floor.R = ft_atoi(tmp[0]);
		global->floor.G = ft_atoi(tmp[1]);
		global->floor.B = ft_atoi(tmp[2]);
	}
	else if (c == 'C' && !global->ceiling.R)
	{
		global->ceiling.R = ft_atoi(tmp[0]);
		global->ceiling.G = ft_atoi(tmp[1]);
		global->ceiling.B = ft_atoi(tmp[2]);
	}
	else 
	{
		write (1, "Error color\n", 12);
		return (-1);
	}
	return (0);
}
int	set_params(char *str, t_global *global)
{
	char	*tmp;
	
	tmp = ft_strtrim(str, " ");
	if (!tmp || tmp[0] == ' ')
		return (0);
	else if (get_path(tmp, "NO") != 0 && !global->NO)
		global->NO = get_path(tmp,"NO");
	else if (get_path(tmp, "WE") != 0 && !global->WE)
		global->WE = get_path(tmp, "WE");
	else if ( get_path(tmp, "EA") != 0 && !global->EA)
		global->EA = get_path(tmp, "EA");
	else if ( get_path(tmp, "SO") != 0 && !global->SO)
		global->SO = get_path(tmp, "SO");
	else if (get_path(tmp, "F") != 0)
		set_color(get_path(tmp, "F"), global, 'F');
	else if (get_path(tmp, "C") != 0)
		set_color(get_path(tmp, "C"), global, 'C');
	else
		return(-1);
	return (0);
}
char **dup_doublechartab(char **tab)
{
	char	**tmp;
	int			i;

	i = 0;
	while(tab[i])
		i++;
	tmp = (char **) malloc(sizeof(char *)* (i + 3));
	if (!tmp)
		return (NULL);
	i = 0;
	while(tab[i])
	{
		tmp[i] = ft_strdup(tab[i]);
		i++;
	}
	tmp[i] = '\0';
	ft_free_tab(tab);
	return (tmp);
}

int	fill_map(t_global *global, char *str)
{
	char **tmp;
	int		i;

	i = 0;
	if (!global->map)
	{
		global->map = (char **)malloc(sizeof(char *)*1);
		global->map[0] = ft_strdup(str);
		return (0);
	}
	tmp = dup_doublechartab(global->map);
	while(tmp[i])
		i++;
	global->map = (char **)malloc(sizeof(char *) * (i + 3));
	if (!global->map)
		return (-1);
	i = 0;
	while (tmp[i])
	{
		global->map[i] = ft_strdup(tmp[i]);
		i++;
	}
	global->map[i] = ft_strdup(str);
	global->map[++i]= '\0';
	return (0);
}

int	parsing(int fd)
{
	char		*tmp;
	int				i;
	t_global	*global;

	//rajouter si le nombre d'arguments n'est ps le bn ca tej si c'est pas un .cub ca tej !
	global = malloc(sizeof(*global));
	if (!global || global == NULL)
		return (0);
	while(tmp && texture_not_set(global) == 0)
	{
		tmp = get_next_line(fd);
		if (check_empty_line(tmp) == 0)
		{
			if (set_params(tmp, global) != 0)
			{
				write(1, "Error params\n", 13);
				return (-1);
			}
		}
	}
	tmp = get_next_line(fd);
	if (!tmp)
	{
		write (1, "Error\n", 6);
		return (-1);
	}
	while (check_empty_line(tmp)!= 0)
	{
		tmp = get_next_line(fd);
	}
	while (tmp && check_empty_line(tmp)== 0)
	{
		fill_map(global, tmp);
		tmp = get_next_line(fd);
	}
	printf("global->NO = %s\n", global->NO);
	printf("global->SO = %s\n", global->SO);
	printf("global->WE = %s\n", global->WE);
	printf("global->EA = %s\n", global->EA);
	printf("floor.R == %i", global->floor.R);
	printf("floor.G == %i", global->floor.G);
	printf("floor B == %i\n", global->floor.B);
	printf("ceiling R == %i", global->ceiling.R);
	printf("ceiling G == %i", global->ceiling.G);
	printf("ceiling B == %i\n", global->ceiling.B);
	i = 0;
	while(global->map[i])
	{
		printf("global->map[%i] = %s\n", i, global->map[i]);
		i++;
	}
	return(0);
}

int main()
{
	int fd;

	fd = open("map_test.cub", O_RDONLY);
	parsing(fd);
	return(0);
}


// a faire :
// reste a checker maintenant si le path est le bon.
// checker si les couleurs sont les bonnes, mettre message d'erreur si c'est pas bon. 
// GROS PB si je met pas es bon args.