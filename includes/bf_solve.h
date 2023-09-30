/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_solve.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wateecuhs <waticouzz@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:14:29 by wateecuhs         #+#    #+#             */
/*   Updated: 2023/09/30 00:17:55 by wateecuhs        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BF_SOLVE_H
# define BF_SOLVE_H

#include "ft.h"

typedef struct s_node
{
	coords			data;
	struct s_node	*parent;
	struct s_node	*next;
}	node;

node	*ft_create_elem(coords data, node *parent);
void	ft_list_push_back(node **begin_list, coords data);
void	bf_solve(t_grid **grid, coords start, coords goal);
void	ft_list_clear(node *begin_list);

#endif