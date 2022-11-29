/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedroso <mpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:35:28 by mpedroso          #+#    #+#             */
/*   Updated: 2022/11/29 15:16:07 by mpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	line[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*gnl;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1 || FOPEN_MAX < fd)
		return (NULL);
	gnl = ft_strjoin(0, line[fd]);
	if (clear_ln(line[fd]))
		return (gnl);
	i = read(fd, line[fd], BUFFER_SIZE);
	if (i < 0 || (i == 0 && (*gnl == '\0')))
		return (free_gnl(gnl));
	while (i > 0)
	{
		gnl = ft_strjoin(gnl, line[fd]);
		if (clear_ln(line[fd]))
			break ;
		i = read(fd, line[fd], BUFFER_SIZE);
	}
	return (gnl);
}
