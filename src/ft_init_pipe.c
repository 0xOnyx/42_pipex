/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:13:32 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/21 20:13:33 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_init_pipe(t_data *data)
{
	if (pipe(data->pipe_fd) < 0)
	{
		perror(NAME);
		return (1);
	}
	return (0);
}
