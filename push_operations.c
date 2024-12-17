/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:52:53 by jvarila           #+#    #+#             */
/*   Updated: 2024/12/17 09:56:18 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	px(t_stack *a, t_stack *b);

void	pa(t_stack *a, t_stack *b)
{
	ft_printf("%s\n", "pa");
	px(a, b);
}

void	pb(t_stack *a, t_stack *b)
{
	ft_printf("%s\n", "pb");
	px(b, a);
}

static void	px(t_stack *s1, t_stack *s2)
{
	int	temp;

	if (s2->size == 0)
		return ;
	push(s1, pop(s2));
}
