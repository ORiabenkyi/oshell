/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_on_substring.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:42:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/02/15 15:32:46 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/oshell.h"

/*
функція утворюю лист з строками де зберігається підстроки.
розбиття відбувається 
	за подвійними лапками
	за одинарними лапками
	за дужками
	за або (||) та (&&)
	за пайпами (|)
	за перенаправленням (>>, <<, >, <)
Значення що повертається слугує для визначення що розбиття пройшло коректно
*/

int	split_on_substring(t_data *data)
{
	t_token	*token;
	int		i;
	char	symbol;

	token = data->begin_token;
	while (token)
	{
		i = 0;
		if (!token->full)
		{
			while (token->tokens[i])
			{
				if (token->tokens[i] == '\'')
					symbol = '\'';
				else if (token->tokens[i] == '\"')
					symbol = '\"';
				else if (i++ >= 0)
					continue ;
				token = extract_token(token, i, symbol);
				break ;
			}
		}
		token = token->next;
	}
	return (1);
}
