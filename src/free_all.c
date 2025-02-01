/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:42:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/02/01 12:23:08 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/oshell.h"

/*
функція для очистки всіх посилань в структурі
*/

void	free_tokens(t_token *token)
{
	t_token	*tmp;

	while (token)
	{
		tmp = token;
		if (token->tokens)
			free(token->tokens);
		token = token->next;
		free(tmp);
	}
}

void	free_all(t_data *data)
{
	if (!data)
		return ;
	if (data->user_input)
		free(data->user_input);
	data->piped = 0;
	data->pid = -1;
	free_tokens(data->begin_token);
}

void	free_all_exit(t_data *data)
{
	int	i;

	ft_printf(" //не забуваємо про очистку пам'яті\n");
	if (!data)
		return ;
	if (data->env)
	{
		i = 0;
		while (data->env[i])
		{
			free(data->env[i]);
			i++;
		}
		free(data->env);
		ft_printf("ENV clean\n");
	}
	//free_all(data);
	ft_printf("EXIT -> //не забуваємо про очистку пам'яті\n");
}
