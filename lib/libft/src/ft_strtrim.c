/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:17:35 by aolabarr          #+#    #+#             */
/*   Updated: 2024/01/17 16:58:50 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_in_set(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	finish;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	finish = ft_strlen(s1);
	while (char_in_set(s1[start], set) == 1 && start < finish)
		start++;
	if (start == finish)
		return (ft_strdup(""));
	finish--;
	while (char_in_set(s1[finish], set) == 1 && finish > start)
		finish--;
	str = malloc((finish - start + 2) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (start <= finish)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}

static int	char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(set))
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
