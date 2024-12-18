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

void	rra(t_stack *a, t_stack *b)
{
	ft_printf("%s\n", "rra");
	rrx(a, b);
}

void	rrb(t_stack *a, t_stack *b)
{
	ft_printf("%s\n", "rrb");
	rrx(b, a);
}

void	rrr(t_stack *a, t_stack *b)
{
	ft_printf("%s\n", "rrr");
	rrx(a, b);
	rrx(b, a);
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
