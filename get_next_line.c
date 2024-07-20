/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:53:27 by mochen            #+#    #+#             */
/*   Updated: 2024/07/19 12:27:00 by mochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *stash, char *buf)
{
	char	*temp;

	temp = ft_strjoin(stash, buf);
	free(stash);
	return (temp);
}

char	*ft_fillstash(char *stash, char *buf, int buf_size, int fd)
{
	int		i;

	i = 0;
	while (ft_strchr(stash, '\n') < 0)
	{
		i = read(fd, buf, buf_size);
		if (i > 0)
		{
			buf[i] = '\0';
			stash = ft_free(stash, buf);
		}
		else
			break ;
	}
	if (i == -1)
	{
		free(stash);
		return (0);
	}
	return (stash);
}

char	*ft_line(char *stash)
{
	int	i;

	i = 0;
	if (!stash[0])
		return (0);
	else
	{
		while (stash[i] && stash[i] != '\n')
			++i;
		return (ft_strsub(stash, 0, i));
	}
}

char	*ft_nextstash(char *stash, int i)
{
	if (i < 0)
		return (ft_free(stash, 0));
	else
		return (ft_memmove(stash, stash + i + 1, ft_strlen(stash) - i));
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!stash)
	{
		stash = malloc(sizeof(char) * 1);
		if (!stash)
			return (0);
		stash[0] = '\0';
	}
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	stash = ft_fillstash(stash, buf, BUFFER_SIZE, fd);
	free(buf);
	if (!stash)
		return (0);
	line = ft_line(stash);
	stash = ft_nextstash(stash, ft_strchr(stash, '\n'));
	return (line);
}
