/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token_after.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:42:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/02/06 12:36:44 by oriabenk         ###   ########.fr       */
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

t_token	*add_token_after(t_token	*list, t_token	*add_in_list)
{
	add_in_list->next = list->next;
	list->next = add_in_list;
	add_in_list->numberpipe = list->numberpipe;
	return (add_in_list);
}
