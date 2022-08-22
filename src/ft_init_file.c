/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:49:09 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/21 16:49:10 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_check_file_in(char *file)
{
	int		fd;
	char	c;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(NAME);
		return (1);
	}
	if (read(fd, &c, 1) < 0)
	{
		close(fd);
		perror(NAME);
		return (1);
	}
	close(fd);
	return (0);
}

static int	ft_check_file_out(char *file)
{
	int		fd;
	char	c;

	c = 'a';
	fd = open(file, O_RDWR | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fd < 0)
	{
		perror(NAME);
		return (1);
	}
	if (write(fd, &c, 1) < 0)
	{
		close(fd);
		perror(NAME);
		return (1);
	}
	close(fd);
	unlink(file);
	return (0);
}

int	ft_init_file(t_data *data, char *file_in, char *file_out)
{
	if (ft_check_file_in(file_in) || ft_check_file_out(file_out))
		return (1);
	data->file_fd_in = open(file_in, O_RDONLY);
	data->file_fd_out = open(file_out, O_RDWR | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	return (0);
}
