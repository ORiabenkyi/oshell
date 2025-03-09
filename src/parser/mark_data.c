/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:42:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/03/09 13:52:00 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/oshell.h"

/*
функція проставляє ознаки для кожної складової
*/

void static	mark_heredoc(t_token *token)
{
	token->is_heredoc = 1;
	if (token->next)
	{
		token->extend = token->next->tokens;
		token->next = delete_token(token->next);
	}
}

void static	mark_redirect(t_token *token, t_data *d, int type)
{
	// t_token	*tmp;

	// tmp = d->begin_token;
	// while (tmp)
	// {
	// 	if (tmp->next == token)
	// 		break ;
	// 	tmp = tmp->next;
	// }
	if (type)
	{
		if (token->next)
			token->extend = token->next->tokens;
		if (token->next)
			token->next = delete_token(token->next);
		token->is_redirect = type;
	}
}

void	mark_data(t_data *d)
{
	t_token	*tmp;

	tmp = d->begin_token;
	while (tmp)
	{
		if (ft_strncmp(tmp->tokens, "<<", 2))
			mark_heredoc(tmp);
		else if (ft_strncmp(tmp->tokens, ">>", 2))
			mark_redirect(tmp, d, 3);
		else if (ft_strncmp(tmp->tokens, ">", 1))
			mark_redirect(tmp, d, 2);
		else if (ft_strncmp(tmp->tokens, "<", 1))
			mark_redirect(tmp, d, 1);
		else if (ft_strncmp(tmp->tokens, "$", 1))
			tmp->is_variable = 1;
		else if (ft_strncmp(tmp->tokens, "|", 1))
			;
		else if (ft_strncmp(tmp->tokens, "\"", 1))
			;
		else if (ft_strncmp(tmp->tokens, "\'", 1))
			;
		tmp = tmp->next;
	}
}
