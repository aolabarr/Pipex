/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shlex_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 00:48:20 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/23 17:04:37 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_quote
{
	int		in;
	char	is;	
}			t_quote;

static size_t	ft_word_count(char *s, char c);
static size_t	ft_char_count(char *s, char c, t_quote quote);
static char		*save_word(char *s, char c, char **mat, int i);
static char		*search_quote(char *s, char c, t_quote quote);

char	**ft_shlex_split(char *s, char c)
{
	char	**mat;
	size_t	i;
	size_t	mlen;

	if (!s)
		return (NULL);
	mlen = ft_word_count(s, c);
	mat = malloc(sizeof(char *) * (mlen + 1));
	if (!mat)
		return (NULL);
	i = 0;
	while (i < mlen)
	{
		s = save_word(s, c, mat, i);
		i++;
	}
	mat[i] = NULL;
	return (mat);
}

static char	*save_word(char *s, char c, char **mat, int i)
{
	t_quote	quote;
	size_t	slen;

	quote.in = 0;
	while (*s == c && quote.in == 0)
		s++;
	if (*s == '"' || *s == '\'')
		quote.in = 1;
	if (*s == '"' || *s == '\'')
		quote.is = *s;
	slen = ft_char_count(s, c, quote);
	mat[i] = malloc(sizeof(char) * (slen + 1));
	if (!mat[i])
		return (ft_free_mat_str(mat, i), NULL);
	if (quote.in == 0)
	{
		ft_strlcpy(mat[i], s, slen + 1);
		s = (ft_strchr(s, c));
	}
	else if (quote.in == 1)
	{
		ft_strlcpy(mat[i], s + 1, slen + 1);
		s = (s + 1) + slen + 1;
	}
	return (s);
}

static size_t	ft_word_count(char *s, char c)
{
	size_t	count;
	size_t	sw;
	t_quote	quote;

	count = 0;
	sw = 0;
	while (*s != '\0')
	{
		quote.in = 0;
		if (sw == 0 && (*s == '"' || *s == '\''))
			quote.in = 1;
		if (sw == 0 && (*s == '"' || *s == '\''))
			quote.is = *s;
		if (*s == c && quote.in == 0)
			sw = 0;
		else if (sw == 0)
		{
			sw = 1;
			count++;
		}
		if (quote.in == 1)
			s = search_quote(s, c, quote);
		s++;
	}
	return (count);
}

static char	*search_quote(char *s, char c, t_quote quote)
{
	char	*end;

	end = ft_strchr(s + 1, quote.is);
	if (!end)
		return (s + ft_strlen(s));
	while (*(end + 1) != c && *(end + 1) != '\0')
	{
		end = ft_strchr(end + 1, quote.is);
		if (!end)
			return (s + ft_strlen(s) - 1);
	}
	return (s);
}

static size_t	ft_char_count(char *s, char c, t_quote quote)
{
	size_t	count;
	char	*end;

	count = 0;
	if (quote.in == 0)
	{
		while (s[count] != c && s[count] != '\0')
			count++;
	}
	else if (quote.in == 1)
	{
		end = search_quote(s, c, quote);
		count = end - s - 1;
	}
	return (count);
}
