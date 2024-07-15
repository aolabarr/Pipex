/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:35:47 by aolabarr          #+#    #+#             */
/*   Updated: 2024/01/17 14:50:02 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_free_mat(char **mat, size_t mlen);
static size_t	ft_word_count(char const *s, char c);
static size_t	ft_char_count(const char *s, char c);

char	**ft_split(const char *s, char c)
{
	char	**mat;
	size_t	i;
	size_t	mlen;
	size_t	slen;

	mlen = ft_word_count(s, c);
	mat = malloc(sizeof(char *) * (mlen + 1));
	if (!mat)
		return (NULL);
	i = 0;
	while (i < mlen)
	{
		while (*s == c)
			s++;
		slen = ft_char_count(s, c);
		mat[i] = malloc(sizeof(char) * (slen + 1));
		if (!mat[i])
			return (ft_free_mat(mat, i));
		ft_strlcpy(mat[i], s, slen + 1);
		s = (ft_strchr(s, c));
		i++;
	}
	mat[i] = NULL;
	return (mat);
}

static size_t	ft_word_count(const char *s, char c)
{
	size_t	count;
	size_t	sw;

	if (!s)
		return (0);
	count = 0;
	sw = 0;
	while (*s != '\0')
	{
		if (*s == c)
			sw = 0;
		else if (sw == 0)
		{
			sw = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static size_t	ft_char_count(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (s[count] != c && s[count] != '\0')
		count++;
	return (count);
}

static char	**ft_free_mat(char **mat, size_t mlen)
{
	while (mlen)
	{
		free(mat[mlen]);
		mlen--;
	}
	free(mat[0]);
	free(mat);
	return (NULL);
}
