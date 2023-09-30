/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wateecuhs <waticouzz@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:00:49 by wateecuhs         #+#    #+#             */
/*   Updated: 2023/09/30 01:21:15 by wateecuhs        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

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
	int isPath;
	int	f;
}	t_grid;

typedef struct s_coords
{
	int	x;
	int	y;
}	coords;

int		val_abs(int x);
char	*read_file(char *str);
int		ft_atoi(char *str);
void	free_grid(t_grid **grid, int width);
void 	init_grid(int length, int width);
void	gen_dfs(t_grid **grid, int i, int j);
void	solve_A(t_grid **grid, coords start, coords goal);


#endif