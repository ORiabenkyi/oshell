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

t_token *split_token(t_token *d, int pos, char symbol)
{
	int		i;
	t_token	*tmp;

	i = pos;
	while (d->tokens[++i] && d->tokens[i] != symbol)
		;
	// if (pos == 0 && i >= ft_strlen(d->tokens))
	// 	return ;
	//ft_printf("token - !%s!\t%d\t%d\t%c\t%c\n",d->tokens,pos, i - pos, d->tokens[pos], d->tokens[i]);
	tmp = create_token(ft_substr(d->tokens, pos, i - pos + 1), 1);
	//ft_printf("token - !%s!\t%d\t%d\n",tmp->tokens,ft_strlen(tmp->tokens), i );
	add_token_after(d, tmp);
	if (d->tokens[i+1] != '\0')
	{
		tmp = create_token(ft_substr(d->tokens, i + 1, ft_strlen(d->tokens) - i), 0);
		add_token_after(d->next, tmp);
	}
	d->tokens = ft_strrealloc(d->tokens, pos);
	return (d->next);
}
