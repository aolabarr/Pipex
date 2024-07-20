/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:39:29 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/20 14:09:25 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    print(int control, t_data *data, int ac, char **av, char **env);

int	main(int ac, char **av, char **env)
{
	t_data	data;
	
	if (ac < MIN_AC)
		return(ft_putstr_fd(INPUT_ERROR_MESSAGE, STDOUT_FILENO), EXIT_FAILURE);
	init_data(ac, av, env, &data);
	//print(0, &data, ac, av, env);
	init_execution(&data);
	close(data.fd.in);
	//print(1, &data, ac, av, env);
	close(data.fd.in);
	close(data.fd.out);
	free_all(&data);
}
