/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wateecuhs <waticouzz@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:14:19 by wateecuhs         #+#    #+#             */
/*   Updated: 2023/09/24 17:57:41 by wateecuhs        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gen.h"
#include "ft.h"

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

void	gen_dfs(t_grid **grid, int i, int j)
{
	int	random;
	int	temp;

	if (i == 0 && j == 0 && grid[i][j].visited == 1)
		return ;
	random = rand() % 4;
	temp = 0;
	grid[i][j].visited = 1;
	while (temp < 4)
	{
		if (random == 0 && grid[i][j].south != -1 && grid[i + 1][j].visited == 0)
		{
			grid[i][j].south = 0;
			grid[i + 1][j].north = 0;
			gen_dfs(grid, i + 1, j);
		}
		if (random == 1 && grid[i][j].east != -1 && grid[i][j + 1].visited == 0)
		{
			grid[i][j].east = 0;
			grid[i][j + 1].west = 0;
			gen_dfs(grid, i, j + 1);
		}
		if (random == 2 && grid[i][j].north != -1 && grid[i - 1][j].visited == 0)
		{
			grid[i][j].north = 0;
			grid[i - 1][j].south = 0;
			gen_dfs(grid, i - 1, j);
		}
		if (random == 3 && grid[i][j].west != -1 && grid[i][j - 1].visited == 0)
		{
			grid[i][j].west = 0;
			grid[i][j - 1].east = 0;
			gen_dfs(grid, i, j - 1);
		}
		temp++;
		random = (random + 1) % 4;
	}
}

void	print_grid(t_grid **grid, int length, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < width)
	{
		j = 0;
		/* while (j < length)
		{
			printf("GRID[%d][%d] : %d %d %d %d ; %d\n", i, j, grid[i][j].south, grid[i][j].east, grid[i][j].north, grid[i][j].west, grid[i][j].visited);
			j++;
		} */
		while (j < length)
		{
			if (grid[i][j].north == 1 && grid[i][j].west == 1)
				printf("┌");
			else if (grid[i][j].north == 1)
				printf("─");
			else if (grid[i][j].west == 1)
				printf("│"); 
			j++;
		}
		printf("\n");
		i++;
	}

}
void init_grid(int length, int width)
{
	t_grid	**grid;
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
	free_grid(grid, width);
}