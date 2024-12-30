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

#include "./libft/libft.h"
#include "push_swap.h"

#define BOTH	1
#define A		2
#define B		3

static int	stack_sorted(t_stack *stack_ptr);
static int	swappable(t_two_stacks *two_stacks_ptr);
static void	double_bubble_sort(t_two_stacks *ts_ptr);

void	sort_stack(t_two_stacks *two_stacks_ptr)
{
	if (stack_sorted(&two_stacks_ptr->a))
		return ;
	if (two_stacks_ptr->a.size == 2)
		return pa(two_stacks_ptr);
	double_bubble_sort(two_stacks_ptr);
}

static int	stack_sorted(t_stack *stack_ptr)
{
	t_list	*node;
	int		sorted;

	if (stack_ptr->size == 1)
		return (1);
	node = stack_ptr->top;
	sorted = 1;
	while (node->next)
	{
		if (*(int *)node->content > *(int *)node->next->content)
		{
			sorted = 0;
			break ;
		}
		node = node->next;
	}
	return (sorted);
}

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
		if (*(int *)ts_ptr->b.top->content
			< *(int *)ts_ptr->a.top->content)
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
