/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <jbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:59:58 by jbouyer           #+#    #+#             */
/*   Updated: 2022/09/14 18:25:18 by jbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/cub3d.h"

static int	check_empty_line(char *str)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	if(!str || str[0] == '\n')
				return(1);
	while(str[i])
	{
		if(str[i] == ' ')
			flag++;
		i++;
	}
	if (flag == i)
		return (1);
	return (0);
}

// static int check_arg(t_global *global)
// {
// 	if (global->EA == NULL || global-> SO == NULL || global->NO == NULL || global->WE == NULL)
// 		return (1);
// 	else 
// 		return (0);
// }

// static int	fill_color(t_global *global, int t, char *tmp)
// {
// 	char **str;
// 	int		i;

// 	i = 0;
// 	if (check_arg(global) == 1)
// 	{
// 		printf("Erreur args format pas correct NO EA WE SO, try AGAIN.");
// 		return (1);
// 	}
// 	str = ft_split(tmp, ',');
// 	while(str[i])
// 	{
// 		i++;
// 	}
// 	if (i < 3 || i > 3)
// 	{
// 		write(1, "Error color format\n", 19);
// 		return (-1);
// 	}
// 	//pa oublier protection si pas assez grand la chaine, genre si les args sont mauvais.
// 	if (t == 4)
// 	{
// 		if(!global->floor.R)
// 			global->floor.R = ft_atoi(str[0]);
// 		else
// 			return(-1);
// 		printf("floor R == %i", global->floor.R);
// 		global->floor.G = ft_atoi(str[1]);
// 		printf("floor G == %i", global->floor.G);
// 		global->floor.B = ft_atoi(str[2]);
// 		printf("floor B == %i", global->floor.B);
// 	}
// 	if (t == 5)
// 	{
// 		if (!global->ceiling.R)
// 			global->ceiling.R = ft_atoi(str[0]);
// 		else 
// 			return (0);
// 		printf("ceiling R == %i", global->ceiling.R);
// 		global->ceiling.G = ft_atoi(str[1]);
// 		printf("ceiling G == %i", global->ceiling.G);
// 		global->ceiling.B = ft_atoi(str[2]);
// 		printf("ceiling B == %i", global->ceiling.B);
// 	}
// 	free(str);
// 	return (0);
// }

// int	fill_graphic_params(char *str, t_global *global)
// {
// 	int	i;
// 	int	t;

// 	i = 0;
// 	t = 0;
// 	printf("str === %s\n", str);
// 	while(str[i])
// 	{
// 		while (str[i] == ' ')
// 			i++;
// 		if (str[i] == 'N')
// 		{
// 			i++;
// 			if (str[i] == 'O')
// 			{
// 				while(str[i] != '.')
// 					i++;
// 				while(str[i] != ' ')
// 				{
// 					t++;
// 					i++;
// 				}
// 				if (!global->NO)
// 					global->NO=ft_substr(str, i - t, t);
// 			}
// 			else
// 				return (-1);
// 		}
// 		else if (str[i] == 'E')
// 		{
// 			i++;
// 			if (str[i] == 'A')
// 			{
// 				while(str[i] != '.')
// 					i++;
// 				while(str[i] != ' ')
// 				{
// 					t++;
// 					i++;
// 				}
// 				if (!global->EA)
// 					global->EA=ft_substr(str, i - t, t);
// 			}
// 			else
// 				return (-1);
// 		}
// 		// else if (str[i] == 'W')
// 		// {
// 		// 	i++;
// 		// 	if (str[i] == 'E')
// 		// 	{
// 		// 		while(str[i] != '.')
// 		// 			i++;
// 		// 		while(str[i] != ' ')
// 		// 		{
// 		// 			t++;
// 		// 			i++;
// 		// 		}
// 		// 		if (!global->WE)
// 		// 			global->WE=ft_substr(str, i - t, t);
// 		// 	}
// 		// 	else
// 		// 		return (-1);
// 		// }
// 		// else if (str[i] == 'S')
// 		// {
// 		// 	i++;
// 		// 	if (str[i] == 'O')
// 		// 	{
// 		// 		while(str[i] != '.')
// 		// 			i++;
// 		// 		while(str[i] != ' ')
// 		// 		{
// 		// 			t++;
// 		// 			i++;
// 		// 		}
// 		// 		if (!global->SO)
// 		// 			global->SO=ft_substr(str, i - t, t);
// 		// 	}
// 		// 	else
// 		// 		return(-1);
// 		// }
// 		// else if (str[i] == 'F')
// 		// {
// 		// 	i++;
// 		// 	while(str[i] == ' ')
// 		// 		i++;
// 		// 	while(str[i] != ' ')
// 		// 	{
// 		// 		t++;
// 		// 		i++;
// 		// 	}
// 		// 	fill_color(global, 4, ft_substr(str, i - t, t));
// 		// }
// 		// else if (str[i] == 'C')
// 		// {
// 		// 	i++;
// 		// 	while(str[i] == ' ')
// 		// 		i++;
// 		// 	while(str[i] != ' ')
// 		// 		t++;
// 		// 	fill_color(global, 5, ft_substr(str, i, t));
// 		// }
// 		i++;
// 	}
// 	return (0);
// }
// static int	is_map(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while(str[i] != ' ')
// 	{
// 		i++;
// 	}
// 	if (str[i] == '0' || str[i] == '1')
// 		return (1);
// 	return (0);
// }

// int	parsing(int fd)
// {
// 	char		*tmp;
// 	int i;
// 	t_global	*global;

// 	//rajouter si le nombre d'arguments n'est ps le bn ca tej si c'est pas un .cub ca tej !
// 	i = 0;
// 	global = malloc(sizeof(*global));
// 	if (!global || global == NULL)
// 		return (0);
// 	while(i < 10)
// 	{
// 		tmp = get_next_line(fd);
// 		if (check_empty_line(tmp) != 1)
// 		{
// 			fill_graphic_params(tmp, global);
// 		}
// 		i++;
// 	}
// 	// while(tmp)
// 	// {
// 	// 	tmp = get_next_line(fd);
// 	// 	printf("str == %s", tmp);
// 	// }
// 	printf("global->NO = %s\n", global->NO);
// 	printf("global->SO = %s\n", global->SO);
// 	printf("global->WE = %s\n", global->WE);
// 	printf("global->EA = %s\n", global->EA);
// 	return (0);
// }

// int	check_line(char *tmp, t_global *global)
// {
// 	int	i;

// 	i = 0;
// 	while (tmp[i] == ' ')
// 		i++;
// 	if (tmp[i] > '0' && tmp[i] < 9)
// 		return(1);
// }
int	texture_not_set(t_global *global)
{
	if (global->NO && global->SO && global->WE && global->EA && global->floor.R && global->ceiling.R)
		return(1);
	else
		return(0);
}

char *get_path(char *tmp, char *str)
{
	char	*path;
	int			i;

	i = 0;
	if (!tmp || !str)
		return (0);
	path = ft_strnstr(tmp, str, ft_strlen(str));
	if (!path)
		return (0);
	while (path[i] == ' ')
		i++;
	if (i != 0)
		path = ft_substr(path, i, ft_strlen(path) - i);
	return (path);
}
void	set_params(char *str, t_global *global)
{
	char *tmp;
	
	tmp = ft_strtrim(str, " ");
		printf("str == %s", tmp);
	if (get_path(tmp, "NO") != 0)
		global->NO = get_path(tmp,"NO");
	if (get_path(tmp, "WE") != 0)
		global->WE = get_path(tmp, "WE");
	if ( get_path(tmp, "EA") != 0)
		global->EA = get_path(tmp, "EA");
	if ( get_path(tmp, "SO") != 0)
		global->SO = get_path(tmp, "SO");
	// else if (path(tmp, "F"))
	// 	set_color(path, global, F);
	// else if (path(tmp, "C"))
	// 	set_color(path, global, C);
}

int	parsing(int fd)
{
	char		*tmp;
	t_global	*global;

	//rajouter si le nombre d'arguments n'est ps le bn ca tej si c'est pas un .cub ca tej !
	global = malloc(sizeof(*global));
	if (!global || global == NULL)
		return (0);
	while(tmp && texture_not_set(global) == 0)
	{
		tmp = get_next_line(fd);
		// si la ligne n'est pas vide faire ca :
		if (check_empty_line(tmp) == 0)
			set_params(tmp, global);
	}
	printf("global->NO = %s\n", global->NO);
	printf("global->SO = %s\n", global->SO);
	printf("global->WE = %s\n", global->WE);
	printf("global->EA = %s\n", global->EA);
		// check_line(tmp, global);
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