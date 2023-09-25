/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_solve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wateecuhs <waticouzz@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 20:46:21 by wateecuhs         #+#    #+#             */
/*   Updated: 2023/09/25 16:44:33 by wateecuhs        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

coords	best_move(t_grid **grid, coords start, coords goal, coords current)
{
	int	f1;
	int	f2;
	int	f3;
	int	f4;
	coords ret;

	printf("looking for a move for current : %d %d\n", current.x, current.y);
	ret = current;
	f1 = -1;
	f2 = -1;
	f3 = -1;
	f4 = -1;
	if (grid[current.x][current.y].south == 0)
	{
		f1 = abs(start.x - (current.x + 1)) + abs(start.y - current.y) + abs((current.x + 1) - goal.x) + abs(current.y - goal.y);printf("f1 : %d\n", f1);
		ret.x = current.x + 1;
		printf("took value from f1\n");
	}
	if (grid[current.x][current.y].north == 0)
	{
		f2 = abs(start.x - (current.x - 1)) + abs(start.y - current.y) + abs((current.x - 1) - goal.x) + abs(current.y - goal.y);
		if (f2 < f1 || f1 == -1)
		{
			ret.x = current.x - 1;
			printf("took value from f2\n");
		}
		printf("f2 : %d\n", f2);
	}
	if (grid[current.x][current.y].east == 0)
	{
		f3 = abs(start.x - (current.x)) + abs(start.y - (current.y + 1)) + abs((current.x) - goal.x) + abs((current.y + 1) - goal.y);
		if ((f3 < f2 || f2 == -1) && (f3 < f1 || f1 == -1))
		{
			ret.x = current.x;
			ret.y = current.y + 1;
			printf("took value from f3\n");
		}
		printf("f3 : %d\n", f3);
	}
	if (grid[current.x][current.y].west == 0)
	{
		f4 = abs(start.x - (current.x)) + abs(start.y - (current.y - 1)) + abs((current.x) - goal.x) + abs((current.y - 1) - goal.y);
		if ((f4 < f3 || f3 == -1) && (f4 < f2 || f2 == -1) && (f4 < f1 || f1 == -1))
		{
			ret.x = current.x;
			ret.y = current.y - 1;
			printf("took value from f4\n");
		}
		printf("f4 : %d\n", f4);
	}
	printf("returning %d %d\n", ret.x, ret.y);
	return (ret);
}

void	solve_A(t_grid **grid, coords start, coords goal, coords current)
{
	coords tmp;
	
	printf("through main loop\n");
	grid[current.x][current.y].isPath = 1;
	if (current.x == goal.x && current.y == goal.y)
		return ;
	tmp = best_move(grid, start, goal, current);
	if (current.x == tmp.x && current.y == tmp.y)
	{
		printf("stopped at %d %d\n", current.x, current.y);
		fflush(stdout);
		return ;
	}
	current = tmp;
	printf("current : %d %d\n", current.x, current.y);
	//fflush(stdout);
	solve_A(grid, start, goal, current);
}