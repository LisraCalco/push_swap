/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:24:30 by tlegendr          #+#    #+#             */
/*   Updated: 2024/03/20 23:59:17 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_fit_in_int(long number)
{
	if (number > 2147483647 || number < -2147483648)
		return (0);
	return (1);
}

int	contain_non_digit_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i != 0 && (str[i] == '-' || str[i] == '+'))
			return (1);
		if (is_number(str[i]) == 0 && (str[i] != '-' && str[i] != '+'))
			return (1);
		i++;
	}
	if (i > 11)
		return (1);
	return (0);
}

int	check_for_duplicates(int *tab, int len_tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < len_tab)
	{
		j = i + 1;
		while (j < len_tab)
		{
			if (tab[i] == tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_if_sorted(t_stack_list *stack)
{
	t_stack_list	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_number(char character)
{
	if (character >= '0' && character <= '9')
		return (1);
	return (0);
}
