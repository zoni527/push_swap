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

#include "../include/push_swap.h"

static void	*free_stacks_return_null(t_two_stacks **ts_ptr_ptr);

t_two_stacks	*parse_input(char **cl_input)
{
	t_two_stacks	*ts_ptr;
	char			*str;
	int				num;

	ts_ptr = ft_calloc(1, sizeof(t_two_stacks));
	if (!ts_ptr)
		return (NULL);
	str = *cl_input;
	while (str)
	{
		str = skip_whitespace(str);
		num = ft_atoi(str);
		if (stack_contains_number(&ts_ptr->a, num))
			return (free_stacks_return_null(&ts_ptr));
		push(&ts_ptr->b, num);
		str = ft_strchr(str, ' ');
		if (str && word_count(str))
			str = skip_char(str, ' ');
		else
			str = *(++cl_input);
	}
	while (ts_ptr->b.size != 0)
		push(&ts_ptr->a, pop(&ts_ptr->b));
	return (ts_ptr);
}

static void	*free_stacks_return_null(t_two_stacks **ts_ptr_ptr)
{
	t_stack	*a_ptr;
	t_stack	*b_ptr;

	a_ptr = &((*ts_ptr_ptr)->a);
	b_ptr = &((*ts_ptr_ptr)->b);
	if (a_ptr && a_ptr->top)
		ft_lstclear(&a_ptr->top, free);
	if (b_ptr && b_ptr->top)
		ft_lstclear(&b_ptr->top, free);
	free(*ts_ptr_ptr);
	*ts_ptr_ptr = NULL;
	return (NULL);
}
