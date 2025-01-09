/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_n_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:59:26 by jvarila           #+#    #+#             */
/*   Updated: 2025/01/09 17:02:39 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra_n(t_two_stacks *ts_ptr, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		ra(ts_ptr);
}

void	rb_n(t_two_stacks *ts_ptr, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		rb(ts_ptr);
}

void	rr_n(t_two_stacks *ts_ptr, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		rr(ts_ptr);
}
