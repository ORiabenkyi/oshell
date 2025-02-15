/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_io.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:42:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/02/15 14:31:13 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/oshell.h"

/*
функція що ініціалізує запуск команд
*/

void	init_io(t_command *cmd)
{
	if (!cmd->io)
	{
		cmd->io = malloc(sizeof(t_io));
		if (!cmd->io)
			return ;
		cmd->io->infile_name = NULL;
		cmd->io->outfile_name = NULL;
		cmd->io->fd_infile = -1;
		cmd->io->fd_outfile = -1;
		cmd->io->stdin_copy = -1;
		cmd->io->stdout_copy = -1;
	}
	printf("init_io: cmd->io=%p\n", cmd->io);
	printf("the end of init_io\n");
}
