/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:20:50 by jvarila           #+#    #+#             */
/*   Updated: 2024/12/19 11:31:27 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stacks(t_two_stacks **two_stacks_ptr_ptr);

int	main(int argc, char **argv)
{
	t_two_stacks	*ts_ptr;

	if (argc == 1)
		return (0);
	if (!validate_input(argv + 1))
		return (write_error_return_int("Error", 0));
	ts_ptr = parse_input(argv + 1);
	if (!ts_ptr || ts_ptr->a.error || ts_ptr->b.error)
	{
		free_stacks(&ts_ptr);
		return (write_error_return_int("Error", 0));
	}
	sort_stack(ts_ptr);
	free_stacks(&ts_ptr);
	return (0);
}

static void	free_stacks(t_two_stacks **ts_ptr_ptr)
{
	if ((*ts_ptr_ptr)->a.top)
		ft_lstclear(&(*ts_ptr_ptr)->a.top, free);
	if ((*ts_ptr_ptr)->b.top)
		ft_lstclear(&(*ts_ptr_ptr)->b.top, free);
	free(*ts_ptr_ptr);
	*ts_ptr_ptr = NULL;
}
