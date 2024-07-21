/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:30:14 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/21 22:43:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex_bonus.h"

void	check_input(int ac, char **av, t_data *data)
{
	if (ac < MIN_AC)
		handle_error(data, INPUT);
	data->hdoc = is_here_doc(av[1]);
	return ;
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
	else if (type == UNLINK)
		perror(UNLINK_ERROR_MESSAGE);
	free_all(data);
	exit(EXIT_FAILURE);
	return ;
}

int	is_here_doc(char *str)
{
	if (!(ft_strncmp(str, HERE_DOC, ft_strlen(HERE_DOC))) 
			|| ft_strlen(str) == ft_strlen(HERE_DOC))
		return (1);
	else
		return (0);
}
