/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:51:10 by aolabarr          #+#    #+#             */
/*   Updated: 2024/04/07 12:35:29 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ftgn_strchr(const char *s, int c)
{
	size_t	i;
	char	aux;
	char	*str;

	aux = (char)c;
	c = aux;
	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	if (c == '\0')
		return (&str[i]);
	return (NULL);
}

char	*ftgn_strjoin(char *s1, char *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (ft_free2(&s1), NULL);
	str = malloc((ftgn_strlen(s1) + ftgn_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (ft_free2(&s1), NULL);
	ftgn_strlcpy(str, s1, ftgn_strlen(s1) + 1);
	ftgn_strlcpy(str + ftgn_strlen(s1), s2, ftgn_strlen(s2) + 1);
	ft_free2(&s1);
	return (str);
}

size_t	ftgn_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

size_t	ftgn_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

char	*ftgn_strdup(const char *s)
{
	char	*str;
	size_t	len;

	len = ftgn_strlen(s);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ftgn_strlcpy(str, s, len + 1);
	str[len] = '\0';
	return (str);
}
