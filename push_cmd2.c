/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cmd2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:20:30 by tlegendr          #+#    #+#             */
/*   Updated: 2024/03/20 23:51:08 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack_list **a, t_stack_list **b)
{
	rotate(a, 1, 0);
	rotate(b, 0, 0);
	ft_putstr("rr\n");
}

void	reverse_rotate(t_stack_list **stack, int is_a, int is_print)
{
	t_stack_list	*temp;
	t_stack_list	*last;

	if (get_list_size(*stack) < 2)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	temp = last;
	last = last->prev;
	last->next = NULL;
	temp->prev = NULL;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp;
	if (is_print)
	{
		if (is_a)
			ft_putstr("rra\n");
		else
			ft_putstr("rrb\n");
	}
}

void	reverse_rotate_both(t_stack_list **a, t_stack_list **b)
{
	reverse_rotate(a, 1, 0);
	reverse_rotate(b, 0, 0);
	ft_putstr("rrr\n");
}

void	copy_tab(int *tab, t_stack_list **stack_a, int len_tab)
{
	t_stack_list	*prev;
	int				i;

	i = 0;
	prev = NULL;
	while (i < len_tab)
	{
		*stack_a = (t_stack_list *)malloc(sizeof(t_stack_list));
		(*stack_a)->content = tab[i];
		(*stack_a)->prev = prev;
		(*stack_a)->next = NULL;
		prev = *stack_a;
		stack_a = &(*stack_a)->next;
		i++;
	}
	free(tab);
}

void	set_index(t_stack_list *stack)
{
	t_stack_list	*tmp;
	int				i;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		tmp->index = i++;
		tmp = tmp->next;
	}
}
