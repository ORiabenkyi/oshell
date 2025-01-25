/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:20:06 by oriabenk          #+#    #+#             */
/*   Updated: 2025/01/25 14:52:02 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *income_str)
{
	int		length;
	int		counter;
	char	*outcome_str;

	if (!income_str)
		return (NULL);
	length = ft_strlen(income_str);
	counter = 0;
	outcome_str = (char *)malloc((length + 1) * sizeof(char));
	if (!outcome_str)
		return (NULL);
	while (counter < length)
	{
		outcome_str[counter] = income_str[counter];
		counter++;
	}
	outcome_str[counter] = '\0';
	return (outcome_str);
}
