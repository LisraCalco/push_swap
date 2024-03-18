#include "push_swap.h"

int find_target(t_stack_list **stack, int len_stack, int to_find)
{
	int i;
	int target;
	int index;
	t_stack_list *tmp;

	i = 0;
	target = 0;
	index = -1; 
	tmp = *stack;
	while (i < len_stack && tmp != NULL)
	{
		if (tmp->content < to_find && target < tmp->content)
		{
			target = tmp->content;
			index = i;
		}
		i++;
		tmp = tmp->next;
	}
	if (index == -1) // Check if no valid target found
	{
		index = get_max_value_index(stack);
	}
	//printf("Potential target for %d is %d at index %d with coup %d\n", target, tab_a[index], index, calculate_coup(tab_a, index));
	//index = calculate_operation(tab_a, index);
	return (index);
}

int find_target_rev(t_stack_list **stack, int len_stack, int to_find)
{
	int	i;
	int	target;
	int	index;
	t_stack_list *tmp;

	i = 0;
	target = get_max_value(stack) + 1;
	index = -1;
	tmp = *stack;
	while (i < len_stack && tmp != NULL)
	{
		if (tmp->content > to_find && target > tmp->content)
		{
			target = tmp->content;
			index = i;
		}
		i++;
		tmp = tmp->next;
	}
	if (index == -1)
	{
		index = get_min_value_index(stack);
	}
	//printf("Returned rev target for %d is %d at index %d\n", to_find, tab[index], index);
	//index = calculate_operation(tab, index);
	return (index);
}

int get_max_value_index(t_stack_list **stack)
{
	int i;
	int max;
	int index;
	t_stack_list *tmp;

	i = 0;
	max = 0;
	index = 0;
	tmp = *stack;
	while (tmp != NULL)
	{
		if (max < tmp->content)
		{
			max = tmp->content;
			index = i;
		}
		i++;
		tmp = tmp->next;
	}
	//free_stack(tmp);
	printf("Max value is %d at index %d\n", max, index);
	return (index);
}

int get_min_value_index(t_stack_list **stack)
{
	int i;
	int min;
	int index;
	t_stack_list *tmp;

	i = 0;
	min = get_max_value(stack) + 1;
	index = 0;
	tmp = *stack;
	while (tmp != NULL)
	{
		if (min > tmp->content)
		{
			min = tmp->content;
			index = i;
		}
		i++;
		tmp = tmp->next;
	}
	//free_stack(tmp);
	printf("Min value is %d at index %d\n", min, index);
	return (index);
}

int get_max_value(t_stack_list **stack)
{
	int i;
	int min;
	t_stack_list *tmp;

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
	free_stack(tmp);
	return (min);
}


int **set_target(t_stack_list **stack_a, t_stack_list **stack_b, int isRev)
{
	int **targets;
	int i;
	int len_tab;

	if (isRev == 0)
		len_tab = get_list_size(*stack_b);
	else
		len_tab = get_list_size(*stack_a);
	
	targets = malloc(sizeof(int*) * (len_tab + 1));
	
	i = 0;
	t_stack_list *tmp;

	if (isRev == 0)
		tmp = *stack_b;
	else
		tmp = *stack_a;
	while (tmp != NULL)
	{
		targets[i] = malloc(sizeof(int) * 2);
		if (isRev == 0)
		{
			targets[i][1] = find_target(stack_b, get_list_size(*stack_b), tmp->content);
			targets[i][0] = i;
			tmp = tmp->next;
		}
		else
		{
			targets[i][0] = find_target_rev(stack_a, get_list_size(*stack_a), tmp->content);
			targets[i][1] = i;
			tmp = tmp->next;
		}
		i++;
	}
	//free_stack(tmp);
	targets[i] = NULL;
	//print targets
	i = 0;
	while (targets[i] != NULL)
	{
		printf("setA %d B %d\n", targets[i][0], targets[i][1]);
		i++;
	}
	return (targets);
}



int *find_cheapest(t_stack_list **stack_a, t_stack_list **stack_b, int isRev)
{
	int **targets;
	int i;
	int len_tab_a;
	int len_tab_b;
	int push_cost;
	int *cheapest;

	len_tab_a = get_list_size(*stack_a);
    len_tab_b = get_list_size(*stack_b);
	targets = set_target(stack_a, stack_b, isRev);
	cheapest = malloc(sizeof(int) * 2);
	push_cost = 2147483647;
	i = 0;
	//print len
	printf("len_tab_a is %d\n", len_tab_a);
	printf("len_tab_b is %d\n", len_tab_b);
	//print targets
	while (targets[i] != NULL)
	{
		printf("findA %d B %d\n", targets[i][0], targets[i][1]);
		i++;
	}
	i = 0;
	while (targets[i] != NULL)
	{
		if ((targets[i][0] < len_tab_a / 2) && (targets[i][1] < len_tab_b / 2))
		{
			if (push_cost > max_value(targets[i][0], targets[i][1]))
			{
				push_cost = max_value(targets[i][0], targets[i][1]);
				cheapest[0] = targets[i][0];
				cheapest[1] = targets[i][1];
			}
		}
		else if ((targets[i][0] > len_tab_a / 2) && (targets[i][1] > len_tab_b / 2))
		{
			if (push_cost > max_value(len_tab_a - targets[i][0], len_tab_b - targets[i][1]))
			{
				push_cost = max_value(len_tab_a - targets[i][0], len_tab_b - targets[i][1]);
				cheapest[0] = targets[i][0];
				cheapest[1] = targets[i][1];
			}
		}
		else if ((targets[i][0] < len_tab_a / 2) && (targets[i][1] > len_tab_b / 2))
		{
			if (push_cost > targets[i][0] + len_tab_b - targets[i][1])
			{
				push_cost = targets[i][0] + len_tab_b - targets[i][1];
				cheapest[0] = targets[i][0];
				cheapest[1] = targets[i][1];
			}
		}
		else 
		{
			if (push_cost > len_tab_a - targets[i][0] + targets[i][1])
			{
				push_cost = len_tab_a - targets[i][0] + targets[i][1];
				cheapest[0] = targets[i][0];
				cheapest[1] = targets[i][1];
			}
		}
		i++;
	}
	printf("Cheapest is A %d B %d with a cost of %d\n", cheapest[0], cheapest[1], push_cost);
	int tmp = cheapest[0];
	cheapest[0] = cheapest[1];
	cheapest[1] = tmp;
	return (cheapest);
}
int get_num_at_index_in_stack(t_stack_list *stack, int index)
{
	t_stack_list *tmp;
	int i;

	i = 0;
	tmp = stack;
	while (i < index)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp->content);
}

void	execute_coups(int *target, t_stack_list **stack_a, t_stack_list **stack_b)
{
	int	len_tab_a;
	int	len_tab_b;
	int num_to_top_a;
	int num_to_top_b;
	t_stack_list *tmp_stack_a;
	t_stack_list *tmp_stack_b;

	num_to_top_a = get_num_at_index_in_stack(*stack_a, target[0]);
	num_to_top_b = get_num_at_index_in_stack(*stack_b, target[1]);

	printf("num_to_top_a is %d\n", num_to_top_a);
	printf("target[0] is %d\n", target[0]);
	printf("num_to_top_b is %d\n", num_to_top_b);
	printf("target[1] is %d\n", target[1]);
	len_tab_a = get_list_size(*stack_a);
	len_tab_b = get_list_size(*stack_b);
	tmp_stack_a = *stack_a;
	tmp_stack_b = *stack_b;
	while (tmp_stack_a->content != num_to_top_a && tmp_stack_b->content != num_to_top_b)
	{
		if ((target[0] < len_tab_a / 2) && (target[1] < len_tab_b / 2))
		{
			rotate_both(stack_a, stack_b);
			target[0] = target[0] - 1;
			target[1] = target[1] - 1;
		}
		else if ((target[0] > len_tab_a / 2) && (target[1] > len_tab_b / 2))
		{
			reverse_rotate_both(stack_a, stack_b);
			target[0] = target[0] + 1;
			target[1] = target[1] + 1;
		}
		else
		{
			if (target[0] < len_tab_a / 2)
			{
				rotate(stack_a, 1, 1);
				target[0] = target[0] - 1;
			}
			else
			{
				printf("target 0 is %d\n", target[0]);
				printf("target 1 is %d\n", target[1]);
				printf("len_tab_a is %d\n", len_tab_a);
				printf("len_tab_b is %d\n", len_tab_b);
				reverse_rotate(stack_a, 1, 1);
				target[0] = target[0] + 1;
			}
		}
		if (target[0] < 0)
			target[0] = len_tab_a - 1;
		else if (target[0] > len_tab_a - 1)
			target[0] = 0;
		if (target[1] < 0)
			target[1] = len_tab_b - 1;
		else if (target[1] > len_tab_b - 1)
			target[1] = 0;
		tmp_stack_a = *stack_a;
		tmp_stack_b = *stack_b;
		len_tab_a = get_list_size(*stack_a);
		len_tab_b = get_list_size(*stack_b);
	}
	while (tmp_stack_a->content != num_to_top_a || tmp_stack_b->content != num_to_top_b)
	{
				printf("target 0 is %d\n", target[0]);
				printf("target 1 is %d\n", target[1]);
				printf("num_to_top_a is %d\n", num_to_top_a);
				printf("num_to_top_b is %d\n", num_to_top_b);
				printf("len_tab_a is %d\n", len_tab_a);
				printf("len_tab_b is %d\n", len_tab_b);
		if (tmp_stack_a->content == num_to_top_a && (target[1] < len_tab_b / 2))
		{
			rotate(stack_b, 0, 1);
			target[1] = target[1] - 1;
		}
		else if (tmp_stack_a->content == num_to_top_a && (target[1] > len_tab_b / 2))
		{
			reverse_rotate(stack_b, 0, 1);
			target[1] = target[1] + 1;
		}
		else if (tmp_stack_a->content == num_to_top_b && (target[0] < len_tab_a / 2))
		{
			rotate(stack_a, 1, 1);
			target[0] = target[0] - 1;
		}
		else
		{
			reverse_rotate(stack_a, 1, 1);
			target[0] = target[0] + 1;
		}
		
		if (target[0] < 0)
			target[0] = len_tab_a - 1;
		else if (target[0] > len_tab_a - 1)
			target[0] = 0;
		if (target[1] < 0)
			target[1] = len_tab_b - 1;
		else if (target[1] > len_tab_b - 1)
			target[1] = 0;
		tmp_stack_a = *stack_a;
		tmp_stack_b = *stack_b;
		len_tab_a = get_list_size(*stack_a);
		len_tab_b = get_list_size(*stack_b);
	}

}

int max_value(int val1, int val2)
{
	if (val1 <= val2)
		return (val2);
	else 
		return (val1);
}