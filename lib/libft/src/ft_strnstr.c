/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:29:20 by aolabarr          #+#    #+#             */
/*   Updated: 2023/12/28 18:58:21 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *ht, const char *nd, size_t len)
{
	size_t	i;
	size_t	j;

	if (*nd == '\0')
		return ((char *)ht);
	i = 0;
	while (ht[i] != '\0' && i < len)
	{
		j = 0;
		while (ht[i + j] == nd[j] && (i + j < len))
		{
			if (nd[j + 1] == '\0')
				return ((char *)ht + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
