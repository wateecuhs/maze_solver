/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wateecuhs <waticouzz@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:03:35 by wateecuhs         #+#    #+#             */
/*   Updated: 2023/09/23 19:21:56 by wateecuhs        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "ft_gen.h"

int	main(int argc, char **argv)
{
	int	length;
	int	width;
	//int	complexity;

	length = 10;
	width = 5;
	init_grid(length, width);
	/* if (argc == 4)
	{
		length = ft_atoi(argv[1]);
		width = ft_atoi(argv[2]);
		complexity = ft_atoi(argv[3]);
	} */
	(void)argc;
	(void)argv;
	return (0);
}