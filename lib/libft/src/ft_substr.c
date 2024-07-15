/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:57:21 by aolabarr          #+#    #+#             */
/*   Updated: 2024/01/17 14:01:51 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len >= ft_strlen(s) + 1 - start)
		len = ft_strlen(s) - start;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && i < len + start)
	{
		if (i >= start)
			str[i - start] = s[i];
		i++;
	}
	str[i - start] = '\0';
	return (str);
}
