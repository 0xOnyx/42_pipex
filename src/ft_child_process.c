/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_child_process.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 00:51:55 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/22 00:51:56 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_free_split(char **list)
{
	int	i;

	i = 0;
	while (list[i] != NULL)
	{
		free(list[i]);
		i++;
	}
	free(list);
}

static char	*ft_get_cmd(char *prog_name, char *env_path)
{
	char	*tmp;
	char	*join;
	char	**path;
	int		i;

	path = ft_split(env_path, ':');
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		join = ft_strjoin(tmp, prog_name);
		free(tmp);
		if (access(join, X_OK) == 0)
		{
			ft_free_split(path);
			return (join);
		}
		free(join);
		i++;
	}
	ft_free_split(path);
	return (prog_name);
}

int	ft_first_child_process(t_data *data, char *cmd, char **env)
{
	char	**arg;
	char	*cmd_path;

	if (dup2(data->pipe_fd[1], 1) < 0
		|| dup2(data->file_fd_in, 0) < 0)
	{
		perror(NAME);
		return (1);
	}
	close(data->pipe_fd[0]);
	close(data->file_fd_out);
	arg = ft_split(cmd, ' ');
	cmd_path = ft_get_cmd(arg[0], data->env_path);
	if (execve(cmd_path, arg, env) < 0)
	{
		perror(NAME);
		ft_free_split(arg);
		return (1);
	}
	return (0);
}

int	ft_second_child_process(t_data *data, char *cmd, char **env)
{
	char	**arg;
	char	*cmd_path;

	if (dup2(data->pipe_fd[0], 0) < 0
		|| dup2(data->file_fd_out, 1) < 0)
	{
		perror(NAME);
		return (1);
	}
	close(data->pipe_fd[1]);
	close(data->file_fd_in);
	waitpid(data->child_pid_1, NULL, 0);
	arg = ft_split(cmd, ' ');
	cmd_path = ft_get_cmd(arg[0], data->env_path);
	if (execve(cmd_path, arg, env) < 0)
	{
		perror(NAME);
		ft_free_split(arg);
		return (1);
	}
	return (0);
}
