/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:42:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/02/15 15:32:51 by oriabenk         ###   ########.fr       */
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

t_token	*split_token(t_token *d, int pos, int size)
{
	int		i;
	t_token	*tmp;

	if (d->tokens[pos + size] != '\0')
	{
		tmp = create_token(ft_substr(d->tokens, pos + size,
					ft_strlen(d->tokens) - pos - size + 1), 0);
		add_token_after(d, tmp);
	}
	if (pos == 0)
	{
		d->tokens = ft_strrealloc(d->tokens, size);
		return (d);
	}
	else
	{
		tmp = create_token(ft_substr(d->tokens, pos, size), 0);
		d->tokens = ft_strrealloc(d->tokens, pos);
		add_token_after(d, tmp);
	}
	return (d->next);
}
