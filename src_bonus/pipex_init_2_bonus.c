/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_init_2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:11:56 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/21 22:44:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex_bonus.h"

void	memory_allocation(t_data *data, char **av)
{
	data->pid = malloc(sizeof(pid_t) * data->childs);
	if (!data->pid)
		handle_error(data, MALLOC);
	data->paths = malloc(sizeof(char *) * (data->childs + 1));
	if (!data->paths)
		handle_error(data, MALLOC);
	data->paths[data->childs] = NULL;
	if (data->hdoc == 1)
		data->limiter = ft_strdup(av[2]);
	else
		data->limiter = NULL;
	return ;
}

void	file_redirections(t_data *data)
{
	dup2(data->fd.in, STDIN_FILENO);
	close(data->fd.in);
	dup2(data->fd.out, STDOUT_FILENO);
	close(data->fd.out);
}

void	read_stdin(t_data *data)
{
	char	*buffer;
	char	*limit;

	limit = data->limiter;
	buffer = ft_strdup("");
	if (!buffer)
		handle_error(data, MALLOC);
	while (buffer)
	{
		if(buffer)
			ft_free(buffer);
		buffer = get_next_line(STDIN_FILENO);
		write(1, buffer, ft_strlen(buffer)); write(1, "Prueba A\n", 9);
		if (!buffer)
			break;
		write(data->fd.in, buffer, ft_strlen(buffer));
		if (!ft_strncmp(buffer, limit, ft_strlen(limit))
				|| ft_strlen(buffer) == ft_strlen(limit) + 1)
			break;
	}
	return ;
}

