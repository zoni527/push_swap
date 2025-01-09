/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_02.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:32:56 by jvarila           #+#    #+#             */
/*   Updated: 2025/01/09 17:33:42 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	assign_up(t_instructions *inst_ptr, int cost, int m_a_up, int m_b_up)
{
	reset_instructions(inst_ptr);
	inst_ptr->cost = cost;
	inst_ptr->rr = smaller_int(m_a_up, m_b_up);
	if (m_a_up > m_b_up)
		inst_ptr->ra = m_a_up - m_b_up;
	else
		inst_ptr->rb = m_b_up - m_a_up;
}

void	assign_down(t_instructions *inst_ptr, int cost,
				int m_a_down, int m_b_down)
{
	reset_instructions(inst_ptr);
	inst_ptr->cost = cost;
	inst_ptr->rrr = smaller_int(m_a_down, m_b_down);
	if (m_a_down > m_b_down)
		inst_ptr->rra = m_a_down - m_b_down;
	else
		inst_ptr->rrb = m_b_down - m_a_down;
}

void	assign_up_down(t_instructions *inst_ptr, int cost,
				int m_a_up, int m_b_down)
{
	reset_instructions(inst_ptr);
	inst_ptr->cost = cost;
	inst_ptr->ra = m_a_up;
	inst_ptr->rrb = m_b_down;
}

void	assign_down_up(t_instructions *inst_ptr, int cost,
				int m_a_down, int m_b_up)
{
	reset_instructions(inst_ptr);
	inst_ptr->cost = cost;
	inst_ptr->rra = m_a_down;
	inst_ptr->rb = m_b_up;
}

void	perform_instructions(t_two_stacks *ts_ptr, t_instructions *inst)
{
	rr_n(ts_ptr, inst->rr);
	rrr_n(ts_ptr, inst->rrr);
	ra_n(ts_ptr, inst->ra);
	rb_n(ts_ptr, inst->rb);
	rra_n(ts_ptr, inst->rra);
	rrb_n(ts_ptr, inst->rrb);
	pb(ts_ptr);
}
