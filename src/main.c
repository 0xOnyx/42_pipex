/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:24:53 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/21 15:24:54 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_print_usage(void)
{
	ft_putstr_fd(NAME, 2);
	ft_putstr_fd(": usage =>\n\t./pipex file1 cmd1 cmd2 file2\n", 2);
}

static int	ft_check_arg(int argc)
{
	if (argc != 5)
	{
		ft_print_usage();
		return (1);
	}
	return (0);
}

void	ft_clean_exit(t_data data)
{
	close(data.pipe_fd[0]);
	close(data.pipe_fd[1]);
	close(data.file_fd_in);
	close(data.file_fd_out);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (ft_check_arg(argc)
		|| ft_init_file(&data, argv[1], argv[argc - 1])
		|| ft_init_pipe(&data)
		|| ft_init_env(&data, env)
		|| ft_init_fork(&data))
		return (1);
	if (data.child_pid_1 == 0)
		ft_first_child_process(&data, argv[2], env);
	else if (data.child_pid_2 == 0)
		ft_second_child_process(&data, argv[3], env);
	ft_clean_exit(data);
	waitpid(data.child_pid_1, NULL, 0);
	waitpid(data.child_pid_2, NULL, 0);
	return (0);
}
