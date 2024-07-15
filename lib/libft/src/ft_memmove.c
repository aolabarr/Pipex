/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:08:00 by aolabarr          #+#    #+#             */
/*   Updated: 2023/12/28 09:53:53 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void *src, size_t len)
{
	size_t	i;
	char	*src2;
	char	*dst2;

	src2 = src;
	dst2 = dst;
	if (src2 < dst2)
	{
		i = len;
		while (i > 0)
		{
			dst2[i - 1] = src2[i - 1];
			i--;
		}
	}
	else if (src2 > dst2)
		ft_memcpy(dst2, src2, len);
	return (dst);
}
