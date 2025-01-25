/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:42:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/01/25 18:08:46 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/oshell.h"

/*
функція утворюю лист
тут можливо змінити поведінку
у випадку коли не змогли виділити пам'ять для листа
	зараз   - повертає помилку
	можливо - вихід із програми
*/

t_token	*create_token(char *string, int fulls)
{
	t_token	*new_list;
	char	*tokenlist;

	new_list = (t_token *)malloc(1 * sizeof(t_token));
	if (new_list == NULL)
		return (NULL);
	tokenlist = ft_strdup(string);
	if (tokenlist == NULL)
	{
		free(new_list);
		return (NULL);
	}
	new_list->tokens = tokenlist;
	new_list->full = fulls;
	new_list->next = NULL;
	return (new_list);
}
