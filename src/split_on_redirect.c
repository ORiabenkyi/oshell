/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_on_redirect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:42:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/02/04 15:06:43 by oriabenk         ###   ########.fr       */
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
			while (token->tokens[i])
			{
				size = 1;
				if (token->tokens[i] == '>' && token->tokens[i + 1]
					&& token->tokens[i + 1] == '>')
					size = 2;
				else if (token->tokens[i] == '>')
					size = 1;
				else if (i++ >= 0)
					continue ;
				token = split_token(token, i, size);
				break ;
			}
		token = token->next;
	}
	return (1);
}
