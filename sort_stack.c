/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:39:34 by jvarila           #+#    #+#             */
/*   Updated: 2024/12/27 17:39:53 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_sorted(t_stack *stack_ptr);
void		merge_sorted_portions_and_rotate_to_end(t_two_stacks *ts_ptr);

int			first_int_larger(int a, int b);
int			first_int_smaller(int a, int b);

int			node_val(t_list *node);
int			last_element_val(t_stack *stack_ptr);
int			top_sorted_sublist_len(t_stack *stack_ptr);
int			bottom_sorted_sublist_len(t_stack *stack_ptr);
int			sublist_len(t_list *node, int order);
int			count_sorted_sublists(t_stack *stack);
void		skip_sorted_sublist(t_list **node_ptr, int order);

void		sort_three(t_two_stacks *ts_ptr);
void		sort_a_b_c(t_two_stacks *ts_ptr, int a, int b, int c);

void		normalize_stack(t_stack *stack);
t_list		*next_larger_node(t_list *lst, int num);
t_list		*next_smaller_node(t_list *lst, int num);
void		insertion_sort(t_two_stacks *ts_ptr);

t_list		*min_node(t_list *lst);

int	element_val(t_stack *stack_ptr, int index);
int	element_to_push_on_index(t_stack *stack_ptr, int num);

void	sort_stack(t_two_stacks *ts_ptr)
{
	ts_ptr->a.order = ASCENDING;
	ts_ptr->b.order = DESCENDING;
	if (stack_sorted(&ts_ptr->a))
		return ;
	if (ts_ptr->a.size == 2)
		return (sa(ts_ptr));
	if (ts_ptr->a.size == 3)
		sort_three(ts_ptr);
	normalize_stack(&ts_ptr->a);
	insertion_sort(ts_ptr);
	print_stack(&ts_ptr->a);
}

static int	stack_sorted(t_stack *stack_ptr)
{
	t_list	*node;
	int		(*comp)(int a, int b);

	if (stack_ptr->size == 1)
		return (1);
	node = stack_ptr->top;
	if (stack_ptr->order == ASCENDING)
		comp = first_int_larger;
	else
		comp = first_int_smaller;
	while (node->next)
	{
		if (comp(node_val(node), node_val(node->next)))
			return (0);
		node = node->next;
	}
	return (1);
}

void	sort_three(t_two_stacks *ts_ptr)
{
	int	first;
	int	second;
	int	third;

	first = node_val(ts_ptr->a.top);
	second = node_val(ts_ptr->a.top->next);
	third = node_val(ts_ptr->a.top->next->next);
	sort_a_b_c(ts_ptr, first, second, third);
}

// The combinations of comparisons correspong to the 5 different sortable
// cases for three numbers, for ascending order this means 1 3 2, 2 1 3,
// 2 3 1, 3 1 2 and 3 2 1. Changing the function to first_int_larger flips
// the comparisons and correctly sorts three numbers in descending order.
void	sort_a_b_c(t_two_stacks *ts_ptr, int a, int b, int c)
{
	int	(*comp)(int a, int b);

	if (ts_ptr->a.order == ASCENDING)
		comp = first_int_smaller;
	else
		comp = first_int_larger;
	if (comp(b, a) && comp(b, c) && comp(c, a))
		ra(ts_ptr);
	if (comp(a, b) && comp(c, b) && comp(c, a))
		rra(ts_ptr);
	if (comp(b, a) && comp(b, c) && comp(a, c))
		sa(ts_ptr);
	if (comp(a, b) && comp(c, b) && comp(a, c))
	{
		sa(ts_ptr);
		ra(ts_ptr);
	}
	if (comp(b, a) && comp(c, b))
	{
		sa(ts_ptr);
		rra(ts_ptr);
	}
}

// Change the values of the stack elements to be consecutive integers starting
// from 0. These values can be useful when comparing against the total size
// of the stack and when calculating the amount of moves needed.
void	normalize_stack(t_stack *stack)
{
	int		min;
	int		count;
	t_list	*node;

	if (!stack->size)
		return ;
	node = min_node(stack->top);
	count = 0;
	while (count < stack->size)
	{
		*(int *)node->content = count;
		min = node_val(node);
		node = next_larger_node(stack->top, min);
		count++;
	}
}

t_list	*min_node(t_list *lst)
{
	int		min;
	t_list	*node;

	if (!lst)
		return (NULL);
	if (!lst->next)
		return (lst);
	min = INT_MAX;
	node = NULL;
	while (lst)
	{
		if (node_val(lst) <= min)
		{
			min = node_val(lst);
			node = lst;
		}
		lst = lst->next;
	}
	return (node);
}

t_list	*max_node(t_list *lst)
{
	int		max;
	t_list	*node;

	if (!lst)
		return (NULL);
	if (!lst->next)
		return (lst);
	max = INT_MIN;
	node = NULL;
	while (lst)
	{
		if (node_val(lst) >= max)
		{
			max = node_val(lst);
			node = lst;
		}
		lst = lst->next;
	}
	return (node);
}

int	min_val(t_stack *stack_ptr)
{
	return (node_val(min_node(stack_ptr->top)));
}

int	max_val(t_stack *stack_ptr)
{
	return (node_val(min_node(stack_ptr->top)));
}

t_list	*next_larger_node(t_list *lst, int num)
{
	int		previous_min;
	int		val;
	t_list	*node;

	if (!lst)
		return (NULL);
	if (!lst->next)
		return (lst);
	previous_min = INT_MAX;
	node = NULL;
	while (lst)
	{
		val = node_val(lst);
		if (val > num && val <= previous_min)
		{
			node = lst;
			previous_min = val;
		}
		lst = lst->next;
	}
	return (node);
}

int	next_larger_val(t_stack *stack_ptr, int num)
{
	return (node_val(next_larger_node(stack_ptr->top, num)));
}

t_list	*next_smaller_node(t_list *lst, int num)
{
	int		previous_max;
	int		val;
	t_list	*node;

	if (!lst)
		return (NULL);
	if (!lst->next)
		return (lst);
	previous_max = INT_MIN;
	node = NULL;
	while (lst)
	{
		val = node_val(lst);
		if (val < num && val >= previous_max)
		{
			node = lst;
			previous_max = val;
		}
		lst = lst->next;
	}
	return (node);
}

int	next_smaller_val(t_stack *stack_ptr, int num)
{
	return (node_val(next_smaller_node(stack_ptr->top, num)));
}

void	insertion_sort(t_two_stacks *ts_ptr)
{
	int		b_min;
	int		b_max;
	int		moves_a_up;
	int		moves_a_down;
	int		moves_b_up;
	int		moves_b_down;
	int		min_cost;
	int		min_cost_element_index;
	int		i;
	t_list	*node;

	pb(ts_ptr);
	b_max = node_val(ts_ptr->b.top);
	b_min = b_max;
	while (ts_ptr->a.size > 3)
	{
		node = ts_ptr->a.top;
		i = -1;
		while (++i < ts_ptr->a.size)
		{
			moves_a_up = i;
			moves_a_down = moves_a_up - ts_ptr->a.size;
			moves_b_up = element_to_push_on_index(&ts_ptr->b, node_val(node));
			moves_b_down = moves_b_down - ts_ptr->b.size;
		}
	}
}

int	element_val(t_stack *stack_ptr, int index)
{
	t_list	*node;
	int		i;

	if (index < 0 || index >= stack_ptr->size)
		return (INT_MIN);
	node = stack_ptr->top;
	i = -1;
	while (++i < index)
		node = node->next;
	return (node_val(node));
}

int	element_index(t_stack *stack_ptr, int num)
{
	int		index;
	t_list	*node;

	index = -1;
	node = stack_ptr->top;
	while (++index < stack_ptr->size)
	{
		if (node_val(node) == num)
			return (index);
	}
	return (-1);
}

int	element_to_push_on_index(t_stack *stack_ptr, int num)
{
	int	max;
	int	min;
	int	index;

	if (stack_ptr->size < 2)
		return (0);
	max = max_val(stack_ptr);
	min = min_val(stack_ptr);
	if (stack_ptr->order == DESCENDING && (num > max || num < min))
		return (element_index(stack_ptr, max));
	if (stack_ptr->order == ASCENDING && (num > max || num < min))
		return(element_index(stack_ptr, min));
	if (stack_ptr->order == ASCENDING)
		index = element_index(stack_ptr, next_larger_val(stack_ptr, num));
	else
		index = element_index(stack_ptr, next_smaller_val(stack_ptr, num));
	return (index);
}

int	last_element_val(t_stack *stack_ptr)
{
	t_list *node;

	node = stack_ptr->top;
	if (!node)
		return (INT_MIN);
	if (!node->next)
		return (node_val(node));
	while (node->next)
		node = node->next;
	return (node_val(node));
}

int	top_sorted_sublist_len(t_stack *stack_ptr)
{
	return (sublist_len(stack_ptr->top, stack_ptr->order));
}

int	bottom_sorted_sublist_len(t_stack *stack_ptr)
{
	t_list	*node;
	int		sorted_sublists;

	sorted_sublists = count_sorted_sublists(stack_ptr) - 1;
	node = stack_ptr->top;
	while (sorted_sublists--)
		skip_sorted_sublist(&node, stack_ptr->order);
	return (sublist_len(node, stack_ptr->order));
}

int	sublist_len(t_list *node, int order)
{
	int	(*comp)(int a, int b);
	int	count;

	if (!node)
		return(0);
	if (!node->next)
		return (1);
	if (order == ASCENDING)
		comp = first_int_smaller;
	else
		comp = first_int_larger;
	count = 1;
	while (node->next && comp(node_val(node), node_val(node->next)))
	{
		node = node->next;
		count++;
	}
	return (count);
}

int	count_sorted_sublists(t_stack *stack_ptr)
{
	int		count;
	t_list	*node;

	if (stack_ptr->size == 0)
		return (0);
	count = 0;
	node = stack_ptr->top;
	while (node)
	{
		skip_sorted_sublist(&node, stack_ptr->order);
		count++;
	}
	return (count);
}

void	skip_sorted_sublist(t_list **node_ptr, int order)
{
	t_list	*node;

	node = *node_ptr;
	int	(*comp)(int a, int b);
	if (order == ASCENDING)
		comp = first_int_smaller;
	else
		comp = first_int_larger;
	while (node->next && comp(node_val(node), node_val(node->next)))
		node = node->next;
	*node_ptr = node->next;
}

int	first_int_larger(int a, int b)
{
	return (a > b);
}

int	first_int_smaller(int a, int b)
{
	return (a < b);
}

int	node_val(t_list *node)
{
	if (!node)
		return (INT_MIN);
	return (*(int *)node->content);
}
