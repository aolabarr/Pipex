/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:30:19 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/20 20:40:09 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	**ft_malloc_mat_int(int x, int y, int size)
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
void	free_all(t_data *data)
{
	int	i;

	free(data->pid);
	ft_free_mat_int(data->pipes, data->childs - 1);
	i = 0;
	while (i < data->childs)
	{
		ft_free_mat_str(data->cmds[i], ft_matsize(data->cmds[i]));
		i++;
	}
	free(data->cmds);
	ft_free_mat_str(data->all_paths, ft_matsize(data->all_paths));
	ft_free_mat_str(data->paths, ft_matsize(data->paths));
	ft_free(data->limiter);
	ft_free(data->here_doc);
	data->pid = NULL;
	data->pipes = NULL;
	data->cmds = NULL;
	data->all_paths = NULL;
	data->paths = NULL;
	data->limiter = NULL;
	data->here_doc = NULL;
}
void	ft_free(char *str)
{
	if (str)
		free(str);
	return ;
}

