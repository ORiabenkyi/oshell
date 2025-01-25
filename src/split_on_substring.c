/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_on_substring.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:42:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/01/25 17:25:05 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/oshell.h"

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

	i = 0;
	token = data->begin_token;
	while (token)
	{
		while (token->tokens[i])
		{
			if (token->tokens[i] == '\'')
				symbol = '\'';
			else if (token->tokens[i] == '\"')
				symbol = '\"';
			else
			{
				i++;
				continue ;
			}
			split_token(token, i, symbol);
			break ;
		}
		token = token->next;
	}
	return (1);
}
