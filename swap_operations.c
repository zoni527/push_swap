/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:46:00 by jvarila           #+#    #+#             */
/*   Updated: 2024/12/17 09:52:46 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sx(t_stack *x);

void	sa(t_two_stacks *stacks_ptr)
{
	ft_printf("%s\n", "sa");
	sx(&stacks_ptr->a);
}

void	sb(t_two_stacks *stacks_ptr)
{
	ft_printf("%s\n", "sb");
	sx(&stacks_ptr->b);
}

void	ss(t_two_stacks *stacks_ptr)
{
	ft_printf("%s\n", "ss");
	sx(&stacks_ptr->a);
	sx(&stacks_ptr->b);
}

static void	sx(t_stack *x)
{
	int	temp1;
	int	temp2;

	if (x->size < 2)
		return ;
	temp1 = pop(x);
	temp2 = pop(x);
	push(x, temp1);
	push(x, temp2);
}
