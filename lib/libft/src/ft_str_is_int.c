/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:54:11 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/10 17:18:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_is_int(char *str)
{
	if (str[0] != '-' && ft_strlen(str) > 10)
		return (0);
	else if (str[0] != '-' && ft_strlen(str) == 10)
	{
		if (ft_strncmp(MAXINT_STR, str, ft_strlen(str)) < 0)
			return (0);
	}
	else if (str[0] == '-' && ft_strlen(str) > 11)
		return (0);
	else if (str[0] == '-' && ft_strlen(str) == 11)
	{
		if (ft_strncmp(MININT_STR, str, ft_strlen(str)) < 0)
			return (0);
	}
	return (1);
}
