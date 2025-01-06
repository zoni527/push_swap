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

void		merge_sorted_portions_and_rotate_to_end(t_two_stacks *ts_ptr);

int			first_int_larger(int a, int b);
int			first_int_smaller(int a, int b);

void		skip_sorted_sublist(t_list **node_ptr, int order);

int			node_val(t_list *node);
int			last_element_val(t_stack *stack_ptr);
int			top_sorted_sublist_len(t_stack *stack_ptr, int order);
int			bottom_sorted_sublist_len(t_stack *stack_ptr, int order);

int			sublist_len(t_list *node, int order);
int			count_sorted_sublists(t_stack *stack, int order);

void		sort_three(t_two_stacks *ts_ptr, int order);
void		sort_a_b_c(t_two_stacks *ts_ptr, int a, int b, int c, int order);

void		normalize_stack(t_stack *stack);
t_list		*next_largest_node(t_list *lst, int num);
void		insertion_sort(t_two_stacks *ts_ptr);

t_list		*min_node(t_list *lst);

void	sort_stack(t_two_stacks *ts_ptr)
{
	if (stack_sorted(&ts_ptr->a, ASCENDING))
		return ;
	if (ts_ptr->a.size == 2)
		return (sa(ts_ptr));
	if (ts_ptr->a.size == 3)
		sort_three(ts_ptr, ASCENDING);
	normalize_stack(&ts_ptr->a);
	insertion_sort(ts_ptr);
	print_stack(&ts_ptr->a);
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

void	sort_three(t_two_stacks *ts_ptr, int order)
{
	int	first;
	int	second;
	int	third;

	first = node_val(ts_ptr->a.top);
	second = node_val(ts_ptr->a.top->next);
	third = node_val(ts_ptr->a.top->next->next);
	sort_a_b_c(ts_ptr, first, second, third, order);
}

// The combinations of comparisons correspong to the 5 different sortable
// cases for three numbers, for ascending order this means 1 3 2, 2 1 3,
// 2 3 1, 3 1 2 and 3 2 1. Changing the function to first_int_larger flips
// the comparisons and correctly sorts three numbers in descending order.
void	sort_a_b_c(t_two_stacks *ts_ptr, int a, int b, int c, int order)
{
	int	(*comp)(int a, int b);

	if (order == ASCENDING)
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
		node = next_largest_node(stack->top, min);
		count++;
	}
}

t_list *min_node(t_list *lst)
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

t_list	*next_largest_node(t_list *lst, int num)
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

void	insertion_sort(t_two_stacks *ts_ptr)
{
	int	b_min;
	int	b_max;
	int	moves_to_top;
	int	min_cost;
	int	min_cost_element_index;
	int	i;

	pb(ts_ptr);
	b_max = node_val(ts_ptr->b.top);
	b_min = b_max;
	while (ts_ptr->a.size > 3)
	{
		i = -1;
		while (++i < ts_ptr->a.size)
		{
			
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
	return (sublist_len(stack_ptr->top, order));
}

int	bottom_sorted_sublist_len(t_stack *stack_ptr, int order)
{
	t_list	*node;
	int		sorted_sublists;

	sorted_sublists = count_sorted_sublists(stack_ptr, order) - 1;
	node = stack_ptr->top;
	while (sorted_sublists--)
		skip_sorted_sublist(&node, order);
	return (sublist_len(node, order));
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
