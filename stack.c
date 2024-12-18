/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:13:38 by jvarila           #+#    #+#             */
/*   Updated: 2024/12/16 16:14:36 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	push(t_stack *stack, int num)
{
	int		*data;
	t_list	*node;

	node = malloc(sizeof(t_list));
	data = malloc(sizeof(int));
	if (node == NULL || data == NULL)
	{
		free(node);
		free(data);
		ft_putstr_fd("ERROR: couldn't malloc in push\n", STDERR_FILENO);
		stack->error = MALLOCERROR;
		return (-1);
	}
	*data = num;
	node->content = data;
	node->next = NULL;
	ft_lstadd_front(&(stack->top), node);
	stack->size++;
	return (num);
}

// Remove topmost element from stack, with this singly linked list
// implementation the topmost element is the first element of the list.
int	pop(t_stack *stack)
{
	int		num;
	t_list	*temp;

	if (stack->size == 0)
	{
		ft_putstr_fd("ERROR: can't pop empty stack\n", STDERR_FILENO);
		stack->error = POPERROR;
		return (-1);
	}
	temp = stack->top;
	stack->top = stack->top->next;
	num = *(int *)(temp->content);
	ft_lstdelone(temp, free);
	stack->size--;
	return (num);
}

int	peek(t_stack *stack)
{
	if (stack == NULL)
	{
		ft_putstr_fd("ERROR: stack empty, can't peek\n", STDERR_FILENO);
		stack->error = PEEKERROR;
		return (-1);
	}
	return (*(int *)(stack->top->content));
}

void	print_stack(t_stack *stack)
{
	t_list	*node;
	int		num;

	node = stack->top;
	while (node != NULL)
	{
		num = *(int *)(node->content);
		if (num >= 0)
			ft_putchar(' ');
		ft_printf("%i ", num);
		node = node->next;
	}
	ft_putchar('\n');
}
