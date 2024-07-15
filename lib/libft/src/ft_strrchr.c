/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:39:37 by aolabarr          #+#    #+#             */
/*   Updated: 2024/01/11 16:28:35 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i--;
	}
	return (NULL);
}
