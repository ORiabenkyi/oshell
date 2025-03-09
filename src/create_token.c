/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:42:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/03/01 14:05:38 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/oshell.h"

/*
функція утворюю ноду для листа
після цього заповнює 0 всі поля окрім строки та посилання на наступний елемент
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
	ft_bzero(new_list,sizeof(t_token));
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
