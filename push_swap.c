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
	t_two_stacks	*two_stacks_ptr;

	if (argc == 1 || !validate_input(argv + 1))
		return (write_error_return_int("Error", 0));
	two_stacks_ptr = parse_input(argv + 1);
	if (!two_stacks_ptr || two_stacks_ptr->error
		|| two_stacks_ptr->a.error || two_stacks_ptr->b.error)
	{
		free_stacks(&two_stacks_ptr);
		return (write_error_return_int("Error", 0));
	}
	sort_stack(two_stacks_ptr);
	return (0);
}

static void	free_stacks(t_two_stacks **two_stacks_ptr_ptr)
{
	if ((*two_stacks_ptr_ptr)->a.top)
		ft_lstclear(&(*two_stacks_ptr_ptr)->a.top, free);
	if ((*two_stacks_ptr_ptr)->b.top)
		ft_lstclear(&(*two_stacks_ptr_ptr)->b.top, free);
	free(*two_stacks_ptr_ptr);
	*two_stacks_ptr_ptr = NULL;
}
