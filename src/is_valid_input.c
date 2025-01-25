/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:42:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/01/25 11:13:49 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/oshell.h"

/*
функція слугує для перевірки чи є строка коректною.
коректною важається строка яка має закрити всі дужки
якщо в строці відкрити лапки то вони мають бути закриті 
чи має бути кінець рядку.
строка перед дужками, за ними та між ними має бути корректною
*/

int	is_valid_input(char *string)
{
	int	i;

	i = 0;
	if (ft_strcountchr(string, '(') != ft_strcountchr(string, ')'))
		return (0);
	while (string[i])
	{
		if (string[i] == '\'')
			while (string[++i] && string[i] != '\'')
				;
		if (string[i] == '\"')
			while (string[++i] && string[i] != '\"')
				;
		if (string[i] == '(')
			if (!is_correct_substring(string, i - 1))
				return (0);
		if (string[i] == ')')
			if (is_opened_bracket(string, i))
				return (0);
		if (string[i] == ';' || string[i] == '\\')
			return (0);
		if (string[i])
			i++;
	}
	return (1);
}
