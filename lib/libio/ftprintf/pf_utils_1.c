/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:51:39 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/18 09:39:51 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(size_t num);

int	ftpf_putnbr(int n)
{
	char	c;
	int		count;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count++;
	}
	if (n > 9)
		count += ftpf_putnbr(n / 10);
	c = n % 10 + '0';
	manage_char(c);
	count++;
	return (count);
}

int	ftpf_putnbru(unsigned int u)
{
	char	c;
	int		count;

	count = 0;
	if (u > 9)
		count += ftpf_putnbru(u / 10);
	c = u % 10 + '0';
	manage_char(c);
	count++;
	return (count);
}

char	*ftpf_itoahex(size_t num)
{
	char		*str;
	long int	len;

	len = ft_numlen(num);
	str = malloc((sizeof(char) * (len + 1)));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		if ((num % 16) <= 9)
			str[len] = (num % 16) + '0';
		else
			str[len] = (num % 16) + 'a' - 10;
		num = num / 16;
		len--;
	}
	return (str);
}

static int	ft_numlen(size_t num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		len = 1;
	while (num > 0)
	{
		num = num / 16;
		len++;
	}
	return (len);
}
