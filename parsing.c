/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouyer <jbouyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:59:58 by jbouyer           #+#    #+#             */
/*   Updated: 2022/09/14 12:37:57 by jbouyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/cub3d.h"

static int	check_texture(char *str)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while(str[i])
	{
		if(str[i] == ' ')
			flag++;
		i++;
	}
	if (flag == i - 1)
		return (1);
	if(str[0] == '\n' || !str)
				return(1);
	return (0);
}

static int check_arg(t_global *global)
{
	if (global->EA == NULL || global-> SO == NULL || global->NO == NULL || global->WE == NULL)
		return (1);
	else 
		return (0);
}

static int	fill_color(t_global *global, int t, char *tmp)
{
	char **str;
	int		i;

	i = 0;
	if (check_arg(global) == 1)
	{
		printf("Erreur args format pas correct NO EA WE SO, try AGAIN.");
		return (1);
	}
	str = ft_split(tmp, ',');
	while(str[i])
	{
		i++;
	}
	if (i < 3 || i > 3)
	{
		write(1, "Error color format\n", 19);
		return (-1);
	}
	//pa oublier protection si pas assez grand la chaine, genre si les args sont mauvais.
	if (t == 4)
	{
		global->floor.R = ft_atoi(str[0]);
		printf("floor R == %i", global->floor.R);
		global->floor.G = ft_atoi(str[1]);
		printf("floor G == %i", global->floor.G);
		global->floor.B = ft_atoi(str[2]);
		printf("floor B == %i", global->floor.B);
	}
	if (t == 5)
	{
		global->ceiling.R = ft_atoi(str[0]);
		printf("ceiling R == %i", global->ceiling.R);
		global->ceiling.G = ft_atoi(str[1]);
		printf("ceiling G == %i", global->ceiling.G);
		global->ceiling.B = ft_atoi(str[2]);
		printf("ceiling B == %i", global->ceiling.B);
	}
	return (0);
}
// int	fill_map(char *str, t_global *global)
// {
// 	t_list	*new;

// 	new = ft_lstnew(str);
// 	printf("str == %s", str);
// 	ft_lstadd_back(global->map->map, new);
// 	return(0);
// }

// void 	print_map(t_global *global)
// {
// 	while(global->map->map->content != NULL)
// 	{
// 		printf("%s", (char *)global->map->map->content);
// 		global->map->map->content = global->map->map->next;
// 	}
// }

int	parsing(int fd)
{
	int 		i;
	int			t;
	char		*tmp;
	t_global	*global;

	i = 0;
	t = 0;
	//rajouter si le nombre d'arguments n'est ps le bn ca tej si c'est pas un .cub ca tej !
	global = malloc(sizeof(*global));
	if (!global || global ==NULL)
		return (0);
	while( t <= 5)
	{
		tmp = get_next_line(fd);
		if (check_texture(tmp) == 1)
			i++;
		else
		{
			if (t == 0 && tmp[0] == 'N' && tmp[1] == 'O')
			{
				if (tmp[0] == 'N' && tmp[1] == 'O')
					global->NO = ft_substr(tmp, 3, (ft_strlen(tmp) - 4));
				else
				{
					write(1, "Error NO\n",9);
					return(-1);
				}
				printf("global->NO = %s\n", global->NO);
				t++;
			}
			else if (t == 1)
			{
				if (tmp[0] == 'S' && tmp[1] == 'O')
					global->SO = ft_substr(tmp, 3, (ft_strlen(tmp) - 4)); 
				else
				{
					write(1, "Error SO\n",9);
					return(-1);
				}
				printf("global->SO = %s\n", global->SO);
				t++;
			}
			
			else if (t == 2)
			{
				if (tmp[0] == 'W' && tmp[1] == 'E')
					global->WE = ft_substr(tmp, 3, (ft_strlen(tmp) - 4));
				else
				{
					write(1, "Error WE\n",9);
					return(-1);
				}
				t++;
				printf("global->WE = %s\n", global->WE);
			}
			else if (t == 3)
			{
				if (tmp[0] == 'E' && tmp[1] == 'A')
					global->EA = ft_substr(tmp, 3, (ft_strlen(tmp) - 4));
				else
				{
					write(1, "Error EA\n",9);
					return(-1);
				}
				t++;
				printf("global->EA = %s\n", global->EA);
			}
			else if (t == 4 || t == 5)
			{
				if (fill_color(global, t, ft_substr(tmp, 2, ft_strlen(tmp)-3)) == -1) //recuperer ici ls infos de l couleur a remettre bien dans le tableau
					return (-1);
				t++;
			}
			printf("t = %i", t);
			i++;
		}
	}
	while(tmp)
	{
		tmp = get_next_line(fd);
	printf("str == %s", tmp);

		// fill_map(tmp, global);
	}
	// print_map(global);
	printf("global->NO = %s\n", global->NO);
	printf("global->SO = %s\n", global->SO);
	printf("global->WE = %s\n", global->WE);
	printf("global->EA = %s\n", global->EA);
	return (0);
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