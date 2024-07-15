/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:31:28 by aolabarr          #+#    #+#             */
/*   Updated: 2023/12/26 15:36:41 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
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
