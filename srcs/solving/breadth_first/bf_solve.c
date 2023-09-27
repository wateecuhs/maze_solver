/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wateecuhs <waticouzz@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:36:34 by wateecuhs         #+#    #+#             */
/*   Updated: 2023/09/27 18:15:45 by wateecuhs        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"



/* int	bf_solve(t_grid **grid, coords start, coords goal, coords current)
{
	coords temp;

	temp = current;
	printf("looking for a move for current : %d %d\n", current.x, current.y);
	fflush(stdout);
	if (current.x == goal.x && current.y == goal.y)
	{
		printf("found solution\n");
		return (1);
	}
	grid[temp.x][temp.y].visited = 0;
	if (grid[current.x][current.y].south == 0 && grid[current.x + 1][current.y].visited == 1)
	{
		temp.x += 1;
		if (bf_solve(grid, start, goal, temp) == 1)
		{
			grid[temp.x][temp.y].isPath = 1;
			return (1);
		}
	}
	if (grid[current.x][current.y].north == 0 && grid[current.x - 1][current.y].visited == 1)
	{
		temp.x -= 1;
		if (bf_solve(grid, start, goal, temp) == 1)
		{
			grid[temp.x][temp.y].isPath = 1;
			return (1);
		}
	}
	if (grid[current.x][current.y].east == 0 && grid[current.x][current.y + 1].visited == 1)
	{
		temp.y += 1;
		if (bf_solve(grid, start, goal, temp) == 1)
		{
			grid[temp.x][temp.y].isPath = 1;
			return (1);
		}
	}
	if (grid[current.x][current.y].west == 0 && grid[current.x][current.y - 1].visited == 1)
	{
		temp.y -= 1;
		if (bf_solve(grid, start, goal, temp) == 1)
		{
			grid[temp.x][temp.y].isPath = 1;
			return (1);
		}
	}
	return (0);
} */

void	bf_solve(t_grid **grid, coords start, coords goal)
{
	node	*head;
	coords	temp;
	int		i;
	coords	current;

	head = ft_create_elem(start, NULL);
	i = 0;
	while (head)
	{
		current = head->data;
		if (current.x == goal.x && current.y == goal.y)
		{
			while(head->parent)
			{
				current = head->data;
				grid[current.x][current.y].isPath = 1;
				head = head->parent;
				i++;
			}
			printf("found solution in %d\n", i);
			ft_list_clear(head);
			return ;
		}
		grid[current.x][current.y].visited = 0;
		if (grid[current.x][current.y].south == 0 && grid[current.x + 1][current.y].visited == 1)
		{
			temp = current;
			temp.x += 1;
			ft_list_push_back(&head, temp);
		}
		if (grid[current.x][current.y].north == 0 && grid[current.x - 1][current.y].visited == 1)
		{
			temp = current;
			temp.x -= 1;
			ft_list_push_back(&head, temp);
		}
		if (grid[current.x][current.y].east == 0 && grid[current.x][current.y + 1].visited == 1)
		{
			temp = current;
			temp.y += 1;
			ft_list_push_back(&head, temp);
		}
		if (grid[current.x][current.y].west == 0 && grid[current.x][current.y - 1].visited == 1)
		{
			temp = current;
			temp.y -= 1;
			ft_list_push_back(&head, temp);
		}
		head = head->next;
	}
}