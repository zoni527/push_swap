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

#define BOTH	1
#define A		2
#define B		3

#define ASCENDING	1
#define DESCENDING	-1

static int	stack_sorted(t_stack *stack_ptr, int order);
static int	first_element_greater_than_second(t_stack *stack_ptr);
static void	merge_sort(t_two_stacks *ts_ptr);
static void	divide_and_presort(t_two_stacks *ts_ptr);
void	merge_sorted_portions_and_rotate_to_end(t_two_stacks *ts_ptr);
int	first_int_larger(int a, int b);
int	first_int_smaller(int a, int b);
void	skip_sorted_sublist(t_list **node_ptr, int order);
int	node_val(t_list *node);
int	last_element_val(t_stack *stack_ptr);
int	top_sorted_sublist_len(t_stack *stack_ptr, int order);
int	bottom_sorted_sublist_len(t_stack *stack_ptr, int order);
int	count_sublist_len(t_list *node, int order);
int	count_sorted_sublists(t_stack *stack, int order);

void	sort_stack(t_two_stacks *two_stacks_ptr)
{
	if (stack_sorted(&two_stacks_ptr->a, ASCENDING))
		return ;
	if (two_stacks_ptr->a.size == 2)
		return sa(two_stacks_ptr);
	merge_sort(two_stacks_ptr);
}

static int	stack_sorted(t_stack *stack_ptr, int order)
{
	t_list	*node;
	int		(*comp)(int a, int b);

	if (stack_ptr->size == 1)
		return (1);
	node = stack_ptr->top;
	if (order == ASCENDING)
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

static void	merge_sort(t_two_stacks *ts_ptr)
{
	int	counter;

	counter = 100000;
	divide_and_presort(ts_ptr);
	while (counter-- && (ts_ptr->b.size || !stack_sorted(&ts_ptr->a, ASCENDING)))
	{
		merge_sorted_portions_and_rotate_to_end(ts_ptr);
	}
}

// First push half of a to b and presort
static void	divide_and_presort(t_two_stacks *ts_ptr)
{
	int	groups_of_two_in_half;
	int	a_swappable;
	int	b_swappable;

	groups_of_two_in_half = ts_ptr->a.size / 4;
	if (groups_of_two_in_half == 0)
		groups_of_two_in_half++;
	while (groups_of_two_in_half--)
	{
		pb(ts_ptr);
		pb(ts_ptr);
		a_swappable = first_element_greater_than_second(&ts_ptr->a);
		b_swappable = !first_element_greater_than_second(&ts_ptr->b);
		if (a_swappable && b_swappable)
			ss(ts_ptr);
		if (a_swappable && !b_swappable)
			sa(ts_ptr);
		if (b_swappable && !a_swappable)
			sb(ts_ptr);
		ra(ts_ptr);
		ra(ts_ptr);
	}
	if ((ts_ptr->a.size + ts_ptr->b.size) % 4 != 0)
		pb(ts_ptr);
}

void	merge_sorted_portions_and_rotate_to_end(t_two_stacks *ts_ptr)
{
	int		first_sorted_sublist_len;
	int		bottom_sorted_sublist_len_a;
	int		top_sorted_sublist_len_b;
	int		sorted_sublists;

	if (!ts_ptr->a.size)
	{
		if (stack_sorted(&ts_ptr->b, DESCENDING))
		{
			while (ts_ptr->b.size)
				pa(ts_ptr);
			return ;
		}
		sorted_sublists = count_sorted_sublists(&ts_ptr->b, DESCENDING);
		sorted_sublists /= 2;
		while (sorted_sublists--)
		{
			first_sorted_sublist_len = top_sorted_sublist_len(&ts_ptr->b, DESCENDING);
			while (first_sorted_sublist_len--)
				pa(ts_ptr);
		}
	}
	if (!ts_ptr->b.size)
	{
		sorted_sublists = count_sorted_sublists(&ts_ptr->a, ASCENDING);
		sorted_sublists /= 2;
		while (sorted_sublists--)
		{
			first_sorted_sublist_len = top_sorted_sublist_len(&ts_ptr->a, ASCENDING);
			while (first_sorted_sublist_len--)
				pb(ts_ptr);
		}
	}
	bottom_sorted_sublist_len_a = bottom_sorted_sublist_len(&ts_ptr->a, ASCENDING);
	top_sorted_sublist_len_b = top_sorted_sublist_len(&ts_ptr->b, DESCENDING);
	while (bottom_sorted_sublist_len_a || top_sorted_sublist_len_b)
	{
		if (bottom_sorted_sublist_len_a && top_sorted_sublist_len_b
			&& peek(&ts_ptr->b) < last_element_val(&ts_ptr->a))
		{
			rra(ts_ptr);
			bottom_sorted_sublist_len_a--;
		}
		else if (bottom_sorted_sublist_len_a && top_sorted_sublist_len_b
			&& peek(&ts_ptr->b) > last_element_val(&ts_ptr->a))
		{
			pa(ts_ptr);
			top_sorted_sublist_len_b--;
		}
		else if (bottom_sorted_sublist_len_a && !top_sorted_sublist_len_b)
		{
			rra(ts_ptr);
			bottom_sorted_sublist_len_a--;
		}
		else
		{
			pa(ts_ptr);
			top_sorted_sublist_len_b--;
		}
	}
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

int	top_sorted_sublist_len(t_stack *stack_ptr, int order)
{
	return (count_sublist_len(stack_ptr->top, order));
}

int	bottom_sorted_sublist_len(t_stack *stack_ptr, int order)
{
	t_list	*node;
	int		sorted_sublists;

	sorted_sublists = count_sorted_sublists(stack_ptr, order) - 1;
	node = stack_ptr->top;
	while (sorted_sublists--)
		skip_sorted_sublist(&node, order);
	return (count_sublist_len(node, order));
}

int	count_sublist_len(t_list *node, int order)
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

static int	first_element_greater_than_second(t_stack *stack_ptr)
{
	int	first;
	int	second;

	if (stack_ptr->size <= 1)
		return (0);
	first = node_val(stack_ptr->top);
	second = node_val(stack_ptr->top->next);
	return (first > second);
}

int	count_sorted_sublists(t_stack *stack, int order)
{
	int		count;
	t_list	*node;

	if (stack->size == 0)
		return (0);
	count = 0;
	node = stack->top;
	while (node)
	{
		skip_sorted_sublist(&node, order);
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
