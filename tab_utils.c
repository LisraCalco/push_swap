/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:26:00 by tlegendr          #+#    #+#             */
/*   Updated: 2024/03/20 23:59:45 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_a_sorted(int *tab_a, int len_tab_a)
{
	int	i;

	i = 0;
	while (i < len_tab_a - 1)
	{
		if (tab_a[i] > tab_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	get_tab_len(int *tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}

int	get_max_value_tab(int *tab, int len_tab)
{
	int	i;
	int	max;

	i = 0;
	max = tab[i];
	while (i < len_tab)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

int	get_min_value_tab(int *tab, int len_tab)
{
	int	i;
	int	min;

	i = 0;
	min = tab[i];
	while (i < len_tab)
	{
		if (tab[i] < min && tab[i] != 0)
			min = tab[i];
		i++;
	}
	return (min);
}

int	*in_tab_replace_number_per_rank(int *tab, int tab_len)
{
	int	*tab_rank;
	int	rank;
	int	i;
	int	j;

	i = 0;
	tab_rank = malloc(sizeof(int) * (tab_len + 1));
	while (i < tab_len)
	{
		j = 0;
		rank = 1;
		while (j < tab_len)
		{
			if (tab[j] < tab[i])
				rank++;
			j++;
		}
		tab_rank[i] = rank;
		i++;
	}
	tab_rank[i] = 0;
	free(tab);
	return (tab_rank);
}
