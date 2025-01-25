/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_allocate_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:42:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/01/25 12:09:37 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/oshell.h"

/*
це буде функція для встановлення помилки та преривання обробки
*/

void	error_allocate_list(void)
{
	ft_fprintf(STDERR_FILENO,"Cann`t allocate memorry for list\n");
	return ;
}
