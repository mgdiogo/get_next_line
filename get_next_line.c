/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedroso <mpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:55:01 by mpedroso          #+#    #+#             */
/*   Updated: 2022/11/21 19:02:49 by mpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	line[BUFFER_SIZE];
	char		*gnl;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1 || FOPEN_MAX < fd)
		return (NULL);
	gnl = ft_strjoin(0, line);
	if (clear_ln(line))
		return (gnl);
	i = read(fd, line, BUFFER_SIZE);
	if (i < 0 || (i == 0 && (!gnl || *gnl == '\0')))
		return (free_gnl(gnl));
	while (i > 0)
	{
		gnl = ft_strjoin(gnl, line);
		if (clear_ln(line))
			break ;
		i = read(fd, line, BUFFER_SIZE);
	}
	if (i == -1)
		return (free_gnl(gnl));
	return (gnl);
}
