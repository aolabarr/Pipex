/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:39:29 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/18 15:37:58 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;
	
	if (ac < 5)
		return(ft_putstr_fd(INPUT_ERROR_MESSAGE, STDOUT_FILENO), EXIT_FAILURE);
	init_data(ac, av, env, &data);
	
	// PRINT INFO
	ft_printf("\nMAIN INFO\n%d: %s\n%d: %s\n", data.fd.in, av[1], data.fd.out, av[ac - 1]);
	int i  = -1;
	size_t j = 0;
	while (++i < ac - 3)
	{
		j = 0;
		ft_printf("cmd %d: ", i);
		while (j < ft_matsize(data.cmds[i]))
			ft_printf("%s\t", data.cmds[i][j++]);
		ft_printf("\n");
	}
	//PRINT PIPES
	i = -1;
	while(++i < data.childs - 1)
		ft_printf("pipe %d: fd = (%d, %d)\n", i, data.pipes[i][RD_END], data.pipes[i][WR_END]);
	/*
	// PRINT ENV
	j = -1;
	while (++j < ft_matsize(env))
		ft_printf("%s\n", env[j]);
	// PRINT PATH
	j = -1;
	while (data.paths[++j] != NULL)
		ft_printf("PATH: %s\n", data.paths[j]);
	*/	
	ft_printf("*****\n");
	
	init_execution(&data);
	//PRINT PID
	i = -1;
	while(++i < data.childs)
		ft_printf("child %d: pid = %d\n", i, data.pid[i]);
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







