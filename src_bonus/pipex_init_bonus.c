/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:11:46 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/23 17:12:43 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex_bonus.h"

void	init_data(int ac, char **av, char **env, t_data *data)
{
	if (data->hdoc == 0)
		data->childs = ac - 3;
	else if (data->hdoc == 1)
		data->childs = ac - 4;
	memory_allocation(data, av);
	data->all_paths = get_all_paths(env);
	data->cmds = handle_arguments(data, av);
	data->pipes = create_pipes(data);
	if (data->hdoc == 1)
		read_stdin(data);
	data->fd = open_files(av[1], av[ac - 1], data);
	file_redirections(data);
	data->env = env;
}

t_files	open_files(char *filename_1, char *filename_2, t_data *data)
{
	t_files	fd;

	if (data->hdoc == 0)
		fd.in = open(filename_1, O_RDONLY);
	else if (data->hdoc == 1)
		fd.in = open(HERE_DOC, O_RDONLY);
	if (fd.in == ERROR)
		handle_error(data, OPEN);
	fd.out = open(filename_2, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd.out == ERROR)
		handle_error(data, OPEN);
	return (fd);
}

char	***handle_arguments(t_data *data, char **av)
{
	char	***args;
	int		i;

	args = malloc(sizeof(char *) * data->childs);
	if (!args)
		handle_error(data, MALLOC);
	i = 0;
	while (i < data->childs)
	{
		if (data->hdoc == 0)
			args[i] = ft_shlex_split(av[i + 2], SPACE);
		else if (data->hdoc == 1)
			args[i] = ft_shlex_split(av[i + 3], SPACE);
		if (!args[i])
		{
			ft_free_mat3_str(args, i);
			handle_error(data, MALLOC);
		}
		i++;
	}
	return (args);
}

int	**create_pipes(t_data *data)
{
	int		i;
	int		**pipes;

	i = 0;
	pipes = ft_malloc_mat_int(data->childs - 1, 2, sizeof(int));
	if (!pipes)
		handle_error(data, MALLOC);
	while (i < data->childs - 1)
	{
		if (pipe(pipes[i]) == ERROR)
			handle_error(data, PIPE);
		i++;
	}
	return (pipes);
}

char	**get_all_paths(char **env)
{
	size_t	i;
	int		get;
	char	**paths;

	i = 0;
	get = 0;
	while (i < ft_matsize(env) && get == 0)
	{
		if (!ft_strncmp(env[i], PATH, ft_strlen(PATH)))
		{
			paths = ft_split(env[i] + ft_strlen(PATH), DOTS);
			get = 1;
		}
		i++;
	}
	return (paths);
}
