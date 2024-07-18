/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:30:19 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/18 20:40:55 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	**ft_malloc_mat(int x, int y, int size)
{
	int	**map;
	int	i;

	map = malloc(sizeof(void *) * x);
	if (!map)
		return (NULL);
	i = 0;
	while (i < x)
	{
		map[i] = malloc(size * y);
		if (!map[i])
			return (ft_free_mat_int(map, i), NULL);
		i++;
	}
	return (map);
}
void	ft_free_mat_int(int **mat, int size)
{
	int	i;

	if (!mat)
		return ;
	i = 0;
	while (i < size)
		free(mat[i++]);
	free(mat);
	mat = NULL;
	return ;
}
