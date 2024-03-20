/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:36:35 by tlegendr          #+#    #+#             */
/*   Updated: 2024/03/20 23:45:29 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack_list
{
	long				content;
	int					index;
	struct s_stack_list	*prev;
	struct s_stack_list	*next;
}	t_stack_list;

void	sort(int *tab, int tab_len);
void	free_stack(t_stack_list *stack);
void	copy_tab(int *tab, t_stack_list **stack_a, int len_tab);
void	set_index(t_stack_list *stack);
int		is_number(char character);
long	ft_atoi(const char *string);
int		is_fit_in_int(long number);
int		get_min_value(t_stack_list **stack);
int		get_max_value(t_stack_list **stack);

int		*in_tab_replace_number_per_rank(int *tab, int len_tab_a);

int		contain_non_digit_char(char *str);
int		check_for_duplicates(int *tab, int len_tab);
void	ft_putstr(char *str);
void	execute_coups(int coup, t_stack_list **tab_a, int is_a);

int		check_if_a_sorted(int *tab_a, int len_tab_a);

int		calculate_coup(t_stack_list **tab_a, int coup);

int		get_list_size(t_stack_list *stack);
void	swap(t_stack_list *stack, int is_a, int is_print);
void	swap_both(t_stack_list *a, t_stack_list *b);
void	push(t_stack_list **from, t_stack_list **to, int is_a);
void	rotate(t_stack_list **stack, int is_a, int is_print);
void	rotate_both(t_stack_list **a, t_stack_list **b);
void	reverse_rotate(t_stack_list **stack, int is_a, int is_print);
void	reverse_rotate_both(t_stack_list **a, t_stack_list **b);

int		sort_stack_three(t_stack_list **tabA);

int		get_num_at_index_in_stack(t_stack_list *stack, int index);
int		get_index_of_value(t_stack_list **stack, int value);
void	get_target_on_top(t_stack_list **stack, int target);

int		sort_small_stack(t_stack_list **stack_a, t_stack_list **stack_b);

void	sort_stack_five(t_stack_list **tab_a, t_stack_list **tab_b);
void	sort_stack_four(t_stack_list **tab_a, t_stack_list **tab_b);

void	radix_sort(t_stack_list **stack_a, t_stack_list **stack_b);

#endif