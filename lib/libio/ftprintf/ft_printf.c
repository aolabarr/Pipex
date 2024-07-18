/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:32:09 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/18 09:23:44 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	printer_manager(va_list vargs, char type);

int	ft_printf(const char *str, ...)
{
	va_list	vargs;
	size_t	i;
	size_t	count;

	va_start(vargs, str);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			count += printer_manager(vargs, str[i]);
		}
		else
			count += manage_char(str[i]);
		i++;
	}
	va_end(vargs);
	return (count);
}

static int	printer_manager(va_list vargs, char type)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += manage_char(va_arg(vargs, int));
	else if (type == 's')
		count += manage_str(va_arg(vargs, char *));
	else if (type == 'p')
		count += manage_dir(va_arg(vargs, size_t));
	else if (type == 'd' || type == 'i')
		count += ftpf_putnbr(va_arg(vargs, int));
	else if (type == 'u')
		count += ftpf_putnbru(va_arg(vargs, unsigned int));
	else if (type == 'x' || type == 'X')
		count += manage_hex(va_arg(vargs, unsigned int), type);
	else if (type == '%')
		count += manage_char('%');
	return (count);
}
