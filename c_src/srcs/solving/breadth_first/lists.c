/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wateecuhs <waticouzz@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:45:44 by wateecuhs         #+#    #+#             */
/*   Updated: 2023/09/30 00:36:05 by wateecuhs        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bf_solve.h"

node	*ft_create_elem(coords data, node *parent)
{
	node	*ret;

	ret = (node *)malloc(sizeof(node));
	ret->data = data;
	ret->parent = parent;
	ret->next = NULL;
	return (ret);
}

void ft_list_push_back(node **begin_list, coords data)
{
	node	*head;

	if (!(*begin_list))
	{
		*begin_list = ft_create_elem(data, *begin_list);
	}
	head = *begin_list;
	while (head->next)
	{
		head = head->next;
	}
	head->next = ft_create_elem(data, *begin_list);
}

void	ft_list_clear(node *begin_list)
{
	node	*temp;

	while (begin_list->parent)
	{
		begin_list = begin_list->parent;
	}
	while (begin_list)
	{
		temp = begin_list->next;
		free(begin_list);
		begin_list = temp;
	}
}