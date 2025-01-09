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

#include "../include/push_swap.h"

static void	sx(t_stack *x);

void	sa(t_two_stacks *ts_ptr)
{
	if (ts_ptr->a.size < 2)
		return ;
	ft_printf("%s\n", "sa");
	sx(&ts_ptr->a);
	if (ts_ptr->a.error)
		cleanup_and_exit(&ts_ptr);
}

void	sb(t_two_stacks *ts_ptr)
{
	if (ts_ptr->a.size < 2)
		return ;
	ft_printf("%s\n", "sb");
	sx(&ts_ptr->b);
	if (ts_ptr->b.error)
		cleanup_and_exit(&ts_ptr);
}

void	ss(t_two_stacks *ts_ptr)
{
	if (ts_ptr->a.size < 2 && ts_ptr->b.size < 2)
		return ;
	ft_printf("%s\n", "ss");
	if (ts_ptr->a.size >= 2)
		sx(&ts_ptr->a);
	if (ts_ptr->b.size >= 2)
		sx(&ts_ptr->b);
	if (ts_ptr->a.error || ts_ptr->b.error)
		cleanup_and_exit(&ts_ptr);
}

static void	sx(t_stack *x)
{
	int	temp1;
	int	temp2;

	temp1 = pop(x);
	temp2 = pop(x);
	push(x, temp1);
	push(x, temp2);
}
