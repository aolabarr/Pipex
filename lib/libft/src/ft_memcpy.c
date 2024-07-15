/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:45:50 by aolabarr          #+#    #+#             */
/*   Updated: 2023/12/19 15:49:02 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src == NULL && dst == NULL)
		return (dst);
	while (i < n)
	{
		((char *)dst)[i] = ((const char *)src)[i];
		i++;
	}
	return (dst);
}
