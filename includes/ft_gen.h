/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wateecuhs <waticouzz@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:36:27 by wateecuhs         #+#    #+#             */
/*   Updated: 2023/09/23 19:22:55 by wateecuhs        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GEN_H
# define FT_GEN_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>

typedef struct s_grid
{
	int	north;
	int	south;
	int	east;
	int	west;
	int	visited;
}	t_grid;

void	free_grid(t_grid **grid, int width);
void 	init_grid(int length, int width);

#endif