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

static void	rx(t_stack *s1, t_stack *s2);

void	ra(t_two_stacks *stacks_ptr)
{
	ft_printf("%s\n", "ra");
	rx(&stacks_ptr->a, &stacks_ptr->b);
}

void	rb(t_two_stacks *stacks_ptr)
{
	ft_printf("%s\n", "rb");
	rx(&stacks_ptr->b, &stacks_ptr->a);
}

void	rr(t_two_stacks *stacks_ptr)
{
	ft_printf("%s\n", "rr");
	rx(&stacks_ptr->a, &stacks_ptr->b);
	rx(&stacks_ptr->b, &stacks_ptr->a);
}

static void	rx(t_stack *s1, t_stack *s2)
{
	int	first_element;
	int	original_size;

	if (s1->size <= 1)
		return ;
	original_size = s1->size;
	first_element = pop(s1);
	while (s1->size > 0)
		push(s2, pop(s1));
	push(s1, first_element);
	while (s1->size < original_size)
		push(s1, pop(s2));
}
