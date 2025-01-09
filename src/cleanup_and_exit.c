/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_and_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:04:05 by jvarila           #+#    #+#             */
/*   Updated: 2025/01/06 11:10:58 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	cleanup_and_exit(t_two_stacks **ts_ptr_ptr)
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
	exit(1);
}
