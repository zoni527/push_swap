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

void	ra(t_two_stacks *two_stacks_ptr)
{
	if (two_stacks_ptr->a.size <= 1)
		return ;
	ft_printf("%s\n", "ra");
	rx(&two_stacks_ptr->a, &two_stacks_ptr->b);
}

void	rb(t_two_stacks *two_stacks_ptr)
{
	if (two_stacks_ptr->b.size <= 1)
		return ;
	ft_printf("%s\n", "rb");
	rx(&two_stacks_ptr->b, &two_stacks_ptr->a);
}

void	rr(t_two_stacks *two_stacks_ptr)
{
	if (two_stacks_ptr->a.size <= 1 && two_stacks_ptr->b.size <= 1)
		return ;
	ft_printf("%s\n", "rr");
	rx(&two_stacks_ptr->a, &two_stacks_ptr->b);
	rx(&two_stacks_ptr->b, &two_stacks_ptr->a);
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
