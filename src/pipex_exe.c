/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:10:51 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/17 21:02:55 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_execution(t_data *data)
{
	int		i;
	//int		status[data->childs];
	char	*pathname;

	i  = 0;
	write(1, "Childs:\t", 8); write(1, ft_itoa(data->childs), ft_strlen(ft_itoa(data->childs))); write(1, "\n", 1);
	while (i < data->childs)
	{
		pathname = get_path(data->paths, data->cmds[i][0]);
		write(1, pathname, ft_strlen(pathname)); write(1, "\n", 1);
		write(1, "fork()\n", 7);
		data->pid[i] = fork();
		if (data->pid[i] == FORK_ERROR)
		{
			perror(FORK_ERROR_MESSAGE); 
			exit(EXIT_FAILURE); // Liberar algo???
		}
		else if (data->pid[i] == 0)
		{
			write(1, "Prueba A\n", 9);
			exe_child(data, pathname, i);
		}
		i++;
	}
	i = 0;
	while (i < data->childs)
	{
		//wait(NULL);
		i++;
		sleep(1);
	}
}

char	*get_path(char **paths, char *cmd)
{
	char	*pathname;
	size_t	i;

	i = 0;
	while (i < ft_matsize(paths))
	{
		pathname = ft_strjoin(paths[i], SLASH);
		pathname = ft_strjoin_freed(pathname, cmd);
		if (access(pathname, X_OK) == ACCESS)
			break;
		free(pathname);
		i++;
	}
	return (pathname);
}

void	exe_child(t_data *data, char *pathname, int child)
{
	char **aux;
	//printf("Child --%d\n", child);
	if (child != 0)
	{
		write(1, "Prueba C\n", 9);
		dup2(data->pipes[child - 1][RD_END], STDIN_FILENO);
		close(data->pipes[child - 1][RD_END]);
	}
	if (child != data->childs - 1)
	{
		write(1, "Prueba D\n", 9);
		dup2(data->pipes[child][WR_END], STDOUT_FILENO);
		close(data->pipes[child][WR_END]);
	}
	size_t j = 0;
	write(1, "child num:\t", 6); write(1, ft_itoa(child), ft_strlen(ft_itoa(child))); write(1, "\n", 1);
	write(1, "exe process:\n", 13);
	write(1, pathname, ft_strlen(pathname)); write(1, "\n", 1);
	while (j < ft_matsize(data->cmds[child]))
	{
		write(1, data->cmds[child][j], ft_strlen(data->cmds[child][j]));
		write(1, "\t", 1);
		j++;
	}	
	write(1, "\n", 1);
	aux = data->cmds[child];
	execve(pathname, aux, data->env);
	perror(EXECVE_ERROR_MESSAGE);
	exit(EXIT_FAILURE);
}


