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

#include "push_swap.h"

static void	rx(t_stack *x);

void	ra(t_stack *a)
{
	ft_printf("%s\n", "ra");
	rx(a);
}

void	rb(t_stack *b)
{
	ft_printf("%s\n", "rb");
	rx(b);
}

void	rr(t_stack *a, t_stack *b)
{
	ft_printf("%s\n", "rr");
	rx(a);
	rx(b);
}

static void	rx(t_stack *x)
{
	int		first_element;
	t_stack	temp_stack;

	if (x->size <= 1)
		return ;
	first_element = pop(x);
	while (x->size > 0)
		push(&temp_stack, pop(x));
	push(x, first_element);
	while (temp_stack.size > 0)
		push(x, pop(&temp_stack));
}
