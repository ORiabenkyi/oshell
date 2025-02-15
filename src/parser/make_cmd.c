/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:42:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/02/15 17:53:42 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/oshell.h"

/*
функція утворюю лист з вже підготовленими командами для подальшої роботи з ними
*/

void	make_cmd(t_data *d)
{
	int		npipe;
	t_token	*tmp;

	npipe = 0;
	tmp = d->begin_token;
	while (d->piped >= npipe)
	{
		npipe++;
		tmp = create_cmd(tmp, d);
		while (tmp && tmp->numberpipe < npipe)
		{
			ft_printf("%s!\t!", tmp->tokens);
			tmp = tmp->next;
		}
		ft_printf("\n");
	}
}
