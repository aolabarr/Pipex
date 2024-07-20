/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_init_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:11:56 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/20 14:28:55 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	memory_allocation(t_data *data)
{
	data->pid = malloc(sizeof(pid_t) * data->childs);
	if (!data->pid)
	{
		perror(MALLOC_ERROR_MESSAGE);
		exit(EXIT_FAILURE);
	}
	data->paths = malloc(sizeof(char *) * (data->childs + 1));
	data->paths[data->childs] = NULL;
	if (!data->paths)
	{
		perror(MALLOC_ERROR_MESSAGE);
		exit(EXIT_FAILURE);
	}
}

void	file_redirections(t_data *data)
{
	dup2(data->fd.in, STDIN_FILENO);
	close(data->fd.in);
	dup2(data->fd.out, STDOUT_FILENO);
	close(data->fd.out);
}
