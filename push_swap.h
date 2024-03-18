/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:36:35 by tlegendr          #+#    #+#             */
/*   Updated: 2024/03/18 16:06:44 by tlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack_list
{
	int                 content;
	int                 index;
	int 			  	is_target;
	struct s_stack_list	*prev;
	struct s_stack_list	*next;
}	t_stack_list;

int	check_for_arg_validity(int argc, char **argv, t_stack_list *stack_a);
void free_stack(t_stack_list *stack);
void print_stack(t_stack_list *stack);
void copy_tab(int *tab_a, t_stack_list *stack_a, int len_tab);
void add_element_to_stack(t_stack_list **stack, int content);
void set_index(t_stack_list *stack);
int	is_number(char character);
int	ft_atoi(const char *string);
int	is_fit_in_int(int number);
int	contain_non_digit_char(char *str);
int	check_for_duplicates(int *tab, int len_tab);
void ft_putstr(char *str);

void	execute_coups(int *target, t_stack_list **stack_a, t_stack_list **stack_b);

void turkish_sort(t_stack_list **stack_a, t_stack_list **stack_b);

int get_list_size(t_stack_list *stack);
void swap(t_stack_list *stack, int is_a, int is_print);
void swap_both(t_stack_list *a, t_stack_list *b);
void push(t_stack_list **from, t_stack_list **to, int is_a);
void rotate(t_stack_list **stack, int is_a, int is_print);
void rotate_both(t_stack_list **a, t_stack_list **b);
void reverse_rotate(t_stack_list **stack, int is_a, int is_print);
void reverse_rotate_both(t_stack_list **a, t_stack_list **b);

int get_min_value_index(t_stack_list **stack);
int	sort_stack_three(t_stack_list **tabA);


int sort_small_stack(t_stack_list **stack_a);

void	radix_sort(t_stack_list **stack_a, t_stack_list **stack_b);

void	ft_sort_big_list(t_stack_list **stack_a, t_stack_list **stack_b);

int find_target(t_stack_list **stack, int len_stack, int to_find);
int get_max_value_index(t_stack_list **stack);
int **set_target(t_stack_list **stack_a, t_stack_list **stack_b, int isRev);
int *find_cheapest(t_stack_list **stack_a, t_stack_list **stack_b, int isRev);
int max_value(int val1, int val2);

int get_max_value(t_stack_list **stack);

#endif