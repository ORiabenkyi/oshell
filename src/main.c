/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:14:06 by oriabenk          #+#    #+#             */
/*   Updated: 2025/02/01 11:44:45 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/oshell.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

/*
run lola, run !!!
*/

int	main(int counter, char *arg[], char *envr[])
{
	t_data	data;

	handle_signals_global();
	ft_memset(&data, 0, sizeof(data));
	if (counter != 1)
		arg = NULL;
	if (!init_data(&data, envr))
		exit_shell (&data, EXIT_FAILURE);
	while (1)
	{
		data.user_input = readline("ohell> ");
		if (!data.user_input)
		{
			ft_printf("buy!\n");
			break ;
		}
		if (strlen(data.user_input) > 0)
		{
			add_history(data.user_input);
			process_execute(&data);
			//free_all(&data);
		}
	}
	exit_shell(&data, 0);
	return (0);
}
