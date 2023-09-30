/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_solve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wateecuhs <waticouzz@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 20:46:21 by wateecuhs         #+#    #+#             */
/*   Updated: 2023/09/30 03:48:47 by wateecuhs        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

typedef struct s_node
{
	int				f;
	int				g;
	coords			data;
	struct s_node	*parent;
	struct s_node	*next;
	struct s_node	*bad_solution;
}	node;

node	*ft_create_elem(coords data, node *parent, int f, int g)
{
	node	*ret;

	ret = (node *)malloc(sizeof(node));
	ret->data = data;
	ret->f = f;
	ret->g = g;
	ret->parent = parent;
	ret->next = NULL;
	ret->bad_solution = NULL;
	return (ret);
}

void	print_list(node *head)
{
	while (head)
	{
		printf("%d:%d  ", head->data.x, head->data.y);
		head = head->next;
	}
	printf("\n");
}

void pop_elem(node **begin_list, node *target)
{
	node	*head;
	node	*trailing;

	head = *begin_list;
	if (head == target)
	{
		if (!(head->next))
			*begin_list = NULL;
		else
		{
			*begin_list = (*begin_list)->next;
		}
		return ;
	}
	while (head)
	{
		if (head == target)
		{
			trailing->next = head->next;
			head = trailing;
		}
		trailing = head;
		head = head->next;
	}
}

node	*ft_list_at(node *begin_list, coords data)
{
	node	*head;

	head = begin_list;
	while (head)
	{
		if (head->data.x == data.x && head->data.y == data.y)
		{
			return (head);
		}
		head = head->next;
	}
	return (NULL);
}

int	ft_in_list(node **begin_list, coords data, int g)
{
	node	*head;

	head = *begin_list;
	while (head)
	{
		if (head->data.x == data.x && head->data.y == data.y && head->g > g)
		{
			pop_elem(begin_list, head);
		}
		else if (head->data.x == data.x && head->data.y == data.y && head->g < g)
		{
			return (1);
		}
		head = head->next;
	}
	return (0);
}


node	*smallest_f(node	*list_open)
{
	node	*head;
	coords	smallest_coords;
	int		smallest;

	head = list_open;
	smallest = -1;
	smallest_coords.x = -1;
	smallest_coords.y = -1;
	while (head)
	{
		if (head->f < smallest || smallest == -1)
		{
			smallest = head->f;
			smallest_coords = head->data;
		}
		head = head->next;
	}
	if (smallest == -1)
		return (NULL);
	return (ft_list_at(list_open, smallest_coords));
}

node	*ft_list_push_back(node **begin_list, coords data, int f, node *parent, int g)
{
	node	*head;

	if (!(*begin_list))
	{
		*begin_list = ft_create_elem(data, parent, f, g);
		return (*begin_list);
	}
	head = *begin_list;
	while (head->next)
	{
		head = head->next;
	}
	head->next = ft_create_elem(data, parent, f, g);
	return (head->next);
}

void ft_pop_adding(node **begin_list, node *to_add)
{
	node	*head;

	if (!(*begin_list))
	{
		*begin_list = to_add;
		return ;
	}
	head = *begin_list;
	while (head->bad_solution)
	{
		head = head->bad_solution;
	}
	head->bad_solution = to_add;
}

// f = g + h
// g being movement cost from the starting point to here
// h being the heuristic of current to goal
// need open list
// find the node with lowest f in the open list then do the while loop on it

int	handle_successors(t_grid **grid, coords goal, node	**list_open, node	**list_closed, node	*q)
{
	int	f;
	coords temp;

	if (grid[q->data.x][q->data.y].south == 0)
	{
		f = (q->g + 1) + abs((q->data.x + 1) - goal.x) + abs(q->data.y - goal.y);
		temp.x = q->data.x + 1;
		temp.y = q->data.y;
		if (temp.x == goal.x && temp.y == goal.y)
			return (1);
		if (ft_in_list(list_open, temp, (q->g + 1)) != 1 && ft_in_list(list_closed, temp, (q->g + 1)) != 1)
			ft_list_push_back(list_open, temp, f, q, (q->g + 1));
	}
	if (grid[q->data.x][q->data.y].north == 0)
	{
		f = (q->g + 1) + abs((q->data.x - 1) - goal.x) + abs(q->data.y - goal.y);
		temp.x = q->data.x - 1;
		temp.y = q->data.y;
		if (temp.x == goal.x && temp.y == goal.y)
			return (2);
		if (ft_in_list(list_open, temp, (q->g + 1)) != 1 && ft_in_list(list_closed, temp, (q->g + 1)) != 1)
			ft_list_push_back(list_open, temp, f, q, (q->g + 1));
	}
	if (grid[q->data.x][q->data.y].east == 0)
	{
		f = (q->g + 1) + abs(q->data.x - goal.x) + abs((q->data.y + 1) - goal.y);
		temp.x = q->data.x;
		temp.y = q->data.y + 1;
		if (temp.x == goal.x && temp.y == goal.y)
			return (3);
		if (ft_in_list(list_open, temp, (q->g + 1)) != 1 && ft_in_list(list_closed, temp, (q->g + 1)) != 1)
			ft_list_push_back(list_open, temp, f, q, (q->g + 1));
	}
	if (grid[q->data.x][q->data.y].west == 0)
	{
		f = (q->g + 1) + abs(q->data.x - goal.x) + abs((q->data.y - 1) - goal.y);
		temp.x = q->data.x;
		temp.y = q->data.y - 1;
		if (temp.x == goal.x && temp.y == goal.y)
			return (4);
		if (ft_in_list(list_open, temp, (q->g + 1)) != 1 && ft_in_list(list_closed, temp, (q->g + 1)) != 1)
			ft_list_push_back(list_open, temp, f, q, (q->g + 1));
	}
	return (0);
}

void	ft_list_clear(node *begin_list)
{
	node	*temp;

	while (begin_list)
	{
		temp = begin_list->bad_solution;
		free(begin_list);
		begin_list = temp;
	}
}

void	solve_A(t_grid **grid, coords start, coords goal)
{
	node	*list_open;
	node	*list_closed;
	node	*full_list;
	node	*head;
	node	*q;
	int		result;

	list_open = ft_create_elem(start, NULL, 0, 0);
	list_closed = NULL;
	full_list = NULL;
	fflush(stdout);
	while (list_open)
	{
		fflush(stdout);
		q = smallest_f(list_open);
		pop_elem(&list_open, q);
		ft_pop_adding(&full_list, q);
		result = handle_successors(grid, goal, &list_open, &list_closed, q);
		if (result != 0)
		{
			head = q;
			while(head->parent)
			{
				fflush(stdout);
				grid[head->data.x][head->data.y].isPath = 1;
				q = head;
				head = head->parent;
			}
			ft_list_clear(full_list);
			ft_list_clear(list_open);
			return;
		}
		q = ft_list_push_back(&list_closed, q->data, q->f, q->parent, q->g);
		ft_pop_adding(&full_list, q);
	}
	ft_list_clear(full_list);
}