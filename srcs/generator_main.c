/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wateecuhs <waticouzz@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:03:35 by wateecuhs         #+#    #+#             */
/*   Updated: 2023/09/25 16:59:23 by wateecuhs        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	main(int argc, char **argv)
{
	int	length;
	int	width;
	//int	complexity;

	length = 20;
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