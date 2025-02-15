/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_opened_bracket.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:42:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/02/15 15:31:43 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/oshell.h"

/*
функція обробляє рядок від позиції до початку
коли рядок може бути закритий тоді (навіть до завершення строки)
повертає 1 в іншому випадку 0 (дужки не виходить закрити)
*/

int	is_opened_bracket(char *string, int position)
{
	int	i;
	int	counter;

	counter = 1;
	i = position;
	while (i--)
	{
		if (string[i] == '(')
			counter--;
		if (string[i] == ')')
			counter++;
		if (counter == 0)
			break ;
	}
	return (counter);
}
