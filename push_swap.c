/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:48:46 by tlegendr          #+#    #+#             */
/*   Updated: 2024/03/20 23:35:30 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(int *tab)
{
	free(tab);
	ft_putstr("Error\n");
	return (1);
}

int	main(int argc, char **argv)
{
	int	*tab;
	int	i;

	i = 0;
	if (argc < 2)
		return (1);
	while (++i < argc)
		if (contain_non_digit_char(argv[i]) == 1
			|| is_fit_in_int(ft_atoi(argv[i])) == 0)
			return (error(NULL));
	i = 0;
	tab = malloc(sizeof(int) * (argc - 1));
	while (i + 1 < argc)
	{
		tab[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (check_for_duplicates(tab, argc - 1) == 0)
		return (error(tab));
	tab = in_tab_replace_number_per_rank(tab, argc - 1);
	if (check_if_a_sorted(tab, argc - 1) == 1)
		return (free(tab), 0);
	sort(tab, argc - 1);
	return (0);
}

void	free_stack(t_stack_list *stack)
{
	t_stack_list	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	sort(int *tab, int tab_len)
{
	t_stack_list	*stack_a;
	t_stack_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	copy_tab(tab, &stack_a, tab_len);
	set_index(stack_a);
	if (tab_len <= 5)
		sort_small_stack(&stack_a, &stack_b);
	else
		radix_sort(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}
