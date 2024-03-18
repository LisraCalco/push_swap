#include "push_swap.h"

int get_list_size(t_stack_list *stack)
{
    int size;
    t_stack_list *temp;

    size = 0;
    temp = stack;
    while (temp)
    {
        size++;
        if (temp->next == NULL)
            break ;
        temp = temp->next;
    }
    return (size);
}

void swap(t_stack_list *stack, int is_a, int is_print)
{
    int temp;
    
    if (get_list_size(stack) < 2)
        return ;
    temp = stack->content;
    stack->content = stack->next->content;
    stack->next->content = temp;
    if (is_print)
    {
        if (is_a)
            ft_putstr("sa\n");
        else
            ft_putstr("sb\n");
    }
}

void swap_both(t_stack_list *a, t_stack_list *b)
{
    swap(a, 1, 0);
    swap(b, 0, 0);
    ft_putstr("ss\n");
}

void push(t_stack_list **from, t_stack_list **to, int is_a)
{
    t_stack_list *temp;

    if (!*from)
        return ;
    temp = *from;
    *from = (*from)->next;
    if (*from)
        (*from)->prev = NULL;
    temp->next = *to;
    if (*to)
        (*to)->prev = temp;
    *to = temp;
    if (is_a)
        ft_putstr("pa\n");
    else
        ft_putstr("pb\n");
}

void rotate(t_stack_list **stack, int is_a, int is_print)
{
    t_stack_list *temp;
    t_stack_list *last;

    if (get_list_size(*stack) < 2)
        return ;
    temp = *stack;
    *stack = (*stack)->next;
    last = *stack;
    while (last->next)
        last = last->next;
    last->next = temp;
    temp->prev = last;
    temp->next = NULL;
    if (is_print)
    {
        if (is_a)
            ft_putstr("ra\n");
        else
            ft_putstr("rb\n");
    }
}

void rotate_both(t_stack_list **a, t_stack_list **b)
{
    rotate(a, 1, 0);
    rotate(b, 0, 0);
    ft_putstr("rr\n");
}

void reverse_rotate(t_stack_list **stack, int is_a, int is_print)
{
    t_stack_list *temp;
    t_stack_list *last;

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

void reverse_rotate_both(t_stack_list **a, t_stack_list **b)
{
    reverse_rotate(a, 1, 0);
    reverse_rotate(b, 0, 0);
    ft_putstr("rrr\n");
}