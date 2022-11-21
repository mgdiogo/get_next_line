/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedroso <mpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:42:24 by mpedroso          #+#    #+#             */
/*   Updated: 2022/11/21 19:05:02 by mpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i] != '\n' && s[i] != '\0')
		i++;
	if (s && s[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *buf)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc(ft_strlen(s1) + ft_strlen(buf) + 1);
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (buf && buf[j] && buf[j] != '\n')
		str[i++] = buf[j++];
	if (buf[j] == '\n')
		str[i++] = buf[j];
	str[i] = '\0';
	if (s1)
		free(s1);
	return (str);
}

int	clear_ln(char *buf)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (buf && buf[i])
	{
		if (flag == 1)
			buf[j++] = buf[i];
		if (buf[i] == '\n')
			flag = 1;
		buf[i++] = 0;
	}
	return (flag);
}

char	*free_gnl(char *gnl)
{
	free(gnl);
	return (NULL);
}
