/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:20:06 by oriabenk          #+#    #+#             */
/*   Updated: 2025/01/26 15:14:48 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *income_str)
{
	int		length;
	int		counter;
	char	*outcome_str;

	if (income_str == NULL)
		return (NULL);
	length = ft_strlen(income_str);
	counter = 0;
	outcome_str = malloc((length + 1) * sizeof(*outcome_str));
	if (outcome_str == NULL)
		return (NULL);
	while (income_str && *income_str)
	{
		*outcome_str++ = *income_str++;
	}
	*outcome_str = '\0';
	return (outcome_str - length);
}
