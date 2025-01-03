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

static int	stack_sorted(t_stack *stack_ptr);
static int	swappable(t_two_stacks *two_stacks_ptr);
// static void	double_bubble_sort(t_two_stacks *ts_ptr);
static void	merge_sort(t_two_stacks *ts_ptr);
static void	divide_and_presort(t_two_stacks *ts_ptr);
void	merge_sorted_portions_and_rotate_to_end(t_two_stacks *ts_ptr);

void	sort_stack(t_two_stacks *two_stacks_ptr)
{
	if (stack_sorted(&two_stacks_ptr->a))
		return ;
	if (two_stacks_ptr->a.size == 2)
		return sa(two_stacks_ptr);
	merge_sort(two_stacks_ptr);
}

static int	stack_sorted(t_stack *stack_ptr)
{
	t_list	*node;

	if (stack_ptr->size == 1)
		return (1);
	node = stack_ptr->top;
	while (node->next)
	{
		if (*(int *)node->content > *(int *)node->next->content)
			return (0);
		node = node->next;
	}
	return (1);
}

int	count_sorted_sections(t_stack *stack)
{
	int		count;
	t_list	*node;

	if (stack->size == 0)
		return (0);
	count = 0;
	node = stack->top;
	while (node)
	{
		while (node->next 
			&& *(int *)node->content < *(int *)node->next->content)
		{
			node = node->next;
		}
		count++;
		node = node->next;
	}
	return (count);
}

static void	merge_sort(t_two_stacks *ts_ptr)
{
	divide_and_presort(ts_ptr);
	while (ts_ptr->b.size || !stack_sorted(&ts_ptr->a))
	{
		merge_sorted_portions_and_rotate_to_end(ts_ptr);
	}
}

void	merge_sorted_portions_and_rotate_to_end(t_two_stacks *ts_ptr)
{
	t_list	*node;
	t_stack	*src;
	t_stack	*dest;
	void	(*push)(t_two_stacks *ts_ptr);
	void	(*rotate)(t_two_stacks *ts_ptr);

	if (ts_ptr->a.size > ts_ptr->b.size)
	{
		src = &ts_ptr->a;
		dest = &ts_ptr->b;
		push = pb;
		rotate = rb;
	}
	else
	{
		src = &ts_ptr->b;
		dest = &ts_ptr->a;
		push = pa;
		rotate = rb;
	}
	node = src->top;
	while (node->next && *(int *)node->content < *(int *)node->next->content)
	{
		if (peek(src) < peek(dest))
		{
			push(ts_ptr);
			rotate(ts_ptr);
		}
		else
			rb(ts_ptr);
	}
}

// First push half of a to b and presort
static void	divide_and_presort(t_two_stacks *ts_ptr)
{
	int	i;
	int	swap_state;

	i = ts_ptr->a.size / 4;
	if (i == 0)
		i++;
	while (ts_ptr->a.size > i)
	{
		pb(ts_ptr);
		pb(ts_ptr);
		swap_state = swappable(ts_ptr);
		if (swap_state == BOTH)
			ss(ts_ptr);
		if (swap_state == A)
			sa(ts_ptr);
		if (swap_state == B)
			sb(ts_ptr);
		ra(ts_ptr);
		ra(ts_ptr);
	}
	if ((ts_ptr->a.size + ts_ptr->b.size) % 4 != 0)
		pb(ts_ptr);
}
/*
static void	double_bubble_sort(t_two_stacks *ts_ptr)
{
	int	elements;
	int	swap_state;
	int	lock;
	int	i;

	elements = ts_ptr->a.size;
	i = -1;
	while (++i < elements / 2)
		pb(ts_ptr);
	lock = 0;
	i = 0;
	while (((lock & 0b00000001) == 0 || (lock & 0b00000010) == 0)
		&& i < 1000000)
	{
		swap_state = swappable(ts_ptr);
		if (swap_state == BOTH
			&& (i + 1) % ts_ptr->a.size != 0
			&& (i + 1) % ts_ptr->b.size != 0)
			ss(ts_ptr);
		if (swap_state == A && (i + 1) % ts_ptr->a.size != 0)
			sa(ts_ptr);
		if (swap_state == B && (i + 1) % ts_ptr->b.size != 0)
			sb(ts_ptr);
		if (stack_sorted(&ts_ptr->a))
			lock |= 1;
		if (stack_sorted(&ts_ptr->b))
			lock |= 1 << 1;
		if (lock == 3)
			break ;
		if (lock == 1)
			rb(ts_ptr);
		if (lock == 2)
			ra(ts_ptr);
		if (lock == 0)
			rr(ts_ptr);
		i++;
	}
	while (ts_ptr->b.size > 0)
	{
		if (peek(&ts_ptr->b) < peek(&ts_ptr->a))
		{
			pa(ts_ptr);
			ra(ts_ptr);
		}
		else if (*(int *)ts_ptr->b.top->content
			> *(int *)ts_ptr->a.top->content)
		{
			ra(ts_ptr);
		}
	}
	while (!stack_sorted(&ts_ptr->a))
		ra(ts_ptr);
}
*/
static int	swappable(t_two_stacks *ts_ptr)
{
	int	a_swappable;
	int	b_swappable;
	int	first;
	int	second;

	first = *(int *)ts_ptr->a.top->content;
	if (ts_ptr->a.top->next)
		second = *(int *)ts_ptr->a.top->next->content;
	else
		second = INT_MIN;
	a_swappable = ts_ptr->a.size > 1 && first > second;
	first = *(int *)ts_ptr->b.top->content;
	if (ts_ptr->b.top->next)
		second = *(int *)ts_ptr->b.top->next->content;
	else
		second = INT_MIN;
	b_swappable = ts_ptr->b.size > 1 && first > second;
	if (a_swappable && b_swappable)
		return (BOTH);
	if (a_swappable)
		return (A);
	if (b_swappable)
		return (B);
	return (0);
}
