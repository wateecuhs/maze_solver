/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_solve.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wateecuhs <waticouzz@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:18:07 by wateecuhs         #+#    #+#             */
/*   Updated: 2023/09/30 00:18:19 by wateecuhs        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_SOLVE_H
# define A_SOLVE_H

#include "ft.h"

typedef struct s_node
{
	coords			data;
	struct s_node	*parent;
	struct s_node	*next;
}	node;

#endif