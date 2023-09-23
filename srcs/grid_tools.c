/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wateecuhs <waticouzz@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:56:26 by wateecuhs         #+#    #+#             */
/*   Updated: 2023/09/23 19:36:01 by wateecuhs        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gen.h"
#include "ft.h"

void	free_grid(t_grid **grid, int width)
{
	int		i;

	i = 0;
	while (i < width)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
