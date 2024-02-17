/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:04:14 by ccormon           #+#    #+#             */
/*   Updated: 2024/01/23 11:41:48 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	count_node(t_stack_node *stack)
{
	size_t	nb_node;

	if (!stack)
		return (0);
	nb_node = 0;
	while (stack)
	{
		nb_node++;
		stack = stack->next;
	}
	return (nb_node);
}

t_stack_node	*find_min(t_stack_node *stack)
{
	t_stack_node	*min;

	min = stack;
	while (stack)
	{
		if (stack->nb < min->nb)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_stack_node	*find_max(t_stack_node *stack)
{
	t_stack_node	*max;

	max = stack;
	while (stack)
	{
		if (stack->nb > max->nb)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_stack_node	*find_closest_smaller(int nb, t_stack_node *stack)
{
	t_stack_node	*closest_smaller;

	closest_smaller = find_min(stack);
	if (closest_smaller->nb > nb)
		return (find_max(stack));
	while (stack)
	{
		if (stack->nb < nb && stack->nb > closest_smaller->nb)
			closest_smaller = stack;
		stack = stack->next;
	}
	return (closest_smaller);
}

t_stack_node	*find_closest_bigger(int nb, t_stack_node *stack)
{
	t_stack_node	*closest_bigger;

	closest_bigger = find_max(stack);
	if (closest_bigger->nb < nb)
		return (find_min(stack));
	while (stack)
	{
		if (stack->nb > nb && stack->nb < closest_bigger->nb)
			closest_bigger = stack;
		stack = stack->next;
	}
	return (closest_bigger);
}
