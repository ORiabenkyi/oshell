/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:42:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/01/23 13:22:38 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/oshell.h"

/*
функція слугує для копіювання оточення в структуру даних. 
в подальшому ми будемо працювати лише з оточенням що всередині

також потрібно очистити пам'ять у випадку коли ми не змогли скопіювати щось
*/
static int	env_var_count(char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
		i++;
	return (i);
}

int	init_env(t_data *data, char **env)
{
	int		i;

	data->env = ft_calloc(env_var_count(env) + 1, sizeof(data->env));
	if (!data->env)
		return (0);
	i = 0;
	while (env[i])
	{
		data->env[i] = ft_strdup(env[i]);
		if (!data->env[i])
			return (0); //потрібна функція для очисти масива. яка повертає 0
		i++;
	}
	return (1);
}
