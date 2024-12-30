/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:18:56 by jvarila           #+#    #+#             */
/*   Updated: 2024/12/27 15:31:00 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*free_stacks_return_null(t_two_stacks **stacks_ptr_ptr);

t_two_stacks	*parse_input(char **cl_input)
{
	t_two_stacks	*stacks_ptr;
	char			*str;
	int				num;

	stacks_ptr = ft_calloc(1, sizeof(t_two_stacks));
	if (!stacks_ptr)
		return (NULL);
	str = *cl_input;
	while (str)
	{
		str = skip_whitespace(str);
		num = ft_atoi(str);
		if (stack_contains_number(&stacks_ptr->a, num))
			return (free_stacks_return_null(&stacks_ptr));
		push(&stacks_ptr->b, num);
		str = ft_strchr(str, ' ');
		if (str && word_count(str))
			str = skip_char(str, ' ');
		else
			str = *(++cl_input);
	}
	while (stacks_ptr->b.size != 0)
		push(&stacks_ptr->a, pop(&stacks_ptr->b));
	return (stacks_ptr);
}

static void	*free_stacks_return_null(t_two_stacks **stacks_ptr_ptr)
{
	t_stack	*a_ptr;
	t_stack	*b_ptr;

	a_ptr = &((*stacks_ptr_ptr)->a);
	b_ptr = &((*stacks_ptr_ptr)->b);
	if (a_ptr && a_ptr->top)
		ft_lstclear(&a_ptr->top, free);
	if (b_ptr && b_ptr->top)
		ft_lstclear(&b_ptr->top, free);
	free(*stacks_ptr_ptr);
	*stacks_ptr_ptr = NULL;
	return (NULL);
}
