/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wateecuhs <waticouzz@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:14:19 by wateecuhs         #+#    #+#             */
/*   Updated: 2023/09/30 01:25:44 by wateecuhs        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

t_grid	*default_val(int length, int pos, int width)
{
	t_grid	*ret;
	int		i;

	ret = (t_grid *)malloc(sizeof(t_grid) * length);
	i = 0;
	while (i < length)
	{
		ret[i].north = 1;
		ret[i].south = 1;
		ret[i].east = 1;
		ret[i].west = 1;
		ret[i].visited = 0;
		ret[i].isPath = 0;
		ret[i].f = -1;
		if (pos == 0)
			ret[i].north = -1;
		if (pos == width - 1)
			ret[i].south = -1;
		if (i == 0)
			ret[i].west = -1;
		if (i == length - 1)
			ret[i].east = -1;
		i++;
	}
	return (ret);
}


void	print_grid(t_grid **grid, int length, int width)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("\u2587");
	while (j < length)
	{
		printf("\u2587\u2587");
		j++;
	}
	printf("\n");
	while (i < width)
	{
		j = 0;
		printf("\u2587");
		while (j < length)
		{
			if (grid[i][j].isPath == 0)
				printf(" ");
			else if (grid[i][j].isPath == 1)
				printf("o");
			else if (grid[i][j].isPath == 2)
				printf("S");
			else if (grid[i][j].isPath == 3)
				printf("E");
			if (grid[i][j].east == 1)
			{
				printf("\u2587");
			}
			else if (grid[i][j].east == 0)
			{
				printf(" ");
			}
			j++;
		}
		printf("\u2587");
		if (grid[i][0].south != -1)
		{
			printf("\n");
			printf("\u2587");
			j = 0;
			while (j < length)
			{
				if (grid[i][j].south == 1)
				{
					printf("\u2587");
				}
				else if (grid[i][j].south == 0)
				{
					printf(" ");
				}
				printf("\u2587");
				j++;
			}
		}
		printf("\n");
		i++;
	}
	j = 0;
	printf("\u2587");
	while (j < length)
	{
		printf("\u2587\u2587");
		j++;
	}
	printf("\n");
}

void init_grid(int length, int width)
{
	t_grid	**grid;
	coords start;
	coords end;
	int		i;

	grid = (t_grid **)malloc(sizeof(t_grid *) * width);
	i = 0;
	while (i < width)
	{
		grid[i] = default_val(length, i, width);
		i++;
	}
	srand(time(NULL));
	gen_dfs(grid, 0, 0);
	print_grid(grid, length, width);
	printf("\n\n");
	start.x = 0;
	start.y = 0;
	end.x = width - 1;
	end.y = length - 1;
	solve_A(grid, start, end);
	grid[start.x][start.y].isPath = 2;
	grid[end.x][end.y].isPath = 3;
	print_grid(grid, length, width);
	free_grid(grid, width);
}