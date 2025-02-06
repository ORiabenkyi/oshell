/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_on_redirect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:42:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/02/06 13:08:58 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/oshell.h"

/*
функція утворюю лист з строками де зберігається підстроки.
розбиття відбувається 
	// за подвійними лапками
	// за одинарними лапками
	// за дужками
	// за або (||) та (&&)
	// за пайпами (|)
	за перенаправленням (>>, <<, >, <)
Значення що повертається слугує для визначення що розбиття пройшло коректно
*/
static int	checkstring(t_token	*t, int i)
{
	if (t->tokens[i] == '>' && t->tokens[i + 1] && t->tokens[i + 1] == '>')
		return (2);
	else if (t->tokens[i] == '>')
		return (1);
	return (0);
}

int	split_on_redirect(t_data *data)
{
	t_token	*token;
	int		i;
	int		size;

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
