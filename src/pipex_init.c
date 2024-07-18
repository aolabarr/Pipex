/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:11:46 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/18 15:33:18 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_data(int ac, char **av, char **env, t_data *data)
{
	data->childs = ac - 3;
	data->fd = open_files(av[1], av[ac - 1]);
	data->pid = malloc((sizeof(pid_t) * data->childs));
	if (!data->pid)
	{
		perror(MALLOC_ERROR_MESSAGE);
		exit(EXIT_FAILURE);
	}
	data->paths = get_paths(env);
	data->cmds = handle_arguments(data->childs, av);
	data->pipes = create_pipes(ac);
	file_redirections(data);
	data->env = env;
}

t_files	open_files(char *filename_1, char *filename_2)
{
	t_files	fd;

	fd.in = open(filename_1, O_RDONLY);
	if (fd.in == OPEN_ERROR)
	{
		perror(OPEN_ERROR_MESSAGE);
		exit(EXIT_FAILURE);
	}
	fd.out = open(filename_2, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd.out == OPEN_ERROR)
	{
		perror(OPEN_ERROR_MESSAGE);
		exit(EXIT_FAILURE);
	}
	return (fd);
}
char ***handle_arguments(int childs, char **av)
{
	char 	***args;
	int		i;

	args = malloc(sizeof(char *) * childs);
	i = 0;
	while (i < childs)
	{
		args[i] = ft_split(av[i + 2], SPACE);
		i++;
	}
	return (args);
}

int **create_pipes(int ac)
{
	int		i;
	int 	**pipes;

	i = 0;
	pipes = ft_malloc_mat(ac - 3 - 1, 2, sizeof(int));
	if (!pipes)
	{
		perror(MALLOC_ERROR_MESSAGE);
		exit(EXIT_FAILURE);
	}
	while (i < ac - 3 - 1)
	{
		if (pipe(pipes[i]) == PIPE_ERROR)
		{
			perror(PIPE_ERROR_MESSAGE);
			exit(EXIT_FAILURE);
		}
		//ft_printf("(%d, %d)\t\n", pipes[i][RD_END], pipes[i][WR_END]);
		i++;
	}
	return (pipes);
}
char	**get_paths(char **env)
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
