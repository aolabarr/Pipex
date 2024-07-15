/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:39:00 by aolabarr          #+#    #+#             */
/*   Updated: 2023/12/28 09:54:45 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size <= dstlen || size == 0)
		return (size + srclen);
	i = 0;
	while (size - dstlen - i > 1 && src[i] != '\0')
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	if (size > 0)
		dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
