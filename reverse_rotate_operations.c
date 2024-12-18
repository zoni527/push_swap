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

#include "libft/libft.h"
#include "push_swap.h"

static void	rrx(t_stack *x);

void	rra(t_stack *a)
{
	ft_printf("%s\n", "rra");
	rrx(a);
}

void	rrb(t_stack *b)
{
	ft_printf("%s\n", "rrb");
	rrx(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	ft_printf("%s\n", "rrr");
	rrx(a);
	rrx(b);
}

void	rrx(t_stack *x)
{
	t_stack	temp_stack;
	int		num;

	if (x->size <= 1)
		return ;
	temp_stack = (t_stack){0};
	while (x->size > 1)
		push(&temp_stack, pop(x));
	num = pop(x);
	while (temp_stack.size > 0)
		push(x, pop(&temp_stack));
	push(x, num);
}
