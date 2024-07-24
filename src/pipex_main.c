/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:39:29 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/24 19:44:36 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;

	if (ac != 5)
		handle_error(&data, INPUT);
	check_input(ac, av, &data);
	init_data(ac, av, env, &data);
	init_execution(&data);
	close(data.fd.in);
	close(data.fd.out);
	free_all(&data);
	return (0);
}


void	memory_allocation(t_data *data)
{
	int	i;

	data->pid = malloc(sizeof(pid_t) * data->childs);
	if (!data->pid)
		handle_error(data, MALLOC);
	data->paths = malloc(sizeof(char *) * (data->childs + 1));
	if (!data->paths)
		handle_error(data, MALLOC);
	i = 0;
	while (i <= data->childs)
		data->paths[i++] = NULL;
	return ;
}

void	file_redirections(t_data *data)
{
	dup2(data->fd.in, STDIN_FILENO);
	close(data->fd.in);
	dup2(data->fd.out, STDOUT_FILENO);
	close(data->fd.out);
}
