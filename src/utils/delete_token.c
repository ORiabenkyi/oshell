/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:42:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/03/01 14:05:38 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/oshell.h"

/*
функція видаляє елемент та повертає посилання на наступний
*/

t_token	*delete_token(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	token = token->next;
	// if (tmp->tokens)
	// 	free(tmp->tokens);
	// if (tmp->extend)
	// 	free(tmp->extend);
	// free(tmp);
	return (token);
}
