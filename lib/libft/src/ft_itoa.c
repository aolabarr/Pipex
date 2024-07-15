/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:25:23 by aolabarr          #+#    #+#             */
/*   Updated: 2024/01/14 20:23:37 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*create_str_pos(long int num);
static char	*create_str_neg(long int num);
static int	ft_numlen(long int num);

char	*ft_itoa(int n)
{
	long int	num;
	int			sign;
	char		*str;

	sign = 0;
	num = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		sign = 1;
		num = -n;
	}
	else if (n > 0)
		num = n;
	if (sign == 1)
		str = create_str_neg(num);
	else
		str = create_str_pos(num);
	return (str);
}

static int	ft_numlen(long int num)
{
	int	len;

	len = 0;
	if (num == 0)
		len = 1;
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

static char	*create_str_pos(long int num)
{
	char	*str;
	int		len;

	len = ft_numlen(num);
	str = malloc((sizeof(char) * (len + 1)));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (str);
}

static char	*create_str_neg(long int num)
{
	char	*str;
	int		len;

	len = ft_numlen(num);
	str = malloc((sizeof(char) * (len + 2)));
	if (!str)
		return (NULL);
	str[len + 1] = '\0';
	str[0] = '-';
	while (len > 0)
	{
		str[len] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (str);
}
