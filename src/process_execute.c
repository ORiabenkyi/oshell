/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:42:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/03/01 14:02:04 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/oshell.h"

/* 
Допоміжні функції
print_tokens - друкує строки
split_data   - розбиває строку на складові
extend_data  - робить підстановки в складових
*/
void static	print_tokens(t_token *token)
{
	while (token)
	{
		if (token->extend)
			ft_printf("token - %s!\textend - %s\tpipe - %d\n", token->tokens,token->extend, token->numberpipe);
		else
			ft_printf("%s!\tpipe - %d\n", token->tokens, token->numberpipe);
		token = token->next;
	}
}

void static	split_data(t_data *data)
{
	split_on_substring(data);
	split_on_pipe(data);
	split_on_redirect(data);
	split_on_herdoc(data);
	split_on_meta(data);
}

void static	extend_data(t_data *data)
{
	extend_heredoc(data);
	extend_variable(data);
}
/*
до цієє функції потрапляє структура з строкою введення та оточенням.
функція має перевірити строку
	 сгенерувати помилку якщо строка некоректна
	 чи передати на виконання якщо строка коректна
*/

void	process_execute(t_data *data)
{
	if (!is_valid_input(data->user_input))
		return (exit_invalid_input());
	init_list(data);
	if (!data->begin_token)
		return ;
	split_data(data);
	mark_data(data);
	extend_data(data);
	//make_cmd(data);
	//print_tokens(data->begin_token);
	if (data->piped)
		run_in_pipe(data);
	else
		execute_command(data);
}
