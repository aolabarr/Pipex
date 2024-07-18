/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:52:09 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/18 09:25:30 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ftpf_strdup(const char *s)
{
	char	*str;
	size_t	len;

	len = ftpf_strlen(s) + 1;
	str = malloc(len * sizeof(char));
	if (!str)
		return (NULL);
	ftpf_strlcpy(str, s, len);
	return (str);
}

size_t	ftpf_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		bool;

	bool = 0;
	i = 0;
	while (src[i] != '\0')
	{
		if (i < size - 1 && size != 0)
			dst[i] = src[i];
		else if (i == size - 1 && size != 0)
		{
			dst[i] = '\0';
			bool = 1;
		}
		i++;
	}
	if (bool == 0 && size != 0)
		dst[i] = '\0';
	return (i);
}

size_t	ftpf_strlen(const char *str)
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

char	*ftpf_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
