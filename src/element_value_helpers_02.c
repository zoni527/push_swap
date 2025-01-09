/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_value_helpers_02.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:20:17 by jvarila           #+#    #+#             */
/*   Updated: 2025/01/09 17:21:20 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	last_element_val(t_stack *stack_ptr)
{
	t_list	*node;

	node = stack_ptr->top;
	if (!node)
		return (INT_MIN);
	if (!node->next)
		return (node_val(node));
	while (node->next)
		node = node->next;
	return (node_val(node));
}

int	next_smaller_val(t_stack *stack_ptr, int num)
{
	return (node_val(next_smaller_node(stack_ptr->top, num)));
}

int	next_larger_val(t_stack *stack_ptr, int num)
{
	return (node_val(next_larger_node(stack_ptr->top, num)));
}
