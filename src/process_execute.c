/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:42:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/02/04 14:12:51 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/oshell.h"

/*
до цієє функції потрапляє структура з строкою введення та оточенням.
функція має перевірити строку
	 сгенерувати помилку якщо строка некоректна
	 чи передати на виконання якщо строка коректна
*/

void static	print_tokens(t_token *token)
{
	while (token)
	{
		ft_printf("%s\n", token->tokens, token->full);
		token = token->next;
	}
}

void	process_execute(t_data *data)
{
	if (!is_valid_input(data->user_input))
		return (exit_invalid_input());
	init_list(data);
	if (!data->begin_token)
		return ;
	split_on_substring(data);
	split_on_pipe(data);
	split_on_redirect(data);
	split_on_herdoc(data);
	print_tokens(data->begin_token);
}
