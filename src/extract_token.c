/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:42:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/02/04 15:20:26 by oriabenk         ###   ########.fr       */
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

t_token	*extract_token(t_token *d, int pos, char symbol)
{
	int		i;
	t_token	*tmp;

	i = pos;
	while (d->tokens[++i] && d->tokens[i] != symbol)
		;
	if (d->tokens[i + 1] != '\0')
	{
		tmp = create_token(ft_substr(d->tokens, i + 1,
					ft_strlen(d->tokens) - i), 0);
		add_token_after(d, tmp);
	}
	if (pos == 0)
	{
		d->tokens = ft_strrealloc(d->tokens, i);
		d->full = 1;
		return (d);
	}
	else
	{
		tmp = create_token(ft_substr(d->tokens, pos, i), 1);
		d->tokens = ft_strrealloc(d->tokens, pos);
		add_token_after(d, tmp);
	}
	return (d->next);
}
