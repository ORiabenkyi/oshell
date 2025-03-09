/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:42:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/02/15 15:29:24 by oriabenk         ###   ########.fr       */
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
		token = token->next;
		if (tmp->tokens)
			free(tmp->tokens);
		if (tmp->extend)
			free(tmp->extend);
		free(tmp);
	}
}

/*
очистка масива оргументів команди (можливо це буде одна строка)
*/

void	free_cmd(t_command *cmd)
{
	t_command	*tmp;

	while (cmd)
	{
		tmp = cmd;
		if (cmd->name)
			free(cmd->name);
		if (cmd->path)
			free(cmd->path);
		if (cmd->args)
		{
			while (*cmd->args)
			{
				free(*cmd->args);
			}
			free(cmd->args);
		}
		cmd = cmd->next;
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
	free_cmd(data->cmd);
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
	ft_printf("EXIT -> //не забуваємо про очистку пам'яті\n");
}
