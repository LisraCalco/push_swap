/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:26:58 by tlegendr          #+#    #+#             */
/*   Updated: 2024/03/20 23:48:10 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_coup(t_stack_list **tab_a, int coup)
{
	int	len_tab;
	int	i;

	i = 0;
	len_tab = get_list_size(*tab_a);
	if (coup < len_tab - coup)
	{
		return (coup);
	}
	else
	{
		return ((len_tab - coup) * -1);
	}
}

void	execute_coups(int coup, t_stack_list **tab_a, int is_a)
{
	int	i;

	i = 0;
	if (coup > 0)
	{
		while (i < coup)
		{
			rotate(tab_a, is_a, 1);
			i++;
		}
	}
	else if (coup < 0)
	{
		coup *= -1;
		while (i < coup)
		{
			reverse_rotate(tab_a, is_a, 1);
			i++;
		}
	}
}

int	get_min_value(t_stack_list **stack)
{
	int				i;
	int				min;
	t_stack_list	*tmp;

	i = 0;
	min = get_max_value(stack) + 1;
	tmp = *stack;
	while (tmp != NULL)
	{
		if (min > tmp->content)
		{
			min = tmp->content;
		}
		i++;
		tmp = tmp->next;
	}
	return (min);
}

void	process_test(t_stack_list **stack_a,
					t_stack_list **stack_b, int size, int max_bits)
{
	t_stack_list	*tmp;
	int				i;
	int				j;

	tmp = *stack_a;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((tmp->content >> i) & 1) == 0)
				push(stack_a, stack_b, 0);
			else
				rotate(stack_a, 1, 1);
			tmp = *stack_a;
			j++;
		}
		while (get_list_size(*stack_b) > 0)
		{
			push(stack_b, stack_a, 1);
			tmp = *stack_a;
		}
		i++;
	}
}

void	radix_sort(t_stack_list **stack_a, t_stack_list **stack_b)
{
	int				size;
	int				max_num;
	int				max_bits;
	t_stack_list	*tmp;

	tmp = *stack_a;
	size = get_list_size(*stack_a);
	max_bits = 0;
	max_num = get_max_value(stack_a);
	while ((max_num >> max_bits) != 0)
		++max_bits;
	process_test(stack_a, stack_b, size, max_bits);
}
