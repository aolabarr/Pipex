/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 14:12:18 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/10 17:19:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static float	get_decimals(float res, int i, const char *str);

float	ft_atoi_float(const char *str)
{
	size_t		i;
	int			sign;
	float		res;

	if (!str)
		return (0);
	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - 48;
	if (str[i++] == '.')
		res = get_decimals(res, i, str);
	return (res * sign);
}

static float	get_decimals(float res, int i, const char *str)
{
	float	ord;

	ord = 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ord /= 10;
		res = res + (str[i] - 48) * ord;
		i++;
	}
	return (res);
}
