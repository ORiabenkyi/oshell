/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcountchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:20:06 by oriabenk          #+#    #+#             */
/*   Updated: 2025/01/23 15:38:23 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcountchr(const char *str, int symbol)
{
	size_t	pos;
	int		counter;

	pos = 0;
	counter = 0;
	while (str[pos] != '\0')
	{
		if (str[pos] == (char)symbol)
			counter++;
		pos++;
	}
	if ((char)symbol == '\0')
		counter++;
	return (counter);
}
