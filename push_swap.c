/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:48:46 by tlegendr          #+#    #+#             */
/*   Updated: 2024/03/18 16:07:45 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int argc, char **argv)
{
	t_stack_list	*stack_a = NULL;
	stack_a = (t_stack_list *)malloc(sizeof(t_stack_list));
	if (argc > 2)
	{
		
		if (check_for_arg_validity(argc, argv, stack_a) == 0)
		{
			printf("Error\n");
			free_stack(stack_a);
			return (0);
		}
		
	}
	free_stack(stack_a);
	return (0);
}
void free_stack(t_stack_list *stack)
{
	t_stack_list *tmp;

	while (stack)
	{
		printf("%p -> %p\n",stack, stack->next);
		tmp = stack;
		stack = stack->next;
		free(tmp);

	}
	stack = NULL;
}

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	check_for_arg_validity(int argc, char **argv, t_stack_list *stack_a)
{
	int	i;
	int *tab_a;
	t_stack_list *stack_b;

	stack_b = NULL;

	i = 1;
	while (i < argc)
	{
		if (contain_non_digit_char(argv[i]) == 1)
			return (0);
		if (is_fit_in_int(ft_atoi(argv[i++])) == 0)
			return (0);
	}
	tab_a = (int *)malloc(sizeof(int) * (argc - 1));
	i = 0;
	while (i < argc - 1)
	{
		tab_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (check_for_duplicates(tab_a, argc - 1) == 0)
		return (0);
	
	copy_tab(tab_a, stack_a, argc - 1);
	set_index(stack_a);

	if (get_list_size(stack_a) <= 3)
		sort_small_stack(&stack_a);
	else
	{
		//radix_sort(&stack_a, &stack_b);
		//ft_sort_big_list(&stack_a, &stack_b);
		turkish_sort(&stack_a, &stack_b);
	}

	//push(&stack_a, &stack_b, 0);
	//push(&stack_a, &stack_b, 0);
	//tab_a = in_tab_replace_number_per_rank(tab_a, argc - 1);
	//ft_sort_big_list(&stack_a, &stack_b);
	return (1);
}

int	sort_small_stack(t_stack_list **tab_a)
{
	t_stack_list *tmp;

	tmp = *tab_a;
	if (get_list_size(*tab_a) == 2)
	{
		if (tmp->content > tmp->next->content)
			swap(*tab_a, 1, 1);
	}
	else if (get_list_size(*tab_a) == 3)
	{

		sort_stack_three(tab_a);
	}
	return (0);
}

int	sort_stack_three(t_stack_list **tabA)
{
	t_stack_list *tmp;

	tmp = *tabA;
	if (tmp->content > tmp->next->content && tmp->content < tmp->next->next->content)
		swap(*tabA, 1, 1);
	else if (tmp->content > tmp->next->content && tmp->next->content > tmp->next->next->content)
	{
		swap(*tabA, 1, 1);
		reverse_rotate(tabA, 1, 1);
	}
	else if (tmp->content > tmp->next->content && tmp->content > tmp->next->next->content)
		rotate(tabA, 1, 1);
	else if (tmp->content < tmp->next->content && tmp->next->content > tmp->next->next->content && tmp->content < tmp->next->next->content)
	{
		swap(*tabA, 1, 1);
		rotate(tabA, 1, 1);
	}
	else if (tmp->content < tmp->next->content && tmp->next->content > tmp->next->next->content)
		reverse_rotate(tabA, 1, 1);
	return (0);
}

void turkish_sort(t_stack_list **stack_a, t_stack_list **stack_b)
{
	int	*i;
	int len_tab_a;
	
	len_tab_a = get_list_size(*stack_a);
	t_stack_list *tmp;

	tmp = *stack_a;
	//if (get_max_value(&stack_a) == tmp->content)
	//	rotate(&stack_a, 1, 1);
	push(stack_a, stack_b, 0);
	//if (get_max_value(&stack_a) == tmp->content)
	//	rotate(&stack_a, 1, 1);
	push(stack_a, stack_b, 0);
	while (get_list_size(*stack_a) > 3)
	{
		i = find_cheapest(stack_a, stack_b, 0);
		execute_coups(i, stack_a, stack_b);
		push(stack_a, stack_b, 0);
	}
	sort_stack_three(stack_a);
	while (get_list_size(*stack_b) > 0)
	{
		i = find_cheapest(stack_a, stack_b, 1);
		execute_coups(i, stack_a, stack_b);
		push(stack_b, stack_a, 1);
	}
	//min_on_top(tab_a, get_tab_len(tab_a));
}




void	radix_sort(t_stack_list **stack_a, t_stack_list **stack_b)
{
	int	size;
	int	max_num;
	int	max_bits;
	int	num;
	int	bit;
	t_stack_list *tmp;

	tmp = *stack_a;
	size = get_list_size(*stack_a);
	max_bits = 0;
	max_num = size - 1;
	while ((max_num >> max_bits) != 0)
		++max_bits;
	for (int i = 0; i <= max_bits; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			num = tmp->content;
			bit = (num >> i) & 1;
			if (bit == 0)
				push(stack_a, stack_b, 0);
			else
				rotate(stack_a, 1, 1);
			tmp = *stack_a;
		}
		while (get_list_size(*stack_b) > 0)
		{
			push(stack_b, stack_a, 1);
			tmp = *stack_a;
		}
	}
}

void print_stack(t_stack_list *stack)
{
	t_stack_list *tmp;

	tmp = stack;
	while (tmp)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
}
void copy_tab(int *tab_a, t_stack_list *stack_a, int len_tab)
{
	int	i;

	i = 0;
	while (i < len_tab)
	{
		stack_a->content = tab_a[i];
		if (i < len_tab - 1)
		{
			stack_a->next = (t_stack_list *)malloc(sizeof(t_stack_list));
			stack_a->next->prev = stack_a;
			stack_a = stack_a->next;
		}
		else
			stack_a->next = NULL;
		i++;
	}
}

int	ft_atoi(const char *string)
{
	int	i;
	int	result;
	int	is_negative;

	i = 0;
	result = 0;
	is_negative = 0;
	while (string[i] == ' ' || string[i] == '\t' || string[i] == '\n'
		|| string[i] == '\v' || string[i] == '\f' || string[i] == '\r')
		i++;
	if (string[i] == '-')
		is_negative = 1;
	if (string[i] == '-' || string[i] == '+')
		i++;
	while (string[i] >= '0' && string[i] <= '9')
	{
		result = result * 10 + (string[i] - '0');
		i++;
	}
	if (is_negative == 1)
		return (-result);
	return (result);
}

int	is_number(char character)
{
	if (character >= '0' && character <= '9')
		return (1);
	return (0);
}



void set_index(t_stack_list *stack)
{
	t_stack_list *tmp;
	int i;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		tmp->index = i++;
		tmp->is_target = 0;
		tmp = tmp->next;
	}
}



int	check_if_a_sorted(int *tab_a, int len_tab_a)
{
	int	i;

	i = 0;
	while (i < len_tab_a - 1 && tab_a[i] != 0)
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

int	is_fit_in_int(int number)
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
		if (is_number(str[i]) == 0 && (str[i] != '-' && str[i] != '+'))
			return (1);
		i++;
	}
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

int ft_check_if_sorted(t_stack_list *stack)
{
	t_stack_list *tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_sort_big_list(t_stack_list **stack_a, t_stack_list **stack_b)
{
	int	bit_pos;
	int size; 
	int count;

	size = get_list_size(*stack_a);
	bit_pos = 1;
	while (ft_check_if_sorted(*stack_a) == 0)
	{
		count = 0;
		while (*stack_a != NULL && count++ < size)
		{
			if (((*stack_a)->index & bit_pos) == 0)
			{
				push(stack_a, stack_b, 0);
			}
			else
				rotate(stack_a, 1, 1);
			ft_putstr("stuck here1\n");
		}
		while (*stack_b != NULL)
		{
			push(stack_b, stack_a, 1);
			ft_putstr("stuck here2\n");
		}
		bit_pos *= 2;
		ft_putstr("stuck here3\n");
	}
}