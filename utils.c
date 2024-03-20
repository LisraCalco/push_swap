/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:23:38 by tlegendr          #+#    #+#             */
/*   Updated: 2024/03/20 23:58:56 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	ft_atoi(const char *string)
{
	int		i;
	long	result;
	int		is_negative;

	i = 0;
	result = 0;
	is_negative = 1;
	while (string[i] == ' ' || string[i] == '\t' || string[i] == '\n'
		|| string[i] == '\v' || string[i] == '\f' || string[i] == '\r')
		i++;
	if (string[i] == '-')
		is_negative = -1;
	if (string[i] == '-' || string[i] == '+')
	{
		i++;
		if (ft_strlen((char *)string) == 1)
			return (2147483648);
	}
	while (string[i] >= '0' && string[i] <= '9')
	{
		result = result * 10 + (string[i] - '0');
		i++;
	}
	return (result * is_negative);
}
