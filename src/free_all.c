/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:42:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/01/26 16:21:02 by oriabenk         ###   ########.fr       */
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
			ft_printf(" %s!\t%d\n", current->tokens, ft_strlen(current->tokens));
			free(current->tokens);
			current->tokens = NULL;
			free(current);
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


void	free_all_exit(t_data *data)
{
	t_token	*current;
	t_token	*next;

	current = data->begin_token;
	if (current)
	{
		while (current)
		{
			ft_printf(" Outside\n");
			next = current->next;
			if (current->tokens != NULL)
			{
				ft_printf(" %s!\t%d\n", current->tokens, ft_strlen(current->tokens));
				//free((void *)current->tokens);
			}
			ft_printf(" Inside\n");
			current->tokens = NULL;
			//free(current);
			current = next;
		}
		ft_printf("EXIT -> //не забуваємо про очистку пам'яті\n");
	}
	if (data->user_input)
	{
		free(data->user_input);
		data->user_input = NULL;
	}
}