/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:30:19 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/21 22:44:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex_bonus.h"

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
	if (!data->pid)
		free(data->pid);
	ft_free_mat_int(data->pipes, data->childs - 1);
	free_commands(data->cmds, data->childs);
	ft_free_mat_str(data->all_paths, ft_matsize(data->all_paths));
	ft_free_mat_str(data->paths, ft_matsize(data->paths));
	ft_free(data->limiter);
	data->pid = NULL;
	data->pipes = NULL;
	data->cmds = NULL;
	data->all_paths = NULL;
	data->paths = NULL;
	data->limiter = NULL;
	return ;
}
void	ft_free(char *str)
{
	if (str)
		free(str);
	return ;
}
void	free_commands(char ***cmds, int size)
{
	int i;

	if (!cmds)
		return ;
	i = 0;
	while (i < size)
	{
		ft_free_mat_str(cmds[i], ft_matsize(cmds[i]));
		i++;
	}
	free(cmds);
	cmds = NULL;
	return ;
}

