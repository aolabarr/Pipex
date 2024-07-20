/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:11:46 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/20 21:05:31 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_data(int ac, char **av, char **env, t_data *data)
{
	if (data->hdoc == 0)
		data->childs = ac - 3;
	else if (data->hdoc == 1)
		data->childs = ac - 4;
	memory_allocation(data, av);
	data->all_paths = get_all_paths(env);
	data->cmds = handle_arguments(data->childs, av, data->hdoc);
	data->pipes = create_pipes(data->childs);
	data->fd = open_files(av[1], av[ac - 1], data->hdoc);
	file_redirections(data);
	data->env = env;
}

t_files	open_files(char *filename_1, char *filename_2, int hdoc)
{
	t_files	fd;

	if (hdoc == 0)
	{
		fd.in = open(filename_1, O_RDONLY);
		if (fd.in == OPEN_ERROR)
		{
			perror(OPEN_ERROR_MESSAGE);
			exit(EXIT_FAILURE);
		}
	}
	fd.out = open(filename_2, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd.out == OPEN_ERROR)
	{
		perror(OPEN_ERROR_MESSAGE);
		exit(EXIT_FAILURE);
	}
	return (fd);
}
char ***handle_arguments(int childs, char **av, int hdoc)
{
	char 	***args;
	int		i;

	args = malloc(sizeof(char *) * childs);
	i = 0;
	while (i < childs)
	{
		if (hdoc == 0)
			args[i] = ft_split(av[i + 2], SPACE);
		else if(hdoc == 1)
			args[i] = ft_split(av[i + 3], SPACE);
		i++;
	}
	return (args);
}

int **create_pipes(int childs)
{
	int		i;
	int 	**pipes;

	i = 0;
	pipes = ft_malloc_mat_int(childs - 1, 2, sizeof(int));
	if (!pipes)
	{
		perror(MALLOC_ERROR_MESSAGE);
		exit(EXIT_FAILURE);
	}
	while (i < childs - 1)
	{
		if (pipe(pipes[i]) == PIPE_ERROR)
		{
			perror(PIPE_ERROR_MESSAGE);
			exit(EXIT_FAILURE);
		}
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
	while(i < ft_matsize(env) && get == 0)
	{
		if (!ft_strncmp(env[i], PATH, ft_strlen(PATH)))
		{
			paths = ft_split(env[i] + ft_strlen(PATH), DOTS);
			get = 1;
		}	
		i++;
	}
	return(paths);
}
