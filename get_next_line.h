/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochen <mochen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:33:15 by mochen            #+#    #+#             */
/*   Updated: 2024/07/19 12:19:07 by mochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_strlen(const char *s);
int		ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strsub(char *s, int min, int max);
char	*ft_memmove(char *dst, char *src, int n);

char	*ft_free(char *stash, char *buf);
char	*ft_fillstash(char *stash, char *buf, int buf_size, int fd);
char	*ft_line(char *stash);
char	*ft_nextstash(char *stash, int i);
char	*get_next_line(int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif
#endif
