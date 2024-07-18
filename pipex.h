/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:38:45 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/18 20:40:12 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H


# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

# include "lib/libft/src/libft.h"
# include "lib/libio/libio.h"
 
# define OPEN_ERROR_MESSAGE     "Open error"
# define INPUT_ERROR_MESSAGE  	"Not enougth arguments\n"
# define PIPE_ERROR_MESSAGE		"Pipe error"
# define MALLOC_ERROR_MESSAGE	"Memory allocation error"
# define FORK_ERROR_MESSAGE		"Child process creation error"
# define EXECVE_ERROR_MESSAGE	"EXCVE execution error"


# define PIPE_ERROR -1
# define OPEN_ERROR -1
# define FORK_ERROR -1
# define ACCESS		0


# define RD_END	0
# define WR_END	1
# define SPACE	' '
# define DOTS	':'
# define SLASH	"/"
# define PATH	"PATH="



typedef struct	s_files
{
	int in;
	int out;
}				t_files;

typedef struct	s_data
{
	t_files	fd;
	int		childs;
	pid_t	*pid;
	int		**pipes;
	char	***cmds;
	char	**paths;
	char	**env;
}				t_data;

//MAIN
void 	file_redirections(t_data *data);

// INIT
void	init_data(int ac, char **av, char **env, t_data *data);
t_files	open_files(char *filename_1, char *filename_2);
int 	**create_pipes(int ac);
char	***handle_arguments(int ac, char **av);
char	**get_paths(char **env);

//EXE
void	init_execution(t_data *data);
char	*get_path(char **paths, char *cmd);
void	exe_child(t_data *data, char *pathname, int child);
void	close_pipes(int **pipes, int childs);


//UTILS
int		**ft_malloc_mat(int x, int y, int size);
void	ft_free_mat_int(int **mat, int size);
void	free_all(t_data *data);

#endif