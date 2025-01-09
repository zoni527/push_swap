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

# include "../libft/libft.h"

# define MALLOCERROR	 1
# define POPERROR		 2
# define PEEKERROR		 3

# define ASCENDING		 0
# define DESCENDING		 1

typedef struct s_stack
{
	t_list	*top;
	int		size;
	int		order;
	int		error;
}	t_stack;

typedef struct s_two_stacks
{
	t_stack	a;
	t_stack	b;
}	t_two_stacks;

typedef struct s_instructions
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	rr;
	int	rrr;
	int	cost;
}	t_instructions;

typedef struct s_moveset
{
	int	cost_up;
	int	cost_down;
	int	cost_up_down;
	int	cost_down_up;
	int	a_up;
	int	a_down;
	int	b_up;
	int	b_down;
}	t_moveset;

//------------------------------------------------------------------------------
// input_parsing.c
//----------------
t_two_stacks	*parse_input(char **cl_input);
//------------------------------------------------------------------------------
// input_validation.c
//-------------------
int				validate_input(char **command_line_arguments);
//------------------------------------------------------------------------------
// sort_stack.c
//-------------
void			sort_stack(t_two_stacks *two_stacks_ptr);
int				stack_sorted(t_stack *stack_ptr);
//------------------------------------------------------------------------------
// sort_three.c
//-------------
void			sort_three(t_two_stacks *ts_ptr);
//------------------------------------------------------------------------------
// insertion_sort_01.c
//--------------------
void			insertion_sort(t_two_stacks *ts_ptr);
void			push_a_to_b(t_two_stacks *ts_ptr);
void			align_sorted_stack(t_stack *stack, t_two_stacks *ts_ptr);
void			reset_instructions(t_instructions *instructions_ptr);
void			calculate_moves(t_two_stacks *ts_ptr,
					t_moveset *moves, int index);
//------------------------------------------------------------------------------
// insertion_sort_02.c
//--------------------
void			assign_up(t_instructions *inst_ptr, int cost,
					int m_a_up, int m_b_up);
void			assign_down(t_instructions *inst_ptr, int cost,
					int m_a_down, int m_b_down);
void			assign_up_down(t_instructions *inst_ptr, int cost,
					int m_a_up, int m_b_down);
void			assign_down_up(t_instructions *inst_ptr, int cost,
					int m_a_down, int m_b_up);
void			perform_instructions(t_two_stacks *ts_ptr,
					t_instructions *inst);
//------------------------------------------------------------------------------
// element_index_helpers.c
//------------------------
int				element_index(t_stack *stack_ptr, int num);
int				element_to_push_on_index(t_stack *stack_ptr, int num);
//------------------------------------------------------------------------------
// element_value_helpers_01.c
//---------------------------
int				element_val(t_stack *stack_ptr, int index);
int				min_val(t_stack *stack_ptr);
int				max_val(t_stack *stack_ptr);
//------------------------------------------------------------------------------
// element_value_helpers_02.c
//---------------------------
int				last_element_val(t_stack *stack_ptr);
int				next_smaller_val(t_stack *stack_ptr, int num);
int				next_larger_val(t_stack *stack_ptr, int num);
//------------------------------------------------------------------------------
// node_helpers.c
//---------------
t_list			*min_node(t_list *lst);
t_list			*max_node(t_list *lst);
t_list			*next_larger_node(t_list *lst, int num);
t_list			*next_smaller_node(t_list *lst, int num);
int				node_val(t_list *node);
//------------------------------------------------------------------------------
// cleanup_and_exit.c
//-------------------
void			cleanup_and_exit(t_two_stacks **ts_ptr_ptr);
//------------------------------------------------------------------------------
// swap_operations.c
//------------------
void			sa(t_two_stacks *stacks_ptr);
void			sb(t_two_stacks *stacks_ptr);
void			ss(t_two_stacks *stacks_ptr);
//------------------------------------------------------------------------------
// push_operations.c
//------------------
void			pa(t_two_stacks *stacks_ptr);
void			pb(t_two_stacks *stacks_ptr);
//------------------------------------------------------------------------------
// rotate_operations.c
//--------------------
void			ra(t_two_stacks *stacks_ptr);
void			rb(t_two_stacks *stacks_ptr);
void			rr(t_two_stacks *stacks_ptr);
//------------------------------------------------------------------------------
// rotate_n_operations.c
//----------------------
void			ra_n(t_two_stacks *ts_ptr, int n);
void			rb_n(t_two_stacks *ts_ptr, int n);
void			rr_n(t_two_stacks *ts_ptr, int n);
//------------------------------------------------------------------------------
// reverse_rotate_operations.c
//----------------------------
void			rra(t_two_stacks *stacks_ptr);
void			rrb(t_two_stacks *stacks_ptr);
void			rrr(t_two_stacks *stacks_ptr);
//------------------------------------------------------------------------------
// reverse_rotate_n_operations.c
//------------------------------
void			rra_n(t_two_stacks *ts_ptr, int n);
void			rrb_n(t_two_stacks *ts_ptr, int n);
void			rrr_n(t_two_stacks *ts_ptr, int n);
//------------------------------------------------------------------------------
// stack.c
//--------
int				push(t_stack *stack, int num);
int				pop(t_stack *stack);
int				peek(t_stack *stack);
void			print_stack(const t_stack *stack);
int				stack_contains_number(const t_stack *stack, int num);
//------------------------------------------------------------------------------
#endif
