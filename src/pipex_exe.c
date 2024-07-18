/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:10:51 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/18 20:56:33 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_execution(t_data *data)
{
	int		i;
	int		status[data->childs];
	char	*pathname;
	char	*path[data->childs];

	i  = 0;
	
	//ft_printf("Childs: %d\n", data->childs); sleep(1);
	while (i < data->childs)
	{
		pathname = get_path(data->paths, data->cmds[i][0]);
		//write(1, pathname, ft_strlen(pathname)); write(1, "\n", 1);
		//write(1, "fork()\n", 7);
		data->pid[i] = fork();
		if (data->pid[i] == FORK_ERROR)
		{
			perror(FORK_ERROR_MESSAGE); 
			exit(EXIT_FAILURE); // Liberar algo???
		}
		else if (data->pid[i] == 0)
		{
			//write(1, "Prueba A\n", 9);
			exe_child(data, pathname, i);
		}
		path[i] = pathname;
		i++;
	}
	i = 0;
	while (i < data->childs)
	{
		free(path[i]);
		i++;
	}
	close_pipes(data->pipes, data->childs);
	i = 0;
	while (i < data->childs)
	{
		if (waitpid(data->pid[i], &(status[i]), 0) == -1)
		{
            perror("waitpid failed");
            exit(EXIT_FAILURE);
		}
		//waitpid(NULL);
		i++;
		//sleep(1);
	}
	i = 0;
	
}

char	*get_path(char **paths, char *cmd)
{
	char	*pathname;
	size_t	i;

	i = 0;
	pathname = ft_strdup("");
	while (i < ft_matsize(paths))
	{
		pathname = ft_strjoin_freed(pathname, paths[i]);
		pathname = ft_strjoin_freed(pathname, SLASH);
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
	/*
	// PRINT
	size_t j = 0;
	write(1, "child num:\t", 6); write(1, ft_itoa(child), ft_strlen(ft_itoa(child)));
	write(1, "\texe:\n\t", 7);
	write(1, pathname, ft_strlen(pathname)); write(1, "\n", 1);
	while (j < ft_matsize(data->cmds[child]))
	{
		write(1, "\t", 1);
		write(1, data->cmds[child][j], ft_strlen(data->cmds[child][j]));
		j++;
	}
	write(1, "\n", 1);
	*/
	if (child != 0) // todos menos el primero proceso
	{
		//write(1, "Prueba C\n", 9);
		dup2(data->pipes[child - 1][RD_END], STDIN_FILENO);
	}
	if (child != data->childs - 1) // todos menos el ultimo proceso
	{
		//write(1, "Prueba D\n", 9);
		dup2(data->pipes[child][WR_END], STDOUT_FILENO);
	}
	close_pipes(data->pipes, data->childs);
	execve(pathname,  data->cmds[child], data->env);
	perror(EXECVE_ERROR_MESSAGE);
	exit(EXIT_FAILURE);
}
void	close_pipes(int **pipes, int childs)
{
	int	i;

	i = 0;
	while(i < childs - 1)
	{
		close(pipes[i][RD_END]);
		close(pipes[i][WR_END]);
		i++;
	}
	
	return ;
}


