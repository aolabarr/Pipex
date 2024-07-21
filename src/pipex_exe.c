/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:10:51 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/22 01:13:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex.h"

void	init_execution(t_data *data)
{
	int		i;
	char	*pathname;

	i = 0;
	while (i < data->childs)
	{
		pathname = get_path(data->all_paths, data->cmds[i][0]);
		if (!pathname)
			handle_error(data, CMD);
		data->pid[i] = fork();
		if (data->pid[i] == ERROR)
			handle_error(data, FORK);
		else if (data->pid[i] == 0)
			exe_child(data, pathname, i);
		data->paths[i] = pathname;
		i++;
	}
	close_pipes(data);
	wait_childs(data);
	return ;
}

char	*get_path(char **all_paths, char *cmd)
{
	char	*pathname;
	size_t	i;

	i = 0;
	while (i < ft_matsize(all_paths))
	{
		pathname = ft_strdup("");
		pathname = ft_strjoin_freed(pathname, all_paths[i]);
		pathname = ft_strjoin_freed(pathname, SLASH);
		pathname = ft_strjoin_freed(pathname, cmd);
		if (access(pathname, X_OK) == ACCESS)
			break ;
		free(pathname);
		pathname = NULL;
		i++;
	}
	return (pathname);
}

void	exe_child(t_data *data, char *pathname, int child)
{
	if (child != 0)
		dup2(data->pipes[child - 1][RD_END], STDIN_FILENO);
	if (child != data->childs - 1)
		dup2(data->pipes[child][WR_END], STDOUT_FILENO);
	close_pipes(data);
	execve(pathname, data->cmds[child], data->env);
	handle_error(data, EXECVE);
}

void	close_pipes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->childs - 1)
	{
		close(data->pipes[i][RD_END]);
		close(data->pipes[i][WR_END]);
		i++;
	}
	return ;
}

void	wait_childs(t_data *data)
{
	int	i;
	int	*status;

	status = malloc(sizeof(int) * data->childs);
	if (!status)
		handle_error(data, MALLOC);
	i = 0;
	while (i < data->childs)
	{
		if (waitpid(data->pid[i], &(status[i]), 0) == ERROR)
		{
			free(status);
			handle_error(data, WAIT);
		}
		i++;
	}
	free(status);
	return ;
}
