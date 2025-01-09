/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:59:39 by jvarila           #+#    #+#             */
/*   Updated: 2024/12/18 10:25:06 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rrx(t_stack *s1, t_stack *s2);

void	rra(t_two_stacks *ts_ptr)
{
	if (ts_ptr->a.size < 2)
		return ;
	ft_printf("%s\n", "rra");
	rrx(&ts_ptr->a, &ts_ptr->b);
	if (ts_ptr->a.error || ts_ptr->b.error)
		cleanup_and_exit(&ts_ptr);
}

void	rrb(t_two_stacks *ts_ptr)
{
	if (ts_ptr->b.size < 2)
		return ;
	ft_printf("%s\n", "rrb");
	rrx(&ts_ptr->b, &ts_ptr->a);
	if (ts_ptr->a.error || ts_ptr->b.error)
		cleanup_and_exit(&ts_ptr);
}

void	rrr(t_two_stacks *ts_ptr)
{
	if (ts_ptr->a.size < 2 && ts_ptr->b.size < 2)
		return ;
	ft_printf("%s\n", "rrr");
	if (ts_ptr->a.size >= 2)
		rrx(&ts_ptr->a, &ts_ptr->b);
	if (ts_ptr->b.size >= 2)
		rrx(&ts_ptr->b, &ts_ptr->a);
	if (ts_ptr->a.error || ts_ptr->b.error)
		cleanup_and_exit(&ts_ptr);
}

static void	rrx(t_stack *s1, t_stack *s2)
{
	int	last_element;
	int	original_size;

	original_size = s1->size;
	while (s1->size > 1)
		push(s2, pop(s1));
	last_element = pop(s1);
	while (s1->size < original_size - 1)
		push(s1, pop(s2));
	push(s1, last_element);
}
