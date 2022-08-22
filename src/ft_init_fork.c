/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 00:36:58 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/22 00:37:00 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_init_fork(t_data *data)
{
	data->child_pid_1 = fork();
	if (data->child_pid_1 < 0)
	{
		perror(NAME);
		return (1);
	}
	if (data->child_pid_1 != 0)
	{
		data->child_pid_2 = fork();
		if (data->child_pid_2 < 0)
		{
			perror(NAME);
			return (1);
		}
	}
	return (0);
}
