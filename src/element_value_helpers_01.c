/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_value_helpers_01.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:18:03 by jvarila           #+#    #+#             */
/*   Updated: 2025/01/09 17:20:12 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	element_val(t_stack *stack_ptr, int index)
{
	t_list	*node;
	int		i;

	if (index < 0 || index >= stack_ptr->size)
		return (INT_MIN);
	node = stack_ptr->top;
	i = -1;
	while (++i < index)
		node = node->next;
	return (node_val(node));
}

int	max_val(t_stack *stack_ptr)
{
	return (node_val(max_node(stack_ptr->top)));
}

int	min_val(t_stack *stack_ptr)
{
	return (node_val(min_node(stack_ptr->top)));
}
