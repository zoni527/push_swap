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

#include "push_swap.h"

static void	rrx(t_stack *s1, t_stack *s2);

void	rra(t_two_stacks *stacks_ptr)
{
	ft_printf("%s\n", "rra");
	rrx(&stacks_ptr->a, &stacks_ptr->b);
}

void	rrb(t_two_stacks *stacks_ptr)
{
	ft_printf("%s\n", "rrb");
	rrx(&stacks_ptr->b, &stacks_ptr->a);
}

void	rrr(t_two_stacks *stacks_ptr)
{
	ft_printf("%s\n", "rrr");
	rrx(&stacks_ptr->a, &stacks_ptr->b);
	rrx(&stacks_ptr->b, &stacks_ptr->a);
}

static void	rrx(t_stack *s1, t_stack *s2)
{
	int	last_element;
	int	original_size;

	if (s1->size <= 1)
		return ;
	original_size = s1->size;
	while (s1->size > 1)
		push(s2, pop(s1));
	last_element = pop(s1);
	while (s1->size < original_size - 1)
		push(s1, pop(s2));
	push(s1, last_element);
}
