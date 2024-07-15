/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:13:31 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/13 23:36:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((str1[i] != '\0' || str2[i] != '\0') && (i < n))
	{
		if (str1[i] > str2[i])
			return (str1[i] - str2[i]);
		else if (str1[i] < str2[i])
			return (s1[i] - str2[i]);
		i++;
	}
	return (0);
}
