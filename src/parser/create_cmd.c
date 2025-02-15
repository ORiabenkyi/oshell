/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:42:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/02/15 18:15:50 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/oshell.h"

/*
функція утворюю лист з вже підготовленими командами для подальшої роботи з ними
*/

static int	is_add(t_token	*tock)
{
	if (ft_strncmp(tock->tokens, ">>", 3) == 0)
		return (1);
	return (0);
}

static int	is_heredoc(t_token	*tock)
{
	if (ft_strncmp(tock->tokens, "<<", 3) == 0)
		return (1);
	return (0);
}

static int	is_to_file(t_token	*tock)
{
	if (ft_strncmp(tock->tokens, ">", 2) == 0)
		return (1);
	return (0);
}

static int	is_from_file(t_token	*tock)
{
	if (ft_strncmp(tock->tokens, "<", 2) == 0)
		return (1);
	return (0);
}

t_data	*create_cmd(t_token	*tock, t_data *d)
{
	int			nnode;
	t_token		*tmp;
	t_command	*cmd;

	nnode = 0;
	tmp = tock;
	while (tmp->numberpipe == tock->numberpipe)
	{
		if (ft_strncmp(tock->tokens, "|", 2) == 0)
		{
			tmp = tmp->next;
			continue ;
		}
		if (is_heredoc(tock))
			cmd->is_piped = 0;
		else if (is_add(tock))
			cmd->is_piped = 0;
		else if (is_from_file(tock))
			cmd->is_piped = 0;
		else if (is_to_file(tock))
			cmd->is_piped = 0;
		tmp = tmp->next;
	}
}
