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

#include "../include/push_swap.h"

static void	normalize_stack(t_stack *stack);

void	sort_stack(t_two_stacks *ts_ptr)
{
	ts_ptr->a.order = ASCENDING;
	ts_ptr->b.order = DESCENDING;
	if (stack_sorted(&ts_ptr->a))
		return ;
	if (ts_ptr->a.size == 2)
		return (sa(ts_ptr));
	if (ts_ptr->a.size == 3)
		return (sort_three(ts_ptr));
	normalize_stack(&ts_ptr->a);
	insertion_sort(ts_ptr);
}

int	stack_sorted(t_stack *stack_ptr)
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

// Change the values of the stack elements to be consecutive integers starting
// from 0. These values can be useful when comparing against the total size
// of the stack and when calculating the amount of moves needed.
static void	normalize_stack(t_stack *stack)
{
	int		max;
	t_stack	temp;
	t_list	*node;

	if (!stack->size)
		return ;
	temp = (t_stack){0};
	node = max_node(stack->top);
	while (node)
	{
		push(&temp, node_val(node));
		max = node_val(node);
		node = next_smaller_node(stack->top, max);
	}
	node = stack->top;
	while (node)
	{
		*(int *)node->content = element_index(&temp, node_val(node));
		node = node->next;
	}
	while (temp.size)
		pop(&temp);
}
