/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wateecuhs <waticouzz@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:36:34 by wateecuhs         #+#    #+#             */
/*   Updated: 2023/09/30 01:17:43 by wateecuhs        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bf_solve.h"

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