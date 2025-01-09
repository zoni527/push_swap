/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_index_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:26:21 by jvarila           #+#    #+#             */
/*   Updated: 2025/01/09 15:32:31 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	element_index(t_stack *stack_ptr, int num)
{
	int		index;
	t_list	*node;

	index = -1;
	node = stack_ptr->top;
	while (++index < stack_ptr->size)
	{
		if (node_val(node) == num)
			return (index);
		node = node->next;
	}
	return (-1);
}

int	element_to_push_on_index(t_stack *stack_ptr, int num)
{
	int	max;
	int	min;

	if (stack_ptr->size < 2)
		return (0);
	max = max_val(stack_ptr);
	min = min_val(stack_ptr);
	if (stack_ptr->order == DESCENDING && (num > max || num < min))
		return (element_index(stack_ptr, max));
	if (stack_ptr->order == ASCENDING && (num > max || num < min))
		return (element_index(stack_ptr, min));
	if (stack_ptr->order == ASCENDING)
		return (element_index(stack_ptr, next_larger_val(stack_ptr, num)));
	else
		return (element_index(stack_ptr, next_smaller_val(stack_ptr, num)));
}
