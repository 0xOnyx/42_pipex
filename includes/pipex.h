/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:24:42 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/21 15:24:43 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# define NAME "pipex"

typedef struct s_data
{
	int		file_fd_in;
	int		file_fd_out;
	int		pipe_fd[2];
	int		child_pid_1;
	int		child_pid_2;
	char	*env_path;
}	t_data;

int	ft_init_file(t_data *data, char *file_in, char *file_out);
int	ft_init_pipe(t_data *data);
int	ft_init_fork(t_data *data);
int	ft_init_env(t_data *data, char **env);

int	ft_first_child_process(t_data *data, char *cmd, char **env);
int	ft_second_child_process(t_data *data, char *cmd, char **env);

#endif
