/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:19:30 by tlegendr          #+#    #+#             */
/*   Updated: 2024/03/20 23:52:27 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_value(t_stack_list **stack)
{
	int				i;
	int				min;
	t_stack_list	*tmp;

	i = 0;
	min = 0;
	tmp = *stack;
	while (tmp->next != NULL)
	{
		if (min < tmp->content)
		{
			min = tmp->content;
		}
		i++;
		tmp = tmp->next;
	}
	return (min);
}

void	get_target_on_top(t_stack_list **stack, int target)
{
	int	index;
	int	size;

	size = get_list_size(*stack);
	index = get_index_of_value(stack, target);
	if (index < size / 2)
	{
		while (get_num_at_index_in_stack(*stack, 0) != target)
		{
			rotate(stack, 1, 1);
		}
	}
	else
	{
		while (get_num_at_index_in_stack(*stack, 0) != target)
		{
			reverse_rotate(stack, 1, 1);
		}
	}
}

int	get_index_of_value(t_stack_list **stack, int value)
{
	int				i;
	t_stack_list	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp != NULL)
	{
		if (tmp->content == value)
		{
			return (i);
		}
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

int	get_num_at_index_in_stack(t_stack_list *stack, int index)
{
	t_stack_list	*tmp;
	int				i;

	i = 0;
	tmp = stack;
	while (i < index)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp->content);
}
