/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:25:17 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/22 16:25:18 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_init_env(t_data *data, char **env)
{
	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
		{
			data->env_path = (*env) + 5;
			return (0);
		}
		env++;
	}
	ft_putstr_fd(NAME, 2);
	ft_putstr_fd(": PATH not found\n", 2);
	return (0);
}
