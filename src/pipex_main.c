/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:39:29 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/20 20:55:10 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    print(int control, t_data *data, int ac, char **av, char **env);

int	main(int ac, char **av, char **env)
{
	t_data	data;

	check_input(ac, av, &data);
	//print(0, &data, ac, av, env);
	if (data.hdoc == 1)
		read_stdin(&data);
	init_data(ac, av, env, &data);
	if(data.here_doc)
		ft_printf("\nhere doc:\n%s\n", data.here_doc);
	init_execution(&data);
	close(data.fd.in);
	//print(1, &data, ac, av, env);
	close(data.fd.in);
	close(data.fd.out);
	free_all(&data);
}

void	check_input(int ac, char **av, t_data *data)
{
	if (ac < MIN_AC)
	{
		ft_putstr_fd(INPUT_ERROR_MESSAGE, STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	if (!(ft_strncmp(av[1], HERE_DOC, ft_strlen(HERE_DOC))) 
			|| ft_strlen(av[1]) == ft_strlen(HERE_DOC))
		data->hdoc = 1;
	else
		data->hdoc = 0;
}

void	read_stdin(t_data *data)
{
	char	*buffer;
	char	*here_doc;
	int		bytes_read;

	bytes_read = 1;
	here_doc = ft_strdup("");
	buffer = ft_strdup("");
	while (buffer != NULL)
	{
		if(buffer)
			ft_free(buffer);
		buffer = get_next_line(STDIN_FILENO);
		if (!buffer)
			break;
		here_doc = ft_strjoin_freed(here_doc, buffer);
	}
	data->here_doc = here_doc;	
}

