/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_init_2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:11:56 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/23 00:37:16 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex_bonus.h"
#include <stdio.h>

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
	return ;
}

void	read_stdin(t_data *data)
{
	char	*buffer;
	char	*limit;
	int		fd;

	fd = create_temp_file(data);
	limit = ft_strjoin(data->limiter, "\n");
	buffer = ft_strdup("");
	if (!buffer)
		handle_error(data, MALLOC);
	while (buffer)
	{
		if (buffer)
			ft_free(buffer);
		buffer = get_next_line(STDIN_FILENO);
		if (is_identical_str(buffer, limit))
		{
			ft_free(limit);
			ft_free(buffer);
			break ;
		}
		if (buffer)
			write(fd, buffer, ft_strlen(buffer));
	}
	close(fd);
	return ;
}

int	create_temp_file(t_data *data)
{
	int	fd;

	fd = open(HERE_DOC, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == ERROR)
		handle_error(data, OPEN);
	return (fd);
}
