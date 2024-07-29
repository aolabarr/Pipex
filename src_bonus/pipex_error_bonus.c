/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:30:14 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/29 10:18:23 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex_bonus.h"

void	check_input(int ac, char **av, t_data *data)
{
	size_t	i;

	if (ac < MIN_AC)
		handle_error(data, INPUT);
	data->hdoc = is_identical_str(av[1], HERE_DOC);
	if (data->hdoc == 1 && ac < MIN_AC + 1)
		handle_error(data, INPUT);
	i = 2;
	while (i < ft_matsize(av) - 1)
	{
		if (av[i] == NULL || av[i][0] == '\0')
			handle_error(data, PERMISSION);
		if (str_is_space(av[i]))
			handle_error(data, INPUT);
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
	else if (type == COMMAND)
		perror(COMMAND_ERROR_MESSAGE);
	else if (type == UNLINK)
		perror(UNLINK_ERROR_MESSAGE);
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

int	is_identical_str(char *str1, char *str2)
{
	if (!(ft_strncmp(str1, str2, ft_strlen(str2)))
		&& ft_strlen(str1) == ft_strlen(str2))
		return (1);
	else
		return (0);
}

int	str_is_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == ' ' || str[i] == '\t'))
			return (0);
		i++;
	}
	return (1);
}
