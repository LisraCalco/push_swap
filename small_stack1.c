/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:21:38 by tlegendr          #+#    #+#             */
/*   Updated: 2024/03/20 23:58:25 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_small_stack(t_stack_list **tab_a, t_stack_list **tab_b)
{
	t_stack_list	*tmp;
	int				list_size;

	list_size = get_list_size(*tab_a);
	tmp = *tab_a;
	if (list_size == 2)
	{
		if (tmp->content > tmp->next->content)
			swap(*tab_a, 1, 1);
	}
	else if (list_size == 3)
		sort_stack_three(tab_a);
	else if (list_size == 4)
		sort_stack_four(tab_a, tab_b);
	else if (list_size == 5)
		sort_stack_five(tab_a, tab_b);
	return (0);
}

int	sort_stack_three(t_stack_list **tabA)
{
	t_stack_list	*tmp;
	int				content;
	int				content_next;

	tmp = *tabA;
	content = tmp->content;
	content_next = tmp->next->content;
	if (content > content_next && content < tmp->next->next->content)
		swap(*tabA, 1, 1);
	else if (content > content_next && content_next > tmp->next->next->content)
	{
		swap(*tabA, 1, 1);
		reverse_rotate(tabA, 1, 1);
	}
	else if (content > content_next && content > tmp->next->next->content)
		rotate(tabA, 1, 1);
	else if (content < content_next && content_next > tmp->next->next->content
		&& content < tmp->next->next->content)
	{
		swap(*tabA, 1, 1);
		rotate(tabA, 1, 1);
	}
	else if (content < content_next && content_next > tmp->next->next->content)
		reverse_rotate(tabA, 1, 1);
	return (0);
}

void	sort_stack_four(t_stack_list **tab_a, t_stack_list **tab_b)
{
	int				i;
	t_stack_list	*tmp;
	t_stack_list	*tmp2;

	i = 0;
	push(tab_a, tab_b, 0);
	sort_stack_three(tab_a);
	tmp = *tab_a;
	tmp2 = *tab_b;
	while (tmp != NULL && tmp->content < tmp2 ->content)
	{
		i++;
		tmp = tmp->next;
	}
	i = calculate_coup(tab_a, i);
	execute_coups(i, tab_a, 1);
	push(tab_b, tab_a, 1);
	i = get_min_value(tab_a);
	get_target_on_top(tab_a, i);
}

void	sort_stack_five(t_stack_list **tab_a, t_stack_list **tab_b)
{
	int				i;
	t_stack_list	*tmp;
	t_stack_list	*tmp2;

	get_target_on_top(tab_a, 1);
	push(tab_a, tab_b, 0);
	get_target_on_top(tab_a, 2);
	push(tab_a, tab_b, 0);
	sort_stack_three(tab_a);
	while (get_list_size(*tab_b) > 0)
	{
		tmp = *tab_a;
		tmp2 = *tab_b;
		i = 0;
		while (tmp != NULL && tmp->content < tmp2 ->content)
		{
			i++;
			tmp = tmp->next;
		}
		i = calculate_coup(tab_a, i);
		execute_coups(i, tab_a, 1);
		push(tab_b, tab_a, 1);
		i = get_min_value(tab_a);
		get_target_on_top(tab_a, i);
	}
}
