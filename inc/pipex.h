/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:38:45 by aolabarr          #+#    #+#             */
/*   Updated: 2024/07/22 01:35:57 by marvin           ###   ########.fr       */
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
 
# define INPUT_ERROR_MESSAGE  	"Incorrect arguments\n"
# define MALLOC_ERROR_MESSAGE	"Memory allocation error"
# define OPEN_ERROR_MESSAGE     "Open error"
# define PIPE_ERROR_MESSAGE		"Pipe error"
# define FORK_ERROR_MESSAGE		"Child process creation error"
# define EXECVE_ERROR_MESSAGE	"EXCVE execution error"
# define WAIT_ERROR_MESSAGE		"Wait error"
# define UNLINK_ERROR_MESSAGE	"Unlink error"
# define CMD_ERROR_MESSAGE		"Command no found"

# define INPUT	1
# define MALLOC	2
# define OPEN	3
# define PIPE	4
# define FORK	5
# define EXECVE	6
# define WAIT	7
# define CMD	8

# define ERROR	-1
# define ACCESS	0

# define OPEN_MODE 	0644
# define RD_END		0
# define WR_END		1
# define SPACE		' '
# define DOTS		':'
# define SLASH		"/"
# define PATH		"PATH="

// Errores comunes del bash
#define EXIT_FILE_NOT_FOUND 1
#define EXIT_INVALID_ARGUMENT 2
#define EXIT_PERMISSION_DENIED 13
#define EXIT_CANNOT_EXECUTE 126
#define COMMAND_NOT_FOUND 127

#define EXIT_OUT_OF_MEMORY 12 // Memoria insuficiente
#define EXIT_IO_ERROR 5       // Error de entrada/salida
#define EXIT_DEVICE_NOT_FOUND 6 // Dispositivo no encontrado
#define EXIT_TIMEOUT 124       // Tiempo de espera agotado
#define EXIT_CONFLICT 409      // Conflicto de recursos
#define EXIT_UNAVAILABLE 503   // Servicio no disponible
#define EXIT_UNSUPPORTED 415   // Operación no soportada
#define EXIT_DATA_CORRUPTION 74 // Corrupción de datos
#define EXIT_AUTH_FAILURE 401  // Fallo de autenticación
#define EXIT_NETWORK_FAILURE 104 // Fallo de red

typedef struct	s_files
{
	int in;
	int out;
}				t_files;

typedef struct	s_data
{
	t_files	fd;
	pid_t	*pid;
	int		childs;
	int		**pipes;
	char	***cmds;
	char	**env;
	char	**all_paths;
	char	**paths;
}				t_data;

//MAIN

// ERROR
void	handle_error(t_data *data, int type);

// INIT
void	init_data(int ac, char **av, char **env, t_data *data);
t_files	open_files(char *filename_1, char *filename_2, t_data *data);
char	***handle_arguments(t_data *data, char **av);
char	**get_all_paths(char **env, t_data *data);
int		**create_pipes(t_data *data);

// INIT 2
void	memory_allocation(t_data *data);
void 	file_redirections(t_data *data);

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