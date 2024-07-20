/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:10:51 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/20 21:17:28 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    print_child(t_data *data, char *pathname, int child);

void	init_execution(t_data *data)
{
	int		i;
	char	*pathname;

	i  = 0;
	ft_printf("Childs: %d\n", data->childs);
	while (i < data->childs)
	{
		pathname = get_path(data->all_paths, data->cmds[i][0]);
		write(1, "\n", 1); write(1, pathname, ft_strlen(pathname)); write(1, "\n", 1);
		data->pid[i] = fork();
		write(1, "Prueba A\n", 9);
		if (data->pid[i] == FORK_ERROR)
		{
			perror(FORK_ERROR_MESSAGE); 
			exit(EXIT_FAILURE); // Liberar algo???
		}
		else if (data->pid[i] == 0)
		{
			write(1, "Prueba B\n", 9);
			exe_child(data, pathname, i);
		}
		else
		{
			if (i == 0)
			{
				write(1, "Prueba C\n", 9);
				write_here_doc(data);
			}
		}	
		data->paths[i] = pathname;
		i++;
	}
	close_pipes(data);
	//sleep(3);
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
	close_pipes(data);
	execve(pathname,  data->cmds[child], data->env);
	perror(EXECVE_ERROR_MESSAGE);
	exit(EXIT_FAILURE);
}
void	close_pipes(t_data *data)
{
	int	i;

	i = 0;
	if (data->hdoc == 1)
		i++;
	while(i < data->childs - 1)
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
void	write_here_doc(t_data *data)
{
	if (data->hdoc == 1)
	{
		close(data->pipes[0][RD_END]);
		write(data->pipes[0][WR_END], data->here_doc, ft_strlen(data->here_doc));
		close(data->pipes[0][WR_END]);
	}
	return ;
}



