/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:42:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/01/25 17:41:19 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/oshell.h"

/*
функція для очистки всіх посилань в структурі
*/

void	free_all(t_data *data)
{
	t_token	*current;
	t_token	*next;

	current = data->begin_token;
	if (current)
	{
		while (current)
		{
			next = current->next;
			ft_printf(" %s\n", current->tokens);
			//free(current->tokens);
			//current->tokens = NULL;
			//free(current);
			current = next;
		}
		ft_printf(" //не забуваємо про очистку пам'яті\n");
	}
	if (data->user_input)
	{
		free(data->user_input);
		data->user_input = NULL;
	}
}
