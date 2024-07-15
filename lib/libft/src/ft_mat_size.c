/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 23:12:07 by marvin            #+#    #+#             */
/*   Updated: 2024/06/18 23:12:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_matsize(char **str)
{
	size_t	count;

	if (!str)
		return (0);
	count = 0;
	while (*str != NULL)
	{
		count++;
		str++;
	}
	return (count);
}
