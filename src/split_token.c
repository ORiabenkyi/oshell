/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:42:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/01/25 18:22:22 by oriabenk         ###   ########.fr       */
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

void	split_token(t_token *d, int pos, char symbol)
{
	int		i;
	t_token	*tmp;

	i = pos;
	while (d->tokens[++i] && d->tokens[i] != symbol)
		;
	if (pos == 0 && i >= ft_strlen(d->tokens))
		return ;
	tmp = create_token(ft_substr(d->tokens, pos, pos - i), 1);
	add_token_after(d, tmp);
	if (d->tokens[i] != '\0')
	{
		tmp = create_token(ft_substr(d->tokens, pos - i, ft_strlen(d->tokens)), 0);
		add_token_after(d->next, tmp);
	}
	d->tokens = ft_strrealloc(d->tokens, pos);
}
