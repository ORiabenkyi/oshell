/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:42:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/02/12 14:36:13 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/oshell.h"

/*
функція з попереднього проекту для запуску команди
*/

void	second_process(char **argv, char **envp, int *filedesc)
{
	int		fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		error(2);
	dup2(filedesc[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(filedesc[1]);
	run_command(argv[3], envp);
}
