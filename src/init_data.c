/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:42:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/02/06 14:34:24 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/oshell.h"

/*
функція слугує для початкового заповнення даних. 
в подальшому ми будемо працювати лише з оточенням що всередині

також потрібно очистити пам'ять у випадку коли ми не змогли скопіювати щось
*/

int	init_data(t_data *data, char **env)
{
	if (!init_env(data, env))
	{
		return (0);
	}
	data->pid = -1;
	data->piped = 0;
	data->heredoc = 0;
	data->redirect = 0;
	data->begin_token = NULL;
	return (1);
}
