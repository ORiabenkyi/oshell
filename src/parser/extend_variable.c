/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extend_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:42:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/03/09 13:50:41 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/oshell.h"

static int	is_with_var_mark(t_token	*t)
{
	int count;

	count = 0;
	while (t->tokens[count] != '\0')
	{
		if (t->tokens[count] == '$')
			return (1);
		count++;
	}
	return (0);
}

static int	is_singl_quote(t_token	*t)
{
	int count;

	count = 0;
	while (t->tokens[count] != '\0')
	{
		if (t->tokens[count] == '$')
			return (1);
		count++;
	}
	return (0);
}
/*
функція заміняє всі входження зміних на їх значення
*/

void	extend_variable(t_data *d)
{
	t_token	*tmp;

	tmp = d->begin_token;
	while (tmp)
	{
		tmp = tmp->next;
	}
}
