/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:20:06 by oriabenk          #+#    #+#             */
/*   Updated: 2025/01/25 11:10:08 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int symbol)
{
	if (symbol == ' ' || symbol == '\t' || symbol == '\n'
		|| symbol == '\v' || symbol == '\f' || symbol == '\r')
		return (1);
	return (0);
}
