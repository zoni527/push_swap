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

void	sa(t_stack *a)
{
	ft_printf("%s\n", "sa");
	sx(a);
}

void	sb(t_stack *b)
{
	ft_printf("%s\n", "sb");
	sx(b);
}

void	ss(t_stack *a, t_stack *b)
{
	ft_printf("%s\n", "ss");
	sx(a);
	sx(b);
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
