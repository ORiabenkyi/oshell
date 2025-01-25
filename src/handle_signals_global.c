/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signals_global.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:31:22 by oriabenk          #+#    #+#             */
/*   Updated: 2025/01/23 13:59:34 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/oshell.h"
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>

void	handle_signal_global(int sig);
/*
we have to go to a new line and clear the previously entered data
*/

void	handle_signal_global(int sig)
{
	if (sig == SIGINT)
	{
		ft_printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

/*
Redirect signal to ignore
or function
*/

void	handle_signals_global(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	signal(SIGINT, handle_signal_global);
}
