/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 20:44:31 by wateecuhs         #+#    #+#             */
/*   Updated: 2024/01/30 13:56:45 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

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
