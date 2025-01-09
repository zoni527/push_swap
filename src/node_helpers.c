/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:15:09 by jvarila           #+#    #+#             */
/*   Updated: 2025/01/09 15:18:05 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

int	node_val(t_list *node)
{
	if (!node)
		return (INT_MIN);
	return (*(int *)node->content);
}
