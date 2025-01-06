/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:52:53 by jvarila           #+#    #+#             */
/*   Updated: 2024/12/18 10:26:49 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	px(t_stack *s1, t_stack *s2);

void	pa(t_two_stacks *ts_ptr)
{
	ft_printf("%s\n", "pa");
	px(&ts_ptr->a, &ts_ptr->b);
	if (ts_ptr->a.error || ts_ptr->b.error)
		cleanup_and_exit(&ts_ptr);
}

void	pb(t_two_stacks *ts_ptr)
{
	ft_printf("%s\n", "pb");
	px(&ts_ptr->b, &ts_ptr->a);
	if (ts_ptr->a.error || ts_ptr->b.error)
		cleanup_and_exit(&ts_ptr);
}

static void	px(t_stack *s1, t_stack *s2)
{
	if (s2->size == 0)
		return ;
	push(s1, pop(s2));
}
