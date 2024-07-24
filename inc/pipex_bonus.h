/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:38:45 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/24 15:04:06 by aolabarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

# include "lib/libft/src/libft.h"
# include "lib/libio/libio.h"

# define INPUT_ERROR_MESSAGE  	"Incorrect arguments\n"
# define MALLOC_ERROR_MESSAGE	"Memory allocation error"
# define OPEN_ERROR_MESSAGE     "Open error"
# define PIPE_ERROR_MESSAGE		"Pipe error"
# define FORK_ERROR_MESSAGE		"Child process creation error"
# define EXECVE_ERROR_MESSAGE	"EXCVE execution error"
# define WAIT_ERROR_MESSAGE		"Wait error"
# define UNLINK_ERROR_MESSAGE	"Unlink error"

# define INPUT	1
# define MALLOC	2
# define OPEN	3
# define PIPE	4
# define FORK	5
# define EXECVE	6
# define WAIT	7
# define CMD	8
# define UNLINK	9

# define ERROR	-1
# define ACCESS	0

# define MIN_AC		5
# define OPEN_MODE 	0644
# define RD_END		0
# define WR_END		1
# define SPACE		32
# define DOTS		58
# define SLASH		"/"
# define PATH		"PATH="
# define HERE_DOC	"here_doc"

// Errores comunes del bash
# define FILE_NOT_FOUND		1
# define INVALID_ARGUMENT	2
# define PIPE_ERROR			141
# define CANNOT_EXECUTE		126
# define COMMAND_NOT_FOUND	127
# define OUT_OF_MEMORY		12
# define FORK_ERROR 		11
# define WAIT_ERROR 		10

typedef struct s_files
{
	int	in;
	int	out;
}				t_files;

typedef struct s_data
{
	t_files	fd;
	pid_t	*pid;
	int		childs;
	int		**pipes;
	char	***cmds;
	char	**env;
	char	**all_paths;
	char	**paths;
	int		hdoc;
	char	*limiter;
}				t_data;

// ERROR
void	check_input(int ac, char **av, t_data *data);
void	handle_error(t_data *data, int type);
void	handle_exit(int type);
int		is_identical_str(char *str1, char *str2);

// INIT
void	init_data(int ac, char **av, char **env, t_data *data);
t_files	open_files(char *filename_1, char *filename_2, t_data *data);
int		**create_pipes(t_data *data);
char	***handle_arguments(t_data *data, char **av);
char	**get_all_paths(char **env);

// INIT 2
void	memory_allocation(t_data *data, char **av);
void	file_redirections(t_data *data);
void	read_stdin(t_data *data);
int		create_temp_file(t_data *data);

//EXE
void	init_execution(t_data *data);
char	*get_path(char **paths, char *cmd);
void	exe_child(t_data *data, char *pathname, int child);
void	close_pipes(t_data *data);
void	wait_childs(t_data *data);

//UTILS
int		**ft_malloc_mat_int(int x, int y, int size);
void	ft_free_mat_int(int **mat, int size);
void	free_all(t_data *data);
void	ft_free(char *str);
void	ft_free_mat3_str(char ***mat, size_t size);

#endif