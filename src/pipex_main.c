/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:39:29 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/17 20:17:45 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;
	
	if (ac < 5)
		return(ft_putstr_fd(INPUT_ERROR_MESSAGE, STDOUT_FILENO), EXIT_FAILURE);
	init_data(ac, av, env, &data);
	/*
	// PRINT INFO
	write(1, "\nXXXX\n", 6);
	printf("\nMAIN INFO\n%d: %s\n%d: %s\n", data.fd.in, av[1], data.fd.out, av[ac - 1]);
	int i  = -1;
	size_t j = 0;
	while (++i < ac - 3)
	{
		j = 0;
		printf("cmd %d: ", i);
		while (j < ft_matsize(data.cmds[i]))
			printf("%s\t", data.cmds[i][j++]);
		printf("\n");
	}

	j = -1;
	while (++j < ft_matsize(env))
		printf("%s\n", env[j]);
		
	j = -1;
	while (data.paths[++j] != NULL)
		printf("PATH: %s\n", data.paths[j]);
	*/	
	init_execution(&data);
	close(data.fd.in);
	close(data.fd.out);
}
void file_redirections(t_data *data)
{
	dup2(data->fd.in, STDIN_FILENO);
	close(data->fd.in);
	dup2(data->fd.out, STDOUT_FILENO);
	close(data->fd.out);
}







