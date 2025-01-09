/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_n_operations.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:02:50 by jvarila           #+#    #+#             */
/*   Updated: 2025/01/09 17:03:18 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra_n(t_two_stacks *ts_ptr, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		rra(ts_ptr);
}

void	rrb_n(t_two_stacks *ts_ptr, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		rrb(ts_ptr);
}

void	rrr_n(t_two_stacks *ts_ptr, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		rrr(ts_ptr);
}
