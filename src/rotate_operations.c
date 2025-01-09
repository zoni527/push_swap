/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:56:27 by jvarila           #+#    #+#             */
/*   Updated: 2024/12/17 11:32:17 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rx(t_stack *s1, t_stack *s2);

void	ra(t_two_stacks *ts_ptr)
{
	if (ts_ptr->a.size < 2)
		return ;
	ft_printf("%s\n", "ra");
	rx(&ts_ptr->a, &ts_ptr->b);
	if (ts_ptr->a.error || ts_ptr->b.error)
		cleanup_and_exit(&ts_ptr);
}

void	rb(t_two_stacks *ts_ptr)
{
	if (ts_ptr->b.size < 2)
		return ;
	ft_printf("%s\n", "rb");
	rx(&ts_ptr->b, &ts_ptr->a);
	if (ts_ptr->a.error || ts_ptr->b.error)
		cleanup_and_exit(&ts_ptr);
}

void	rr(t_two_stacks *ts_ptr)
{
	if (ts_ptr->a.size < 2 && ts_ptr->b.size < 2)
		return ;
	ft_printf("%s\n", "rr");
	if (ts_ptr->a.size >= 2)
		rx(&ts_ptr->a, &ts_ptr->b);
	if (ts_ptr->b.size >= 2)
		rx(&ts_ptr->b, &ts_ptr->a);
	if (ts_ptr->a.error || ts_ptr->b.error)
		cleanup_and_exit(&ts_ptr);
}

static void	rx(t_stack *s1, t_stack *s2)
{
	int	first_element;
	int	original_size;

	original_size = s1->size;
	first_element = pop(s1);
	while (s1->size > 0)
		push(s2, pop(s1));
	push(s1, first_element);
	while (s1->size < original_size)
		push(s1, pop(s2));
}
