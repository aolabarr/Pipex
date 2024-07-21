

#include "inc/pipex_bonus.h"

void    print(int control, t_data *data, int ac, char **av, char **env)
{
    int i = -1;
    if (control == 0)
    {
        // PRINT INFO
        ft_printf("\nMAIN INFO\n%d: %s\n%d: %s\n", data->fd.in, av[1], data->fd.out, av[ac - 1]);
        size_t j = 0;
        while (++i < data->childs)
        {
            j = 0;
            ft_printf("cmd %d: ", i);
            while (j < ft_matsize(data->cmds[i]))
                ft_printf("%s\t", data->cmds[i][j++]);
            ft_printf("\n");
        }
        //PRINT PIPES
        i = -1;
        while(++i < data->childs - 1)
            ft_printf("pipe %d: fd = (%d, %d)\n", i, data->pipes[i][RD_END], data->pipes[i][WR_END]);
        
        // PRINT ENV
        j = -1;
        while (++j < ft_matsize(env))
        {
            //ft_printf("%s\n", env[j]);
        }
            
        // PRINT PATH
        j = -1;
        while (data->all_paths[++j] != NULL)
            ft_printf("PATH: %s\n", data->all_paths[j]);  
        ft_printf("Childs: %d\n", data->childs);
        ft_printf("*****\n");
    }
    else if (control == 1)
	{
        //PRINT PID
        i = -1;
        while(++i < data->childs)
        {
            ft_printf("child %d: pid = %d\n", i, data->pid[i]);
        } 
    }
	return ;
}
void    print_child(t_data *data, char *pathname, int child)
{
    size_t j = 0;
	write(1, "child num:\t", 6); write(1, ft_itoa(child), ft_strlen(ft_itoa(child)));
	write(1, "\texe:\n\t", 7);
	write(1, pathname, ft_strlen(pathname)); write(1, "\n", 1);
	while (j < ft_matsize(data->cmds[child]))
	{
		write(1, "\t", 1);
		write(1, data->cmds[child][j], ft_strlen(data->cmds[child][j]));
		j++;
	}
	write(1, "\n", 1);
}
