/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:42:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/02/07 14:35:23 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/oshell.h"

/*
функція з попереднього проекту для запуску команди
*/

void	run_command(char *argv, char **envp)
{
	char	**cmd;
	int		i;
	char	*path;

	i = -1;
	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], envp);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		//error(5);
	}
	if (execve(path, cmd, envp) == -1)
		;
		//error(6);
}
