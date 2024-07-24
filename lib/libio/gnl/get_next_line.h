/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:50:28 by aolabarr          #+#    #+#             */
/*   Updated: 2024/04/07 12:56:22 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*extract_line(char *aux);
char	*save_rest(char *aux, size_t len);
void	ft_free2(char **str);
char	*read_file(int fd, char *bkup);

char	*ftgn_strchr(const char *s, int c);
char	*ftgn_strjoin(char *s1, char *s2);
char	*ftgn_strdup(const char *s);
size_t	ftgn_strlcpy(char *dst, const char *src, size_t size);
size_t	ftgn_strlen(const char *str);

#endif
