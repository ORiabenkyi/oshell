/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extend_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:42:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/03/01 14:05:47 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/oshell.h"

/*
функція має пройтись по всьому вводу та замінити heredoc на введену строку,
при цьому ми маємо обробляти сигнал зупинки
*/
int	extend_heredoc(t_data *data)
{
	t_token	*token;

	token = data->begin_token;
	while (token)
	{
		if (!token->full)
			;
		token = token->next;
	}
	return (1);
}
