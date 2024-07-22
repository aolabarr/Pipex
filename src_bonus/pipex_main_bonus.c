/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:39:29 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/23 00:27:00 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex_bonus.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;

	check_input(ac, av, &data);
	init_data(ac, av, env, &data);
	init_execution(&data);
	if (data.hdoc == 1)
		unlink(HERE_DOC);
	close(data.fd.in);
	close(data.fd.out);
	free_all(&data);
	return (0);
}
