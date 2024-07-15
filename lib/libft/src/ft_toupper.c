/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:05:38 by aolabarr          #+#    #+#             */
/*   Updated: 2024/01/14 20:24:37 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	if (ch >= 'a' && ch <= 'z')
		return (c - 32);
	return (c);
}
