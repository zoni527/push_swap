/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:39:34 by jvarila           #+#    #+#             */
/*   Updated: 2024/12/27 17:39:53 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_sorted(t_stack *stack_ptr);
void		merge_sorted_portions_and_rotate_to_end(t_two_stacks *ts_ptr);

int			first_int_larger(int a, int b);
int			first_int_smaller(int a, int b);

int			node_val(t_list *node);
int			last_element_val(t_stack *stack_ptr);
int			top_sorted_sublist_len(t_stack *stack_ptr);
int			bottom_sorted_sublist_len(t_stack *stack_ptr);
int			sublist_len(t_list *node, int order);
int			count_sorted_sublists(t_stack *stack);
void		skip_sorted_sublist(t_list **node_ptr, int order);

void		sort_three(t_two_stacks *ts_ptr);
void		sort_a_b_c(t_two_stacks *ts_ptr, int a, int b, int c);

void		normalize_stack(t_stack *stack);
t_list		*next_larger_node(t_list *lst, int num);
t_list		*next_smaller_node(t_list *lst, int num);
void		insertion_sort(t_two_stacks *ts_ptr);

t_list		*min_node(t_list *lst);
t_list		*max_node(t_list *lst);

int	element_val(t_stack *stack_ptr, int index);
int	element_index(t_stack *stack_ptr, int num);
int	element_to_push_on_index(t_stack *stack_ptr, int num);

void	ra_n(t_two_stacks *ts_ptr, int n);
void	rb_n(t_two_stacks *ts_ptr, int n);
void	rra_n(t_two_stacks *ts_ptr, int n);
void	rrb_n(t_two_stacks *ts_ptr, int n);
void	rr_n(t_two_stacks *ts_ptr, int n);
void	rrr_n(t_two_stacks *ts_ptr, int n);

void	reset_instructions(t_instructions *instructions_ptr);

void	sort_stack(t_two_stacks *ts_ptr)
{
	ts_ptr->a.order = ASCENDING;
	ts_ptr->b.order = DESCENDING;
	if (stack_sorted(&ts_ptr->a))
		return ;
	if (ts_ptr->a.size == 2)
		return (sa(ts_ptr));
	if (ts_ptr->a.size == 3)
		return (sort_three(ts_ptr));
	// normalize_stack(&ts_ptr->a);
	insertion_sort(ts_ptr);
}

static int	stack_sorted(t_stack *stack_ptr)
{
	t_list	*node;
	int		(*comp)(int a, int b);

	if (stack_ptr->size == 1)
		return (1);
	node = stack_ptr->top;
	if (stack_ptr->order == ASCENDING)
		comp = first_int_larger;
	else
		comp = first_int_smaller;
	while (node->next)
	{
		if (comp(node_val(node), node_val(node->next)))
			return (0);
		node = node->next;
	}
	return (1);
}

void	sort_three(t_two_stacks *ts_ptr)
{
	int	first;
	int	second;
	int	third;

	first = node_val(ts_ptr->a.top);
	second = node_val(ts_ptr->a.top->next);
	third = node_val(ts_ptr->a.top->next->next);
	sort_a_b_c(ts_ptr, first, second, third);
}

// The combinations of comparisons correspong to the 5 different sortable
// cases for three numbers, for ascending order this means 1 3 2, 2 1 3,
// 2 3 1, 3 1 2 and 3 2 1. Changing the function to first_int_larger flips
// the comparisons and correctly sorts three numbers in descending order.
void	sort_a_b_c(t_two_stacks *ts_ptr, int a, int b, int c)
{
	int	(*comp)(int a, int b);

	if (ts_ptr->a.order == ASCENDING)
		comp = first_int_smaller;
	else
		comp = first_int_larger;
	if (comp(b, a) && comp(b, c) && comp(c, a))
		ra(ts_ptr);
	if (comp(a, b) && comp(c, b) && comp(c, a))
		rra(ts_ptr);
	if (comp(b, a) && comp(b, c) && comp(a, c))
		sa(ts_ptr);
	if (comp(a, b) && comp(c, b) && comp(a, c))
	{
		sa(ts_ptr);
		ra(ts_ptr);
	}
	if (comp(b, a) && comp(c, b))
	{
		sa(ts_ptr);
		rra(ts_ptr);
	}
}

// Change the values of the stack elements to be consecutive integers starting
// from 0. These values can be useful when comparing against the total size
// of the stack and when calculating the amount of moves needed.
void	normalize_stack(t_stack *stack)
{
	int		max;
	t_stack temp;
	t_list	*node;

	if (!stack->size)
		return ;
	temp = (t_stack){0};
	node = max_node(stack->top);
	while (node)
	{
		push(&temp, node_val(node));
		max = node_val(node);
		node = next_smaller_node(stack->top, max);
	}
	node = stack->top;
	while (node)
	{
		*(int *)node->content = element_index(&temp, node_val(node));
		node = node->next;
	}
	while (temp.size)
		pop(&temp);
}

t_list	*min_node(t_list *lst)
{
	int		min;
	t_list	*node;

	if (!lst)
		return (NULL);
	if (!lst->next)
		return (lst);
	min = INT_MAX;
	node = NULL;
	while (lst)
	{
		if (node_val(lst) <= min)
		{
			min = node_val(lst);
			node = lst;
		}
		lst = lst->next;
	}
	return (node);
}

t_list	*max_node(t_list *lst)
{
	int		max;
	t_list	*node;

	if (!lst)
		return (NULL);
	if (!lst->next)
		return (lst);
	max = INT_MIN;
	node = NULL;
	while (lst)
	{
		if (node_val(lst) >= max)
		{
			max = node_val(lst);
			node = lst;
		}
		lst = lst->next;
	}
	return (node);
}

int	min_val(t_stack *stack_ptr)
{
	return (node_val(min_node(stack_ptr->top)));
}

int	max_val(t_stack *stack_ptr)
{
	return (node_val(max_node(stack_ptr->top)));
}

t_list	*next_larger_node(t_list *lst, int num)
{
	int		previous_min;
	int		val;
	t_list	*node;

	if (!lst)
		return (NULL);
	if (!lst->next)
		return (lst);
	previous_min = INT_MAX;
	node = NULL;
	while (lst)
	{
		val = node_val(lst);
		if (val > num && val <= previous_min)
		{
			node = lst;
			previous_min = val;
		}
		lst = lst->next;
	}
	return (node);
}

int	next_larger_val(t_stack *stack_ptr, int num)
{
	return (node_val(next_larger_node(stack_ptr->top, num)));
}

t_list	*next_smaller_node(t_list *lst, int num)
{
	int		previous_max;
	int		val;
	t_list	*node;

	if (!lst)
		return (NULL);
	if (!lst->next)
		return (lst);
	previous_max = INT_MIN;
	node = NULL;
	while (lst)
	{
		val = node_val(lst);
		if (val < num && val >= previous_max)
		{
			node = lst;
			previous_max = val;
		}
		lst = lst->next;
	}
	return (node);
}

int	next_smaller_val(t_stack *stack_ptr, int num)
{
	return (node_val(next_smaller_node(stack_ptr->top, num)));
}

void	insertion_sort(t_two_stacks *ts_ptr)
{
	int				moves_a_up;
	int				moves_a_down;
	int				moves_b_up;
	int				moves_b_down;
	int				i;
	int				cost1;
	int				cost2;
	int				cost3;
	int				cost4;
	t_instructions	instructions;
	t_list			*node;

	pb(ts_ptr);
	while (ts_ptr->a.size > 3)
	{
		node = ts_ptr->a.top;
		i = -1;
		reset_instructions(&instructions);
		instructions.cost = INT_MAX;
		while (++i < ts_ptr->a.size)
		{
			moves_a_up = i;
			moves_a_down = ts_ptr->a.size - moves_a_up;
			moves_b_up = element_to_push_on_index(&ts_ptr->b, node_val(node));
			moves_b_down = ts_ptr->b.size - moves_b_up;

			cost1 = larger_int(moves_a_up, moves_b_up);
			cost2 = larger_int(moves_a_down, moves_b_down);
			cost3 = moves_a_up + moves_b_down;
			cost4 = moves_b_up + moves_a_down;

			if (cost1 < instructions.cost)
			{
				reset_instructions(&instructions);
				instructions.cost = cost1;
				instructions.rr = smaller_int(moves_a_up, moves_b_up);
				if (moves_a_up > moves_b_up)
					instructions.ra = moves_a_up - moves_b_up;
				else
					instructions.rb = moves_b_up - moves_a_up;
			}
			if (cost2 < instructions.cost)
			{
				reset_instructions(&instructions);
				instructions.cost = cost2;
				instructions.rrr = smaller_int(moves_a_down, moves_b_down);
				if (moves_a_down > moves_b_down)
					instructions.rra = moves_a_down - moves_b_down;
				else
					instructions.rrb = moves_b_down - moves_a_down;
			}
			if (cost3 < instructions.cost)
			{
				reset_instructions(&instructions);
				instructions.cost = cost3;
				instructions.ra = moves_a_up;
				instructions.rrb = moves_b_down;
			}
			if (cost4 < instructions.cost)
			{
				reset_instructions(&instructions);
				instructions.cost = cost4;
				instructions.rra = moves_a_down;
				instructions.rb = moves_b_up;
			}
			node = node->next;
		}
		rr_n(ts_ptr, instructions.rr);
		rrr_n(ts_ptr, instructions.rrr);
		ra_n(ts_ptr, instructions.ra);
		rb_n(ts_ptr, instructions.rb);
		rra_n(ts_ptr, instructions.rra);
		rrb_n(ts_ptr, instructions.rrb);
		pb(ts_ptr);
	}
	if (!stack_sorted(&ts_ptr->b))
	{
		moves_b_up = element_index(&ts_ptr->b, max_val(&ts_ptr->b));
		moves_b_down = ts_ptr->b.size - moves_b_up;
		if (moves_b_up < moves_b_down)
			rb_n(ts_ptr, moves_b_up);
		else
			rrb_n(ts_ptr, moves_b_down);
	}
	sort_three(ts_ptr);
	while (ts_ptr->b.size 
		&& node_val(ts_ptr->b.top) > last_element_val(&ts_ptr->a))
		pa(ts_ptr);
	if (!ts_ptr->b.size)
	{
		if (stack_sorted(&ts_ptr->a))
			return ;
		moves_a_up = element_index(&ts_ptr->a, min_val(&ts_ptr->a));
		moves_a_down = ts_ptr->a.size - moves_a_up;
		if (moves_a_up < moves_a_down)
			ra_n(ts_ptr, moves_a_up);
		else
			rra_n(ts_ptr, moves_a_down);
	}
	while (ts_ptr->b.size)
	{
		moves_a_up = element_to_push_on_index(&ts_ptr->a, node_val(ts_ptr->b.top));
		moves_a_down = ts_ptr->a.size - moves_a_up;
		if (moves_a_up < moves_a_down)
			ra_n(ts_ptr, moves_a_up);
		else
			rra_n(ts_ptr, moves_a_down);
		pa(ts_ptr);
	}
	if (!stack_sorted(&ts_ptr->a))
	{
		moves_a_up = element_index(&ts_ptr->a, min_val(&ts_ptr->a));
		moves_a_down = ts_ptr->a.size - moves_a_up;
		if (moves_a_up < moves_a_down)
			ra_n(ts_ptr, moves_a_up);
		else
			rra_n(ts_ptr, moves_a_down);
	}
}

void	reset_instructions(t_instructions *instructions_ptr)
{
	instructions_ptr->ra = 0;
	instructions_ptr->rb = 0;
	instructions_ptr->rra = 0;
	instructions_ptr->rrb = 0;
	instructions_ptr->rr = 0;
	instructions_ptr->rrr = 0;
	instructions_ptr->cost = 0;
}

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

void	rr_n(t_two_stacks *ts_ptr, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		rr(ts_ptr);
}

void	rrr_n(t_two_stacks *ts_ptr, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		rrr(ts_ptr);
}

int	element_val(t_stack *stack_ptr, int index)
{
	t_list	*node;
	int		i;

	if (index < 0 || index >= stack_ptr->size)
		return (INT_MIN);
	node = stack_ptr->top;
	i = -1;
	while (++i < index)
		node = node->next;
	return (node_val(node));
}

int	element_index(t_stack *stack_ptr, int num)
{
	int		index;
	t_list	*node;

	index = -1;
	node = stack_ptr->top;
	while (++index < stack_ptr->size)
	{
		if (node_val(node) == num)
			return (index);
		node = node->next;
	}
	return (-1);
}

int	element_to_push_on_index(t_stack *stack_ptr, int num)
{
	int	max;
	int	min;

	if (stack_ptr->size < 2)
		return (0);
	max = max_val(stack_ptr);
	min = min_val(stack_ptr);
	if (stack_ptr->order == DESCENDING && (num > max || num < min))
		return (element_index(stack_ptr, max));
	if (stack_ptr->order == ASCENDING && (num > max || num < min))
		return(element_index(stack_ptr, min));
	if (stack_ptr->order == ASCENDING)
		return(element_index(stack_ptr, next_larger_val(stack_ptr, num)));
	else
		return(element_index(stack_ptr, next_smaller_val(stack_ptr, num)));
}

int	last_element_val(t_stack *stack_ptr)
{
	t_list *node;

	node = stack_ptr->top;
	if (!node)
		return (INT_MIN);
	if (!node->next)
		return (node_val(node));
	while (node->next)
		node = node->next;
	return (node_val(node));
}

int	first_int_larger(int a, int b)
{
	return (a > b);
}

int	first_int_smaller(int a, int b)
{
	return (a < b);
}

int	node_val(t_list *node)
{
	if (!node)
		return (INT_MIN);
	return (*(int *)node->content);
}
