/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wateecuhs <waticouzz@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:06:13 by wateecuhs         #+#    #+#             */
/*   Updated: 2023/09/18 21:18:29 by wateecuhs        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	file_len(char *str)
{
	char	buf[100];
	int		fd;
	int		char_read;
	int		count;

	char_read = -1;
	count = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		return (-1);
	}
	while (char_read != 0)
	{
		char_read = read(fd, buf, 99);
		if (char_read == -1)
			return (-1);
		count += char_read;
	}
	close(fd);
	return (count);
}

char	*read_file(char *str)
{
	char	*ret;
	int		fd;
	int		char_read;
	int		count;
	int		len;	

	len = file_len(str);
	if (len == -1)
		return (NULL);
	ret = (char *)malloc(len * sizeof(char) + 1);
	char_read = -1;
	count = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		return (NULL);
	}
	char_read = read(fd, ret, len);
	if (char_read == -1)
		return (NULL);
	count += char_read;
	ret[len] = '\0';
	close(fd);
	return (ret);
}