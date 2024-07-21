/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:39:29 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/21 22:44:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex_bonus.h"

void    print(int control, t_data *data, int ac, char **av, char **env);

int	main(int ac, char **av, char **env)
{
	t_data	data;

	check_input(ac, av, &data);
	//print(0, &data, ac, av, env);
	//if (data.hdoc == 1)
	//	read_stdin(&data);
	init_data(ac, av, env, &data);
	init_execution(&data);
	if (data.hdoc == 1)
		unlink(HERE_DOC);
	//print(1, &data, ac, av, env);
	close(data.fd.in);
	close(data.fd.out);
	free_all(&data);
	return (0);
}


