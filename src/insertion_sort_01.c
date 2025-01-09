/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:25:10 by jvarila           #+#    #+#             */
/*   Updated: 2025/01/09 17:32:50 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	insertion_sort(t_two_stacks *ts_ptr)
{
	int	moves_a_up;
	int	moves_a_down;

	push_a_to_b(ts_ptr);
	if (!stack_sorted(&ts_ptr->b))
		align_sorted_stack(&ts_ptr->b, ts_ptr);
	sort_three(ts_ptr);
	while (ts_ptr->b.size
		&& node_val(ts_ptr->b.top) > last_element_val(&ts_ptr->a))
		pa(ts_ptr);
	if (!ts_ptr->b.size)
		align_sorted_stack(&ts_ptr->a, ts_ptr);
	while (ts_ptr->b.size)
	{
		moves_a_up = element_to_push_on_index(&ts_ptr->a,
				node_val(ts_ptr->b.top));
		moves_a_down = ts_ptr->a.size - moves_a_up;
		if (moves_a_up < moves_a_down)
			ra_n(ts_ptr, moves_a_up);
		else
			rra_n(ts_ptr, moves_a_down);
		pa(ts_ptr);
	}
	if (!stack_sorted(&ts_ptr->a))
		align_sorted_stack(&ts_ptr->a, ts_ptr);
}

void	push_a_to_b(t_two_stacks *ts_ptr)
{
	int				i;
	t_moveset		mov;
	t_instructions	inst;

	pb(ts_ptr);
	while (ts_ptr->a.size > 3)
	{
		i = -1;
		reset_instructions(&inst);
		inst.cost = INT_MAX;
		while (++i < ts_ptr->a.size)
		{
			calculate_moves(ts_ptr, &mov, i);
			if (mov.cost_up < inst.cost)
				assign_up(&inst, mov.cost_up, mov.a_up, mov.b_up);
			if (mov.cost_down < inst.cost)
				assign_down(&inst, mov.cost_down, mov.a_down, mov.b_down);
			if (mov.cost_up_down < inst.cost)
				assign_up_down(&inst, mov.cost_up_down, mov.a_up, mov.b_down);
			if (mov.cost_down_up < inst.cost)
				assign_down_up(&inst, mov.cost_down_up, mov.a_down, mov.b_up);
		}
		perform_instructions(ts_ptr, &inst);
	}
}

void	align_sorted_stack(t_stack *stack, t_two_stacks *ts_ptr)
{
	int		moves_up;
	int		moves_down;
	void	(*rotate)(t_two_stacks *ts_ptr, int amount);

	if (stack->order == ASCENDING)
		moves_up = element_index(stack, min_val(stack));
	else
		moves_up = element_index(stack, max_val(stack));
	moves_down = stack->size - moves_up;
	if (moves_up <= moves_down && stack->order == ASCENDING)
		rotate = ra_n;
	else if (moves_up <= moves_down && stack->order == DESCENDING)
		rotate = rb_n;
	else if (moves_down <= moves_up && stack->order == ASCENDING)
		rotate = rra_n;
	else
		rotate = rrb_n;
	rotate(ts_ptr, smaller_int(moves_up, moves_down));
}

void	reset_instructions(t_instructions *instructions_ptr)
{
	instructions_ptr->ra = 0;
	instructions_ptr->rb = 0;
	instructions_ptr->rra = 0;
	instructions_ptr->rrb = 0;
	instructions_ptr->rr = 0;
	instructions_ptr->rrr = 0;
	instructions_ptr->cost = INT_MAX;
}

void	calculate_moves(t_two_stacks *ts_ptr, t_moveset *moves, int index)
{
	t_stack	*a;
	t_stack	*b;

	a = &ts_ptr->a;
	b = &ts_ptr->b;
	moves->a_up = index;
	moves->b_up = element_to_push_on_index(b, element_val(a, index));
	moves->a_down = a->size - moves->a_up;
	moves->b_down = b->size - moves->b_up;
	moves->cost_up = larger_int(moves->a_up, moves->b_up);
	moves->cost_down = larger_int(moves->a_down, moves->b_down);
	moves->cost_up_down = moves->a_up + moves->b_down;
	moves->cost_down_up = moves->a_down + moves->b_up;
}
