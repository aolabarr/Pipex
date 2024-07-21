/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 23:07:45 by marvin            #+#    #+#             */
/*   Updated: 2024/06/18 23:07:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_mat_str(char **mat, size_t size)
{
	size_t	i;

	if (!mat)
		return ;
	i = 0;
	while (i < size)
	{
		if (mat[i])
			free(mat[i]);
		i++;
	}
	free(mat);
	mat = NULL;
	return ;
}
