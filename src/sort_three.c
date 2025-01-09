/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:50:44 by jvarila           #+#    #+#             */
/*   Updated: 2025/01/09 14:00:25 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_a_b_c(t_two_stacks *ts_ptr, int a, int b, int c);

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
static void	sort_a_b_c(t_two_stacks *ts_ptr, int a, int b, int c)
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
