/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:39:29 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/21 23:58:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;

	if (ac != 5)
		handle_error(&data, INPUT);
	init_data(ac, av, env, &data);
	init_execution(&data);
	close(data.fd.in);
	close(data.fd.out);
	free_all(&data);
	return (0);
}

void	handle_error(t_data *data, int type)
{
	if (type == INPUT)
		ft_putstr_fd(INPUT_ERROR_MESSAGE, STDOUT_FILENO);
	else if (type == MALLOC)
		perror(MALLOC_ERROR_MESSAGE);
	else if (type == OPEN)
		perror(OPEN_ERROR_MESSAGE);
	else if (type == FORK)
		perror(FORK_ERROR_MESSAGE);
	else if (type == EXECVE)
		perror(EXECVE_ERROR_MESSAGE);
	else if (type == PIPE)
		perror(PIPE_ERROR_MESSAGE);
	free_all(data);
	exit(EXIT_FAILURE);
	return ;
}

void	memory_allocation(t_data *data)
{
	data->pid = malloc(sizeof(pid_t) * data->childs);
	if (!data->pid)
		handle_error(data, MALLOC);
	data->paths = malloc(sizeof(char *) * (data->childs + 1));
	if (!data->paths)
		handle_error(data, MALLOC);
	data->paths[data->childs] = NULL;
	return ;
}

void	file_redirections(t_data *data)
{
	dup2(data->fd.in, STDIN_FILENO);
	close(data->fd.in);
	dup2(data->fd.out, STDOUT_FILENO);
	close(data->fd.out);
}
