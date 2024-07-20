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
	if (!mat)
		return ;
	while (size)
	{
		if (mat[size])
			free(mat[size]);
		size--;
	}
	if (mat[0])
		free(mat[0]);
	free(mat);
	return ;
}
