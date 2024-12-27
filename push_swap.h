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

# define MALLOCERROR 1
# define POPERROR 2
# define PEEKERROR 3

typedef struct s_stack
{
	t_list	*top;
	int		size;
	int		error;
}	t_stack;

typedef struct s_two_stacks
{
	t_stack	a;
	t_stack	b;
	int		error;
}	t_two_stacks;

int				push(t_stack *stack, int num);
int				pop(t_stack *stack);
int				peek(t_stack *stack);
void			print_stack(const t_stack *stack);
int				stack_contains_number(const t_stack *stack, int num);

void			sa(t_two_stacks *stacks_ptr);
void			sb(t_two_stacks *stacks_ptr);
void			ss(t_two_stacks *stacks_ptr);
void			pa(t_two_stacks *stacks_ptr);
void			pb(t_two_stacks *stacks_ptr);
void			ra(t_two_stacks *stacks_ptr);
void			rb(t_two_stacks *stacks_ptr);
void			rr(t_two_stacks *stacks_ptr);
void			rra(t_two_stacks *stacks_ptr);
void			rrb(t_two_stacks *stacks_ptr);
void			rrr(t_two_stacks *stacks_ptr);

int				validate_input(char **command_line_arguments);
int				valid_multinumberstring(char *str);
t_two_stacks	*parse_input(char **cl_input);

#endif
