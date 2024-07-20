/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:10:51 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/20 13:52:51 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    print_child(t_data *data, char *pathname, int child);

void	init_execution(t_data *data)
{
	int		i;
	char	*pathname;

	i  = 0;
	while (i < data->childs)
	{
		pathname = get_path(data->all_paths, data->cmds[i][0]);
		data->pid[i] = fork();
		if (data->pid[i] == FORK_ERROR)
		{
			perror(FORK_ERROR_MESSAGE); 
			exit(EXIT_FAILURE); // Liberar algo???
		}
		else if (data->pid[i] == 0)
			exe_child(data, pathname, i);
		data->paths[i] = pathname;
		i++;
		
	}
	close_pipes(data->pipes, data->childs);
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
			break;
		free(pathname);
		pathname = NULL;
		i++;
	}
	return (pathname);
}

void	exe_child(t_data *data, char *pathname, int child)
{
	
	//print_child(data, pathname, child); //PRINT
	if (child != 0) // todos menos el primero proceso
		dup2(data->pipes[child - 1][RD_END], STDIN_FILENO);
	if (child != data->childs - 1) // todos menos el ultimo proceso
		dup2(data->pipes[child][WR_END], STDOUT_FILENO);
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
void	wait_childs(t_data *data)
{
	int	i;
	int	status[data->childs];

	i = 0;
	while (i < data->childs)
	{
		if (waitpid(data->pid[i], &(status[i]), 0) == WAIT_ERROR)
		{
            perror(WAIT_ERROR_MESSAGE);
            exit(EXIT_FAILURE); // Liberar algo???
		}
		i++;
	}
}



