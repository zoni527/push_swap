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

void	pa(t_two_stacks *stacks_ptr)
{
	ft_printf("%s\n", "pa");
	px(&stacks_ptr->a, &stacks_ptr->b);
}

void	pb(t_two_stacks *stacks_ptr)
{
	ft_printf("%s\n", "pb");
	px(&stacks_ptr->b, &stacks_ptr->a);
}

static void	px(t_stack *s1, t_stack *s2)
{
	if (s2->size == 0)
		return ;
	push(s1, pop(s2));
}
