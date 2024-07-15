/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_freed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:21:19 by aolabarr          #+#    #+#             */
/*   Updated: 2024/06/08 16:54:35 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_freed(char *s1, char const *s2)
{
	char	*str;

	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcpy(str + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	free(s1);
	return (str);
}
