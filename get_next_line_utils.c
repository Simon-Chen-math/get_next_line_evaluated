/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochen <mochen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:13:06 by mochen            #+#    #+#             */
/*   Updated: 2024/07/19 11:24:43 by mochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		++i;
	return (i);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s || ft_strlen(s) == 0)
		return (-1);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		++i;
	}
	if (s[i] == (char)c)
		return (i);
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		l;
	int		i;
	char	*s;

	i = -1;
	if (!s1 || !s2)
		return (0);
	l = ft_strlen(s1) + ft_strlen(s2);
	s = malloc(sizeof(char) * (l + 1));
	if (!s)
		return (0);
	--s1;
	--s2;
	while (*(++s1))
		s[++i] = *(char *)s1;
	while (*(++s2))
		s[++i] = *(char *)s2;
	s[++i] = '\0';
	return (s);
}

char	*ft_memmove(char *dst, char *src, int n)
{
	int	i;
	int	s;

	i = -1;
	if (!dst || !src)
		return (0);
	while (++i < n)
	{
		s = (-1 + (2 * (dst < src))) * i + (n - 1) * (1 - (dst < src));
		((unsigned char *)dst)[s] = ((unsigned char *)src)[s];
	}
	return (dst);
}

char	*ft_strsub(char *s, int min, int max)
{
	char	*p;
	int		i;

	i = -1;
	if (min > max)
		return ("");
	p = (char *)malloc((max - min + 2) * sizeof(char));
	if (!p)
		return (0);
	while (min <= max)
		p[++i] = s[min++];
	p[++i] = '\0';
	return (p);
}
