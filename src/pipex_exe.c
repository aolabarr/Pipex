/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:10:51 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/15 20:44:51 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_execution(t_data *data)
{
	int		i;
	int		status[data->childs];
	char	*pathname;

	i  = 0;
	while (i < data->childs)
	{
		pathname = get_path(data->paths, data->cmds[i][1]);
		data->pid[i] = fork();
		if (data->pid[i] == FORK_ERROR)
		{
			perror(FORK_ERROR_MESSAGE); 
			exit(EXIT_FAILURE); // Liberar algo???
		}
		else if (data->pid[i] == 0)
			exe_child(data, pathname, i);
		else
		{

		}
		i++;
	}
	i = 0;
	while (i < data->childs)
		waitpid(data->pid[i], &(status[i]), 0);
}

char	*get_path(char **paths, char *cmd)
{
	char	*pathname;
	size_t	i;

	i = -1;
	while (i++ < ft_matsize(paths))
	{
		pathname = ft_strjoin(paths[i], cmd);
		if (access(pathname, X_OK) == N0_ACCESS)
			break;
		free(pathname);
	}
	return (pathname);
}

void	exe_child(t_data *data, char *pathname, int child)
{
	
	if (child != 0)
	{
		dup2(data->pipes[child - 1][RD_END], STDIN_FILENO);
		close(data->pipes[child - 1][RD_END]);
	}
	if (child != data->childs - 1)
	{
		dup2(data->pipes[child][WR_END], STDOUT_FILENO);
		close(data->pipes[child][WR_END]);
	}
	write(1, "child ", 6);
	printf("%d", child);
	size_t j = 0;
	while (j < ft_matsize(data->cmds[child]))
	{
		write(1, data->cmds[child][j], ft_strlen(data->cmds[child][j]));
		write(1, "\t", 1);
		j++;
	}	
	//printf("%s\t", data->cmds[child][j++]);
	//printf("\n");
	write(1, "\n", 1);

	execve(pathname, data->cmds[child], data->env);
	perror(EXECVE_ERROR_MESSAGE);
	exit(EXIT_FAILURE);
}


