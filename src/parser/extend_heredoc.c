/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extend_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:42:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/03/01 14:05:47 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/oshell.h"

/*
функція обробляє лист та замінює знаки << на виклик текст
*/

static int	checkstring(t_token	*t, int i)
{
	if (t->tokens[i] == '<' && t->tokens[i + 1] && t->tokens[i + 1] == '<')
		return (2);
	else if (t->tokens[i] == '<')
		return (1);
	return (0);
}

int	extend_heredoc(t_data *data)
{
	int		i;
	t_token	*token;

	token = data->begin_token;
	while (token)
	{
		i = 0;
		if (!token->full)
		{
			while (token->tokens[i])
			{
				size = checkstring(token, i);
				if (!size)
				{
					i++;
					continue ;
				}
				token = split_token(token, i, size);
				break ;
			}
		}
		token = token->next;
	}
	return (1);
}
