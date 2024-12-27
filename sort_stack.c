/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:39:34 by jvarila           #+#    #+#             */
/*   Updated: 2024/12/27 17:39:53 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_sorted(t_two_stacks *two_stacks_ptr);

void	sort_stack(t_two_stacks *two_stacks_ptr)
{
	if (stack_sorted(two_stacks_ptr))
		return ;
	ft_printf("%s\n", "Not sorted");
}

static int	stack_sorted(t_two_stacks *two_stacks_ptr)
{
	int	sorted;

	if (two_stacks_ptr->b.size != 0)
		return (0);
	if (two_stacks_ptr->a.size == 1)
		return (1);
	sorted = 1;
	pb(two_stacks_ptr);
	while (two_stacks_ptr->a.size != 0)
	{
		if (*(int *)two_stacks_ptr->b.top->content
			> *(int *)two_stacks_ptr->a.top->content)
		{
			sorted = 0;
			break ;
		}
		pb(two_stacks_ptr);
	}
	while (two_stacks_ptr->b.size != 0)
		pa(two_stacks_ptr);
	return (sorted);
}
