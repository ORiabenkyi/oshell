/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_on_meta.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:42:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/02/15 14:01:12 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/oshell.h"

/*
функція утворюю лист з строками де зберігається підстроки.
розбиття відбувається 
	metacarackters (' ', '	', '\n')
Значення що повертається слугує для визначення що розбиття пройшло коректно
*/
static int	checkstring(t_token	*t, int i)
{
	int	returnint;

	returnint = 0;
	if (t->tokens[i] == ' ' || t->tokens[i] == '\t' || t->tokens[i] == '\n' )
		returnint = ft_strlen(t->tokens) - i;
	return (returnint);
}

static char	*sw(void)
{
	return (" \n\t");
}

int	split_on_meta(t_data *data)
{
	t_token	*token;
	int		i;

	token = data->begin_token;
	while (token)
	{
		i = 0;
		if (!token->full)
		{
			token->tokens = ft_strtrim(token->tokens, sw());
			while (token->tokens[i])
			{
				if (!checkstring(token, i))
				{
					i++;
					continue ;
				}
				split_token(token, i, checkstring(token, i));
				break ;
			}
		}
		token = token->next;
	}
	return (1);
}
