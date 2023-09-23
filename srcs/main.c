/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wateecuhs <waticouzz@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:03:35 by wateecuhs         #+#    #+#             */
/*   Updated: 2023/09/18 21:51:43 by wateecuhs        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	**maze_int(char *str)
{
	int	**tab;
	int	len;
	int	i;
	int	j;

	len = 0;
	while (str[len] && str[len] != '\n')
	{
		len++;
	}
	printf("len %d\n", len);
	tab = (int **)malloc(sizeof(int *) * 11);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < 11)
	{
		tab[i] = (int *)malloc(sizeof(int) * len);
		i++;
	}
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			tab[j / len][j % len] = 0;
			j++;
		}
		else if (str[i] == '.')
		{
			tab[j / len][j % len] = 1;
			j++;
		}
		i++;
	}
	return (tab);
}

int	main(int argc, char **argv)
{
	char	*file;
	int		**maze;
	int		i;
	int		j;

	if (argc == 2)
	{
		file = read_file(argv[1]);
		if (!file)
		{
			free(file);
			return (0);
		}
		printf("%s\n", file);
		maze = maze_int(file);
		i = 0;
		while (i < 11)
		{
			j = 0;
			while (j < 16)
			{
				printf("%d ", maze[i][j]);
				j++;
			}
			free(maze[i]);
			printf("\n");
			i++;
		}
		free(file);
		free(maze);
	}
}