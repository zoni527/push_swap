/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:11:40 by jvarila           #+#    #+#             */
/*   Updated: 2024/12/13 17:11:07 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_stack
{
	t_list	*top;
	int		size;
	int		error;
}	t_stack;

int		push(t_stack *stack, int num);
int		pop(t_stack *stack);
int		peek(t_stack *stack);
void	print_stack(t_stack *stack);

#endif
