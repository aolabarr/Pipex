/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:21:50 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/24 19:58:35 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex.h"

void	check_input(int ac, char **av, t_data *data)
{
	size_t	i;

	if (ac != 5)
		handle_error(data, INPUT);
	i = 2;
	while (i < ft_matsize(av) - 1)
	{
		if (av[i] == NULL || av[i][0] == '\0')
			handle_error(data, PERMISSION);
		i++;
	}
	return ;
}

void	handle_error(t_data *data, int type)
{
	if (type == INPUT)
		ft_putendl_fd(INPUT_ERROR_MESSAGE, STDOUT_FILENO);
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
	else if (type == WAIT)
		perror(WAIT_ERROR_MESSAGE);
	else if (type == COMMAND)
		perror(CMD_ERROR_MESSAGE);
	else if (type == PERMISSION)
		ft_putendl_fd(PERMISSION_ERROR_MESSAGE, STDOUT_FILENO);
	if (!(type == INPUT || type == PERMISSION))
		free_all(data);
	handle_exit(type);
	return ;
}

void	handle_exit(int type)
{
	if (type == INPUT)
		exit(INVALID_ARGUMENT);
	else if (type == MALLOC)
		exit(OUT_OF_MEMORY);
	else if (type == OPEN)
		exit(EXIT_FAILURE);
	else if (type == FORK)
		exit(FORK_ERROR);
	else if (type == EXECVE)
		exit(CANNOT_EXECUTE);
	else if (type == PIPE)
		exit(PIPE_ERROR);
	else if (type == WAIT)
		exit(WAIT_ERROR);
	else if (type == COMMAND)
		exit(COMMAND_NOT_FOUND);
	exit(EXIT_FAILURE);
	return ;
}