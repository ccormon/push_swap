/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:04:20 by ccormon           #+#    #+#             */
/*   Updated: 2024/01/23 11:04:31 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack_node **top)
{
	t_stack_node	*stack;
	int				index;

	if (!top || !(*top))
		return ;
	stack = *top;
	index = 0;
	while (stack)
	{
		stack->index = index;
		index++;
		stack = stack->next;
	}
}

void	set_median(t_stack_node **top)
{
	t_stack_node	*stack;
	size_t			nb_node;
	int				median;

	if (!top || !(*top))
		return ;
	stack = *top;
	median = find_bottom(stack)->index / 2;
	nb_node = count_node(stack);
	while (stack)
	{
		if (stack->index <= median)
		{
			stack->push_cost = stack->index;
			stack->above_median = true;
		}
		else
		{
			stack->push_cost = nb_node - stack->index;
			stack->above_median = false;
		}
		stack = stack->next;
	}
}

void	set_stack_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*stack;

	set_index(a);
	set_median(a);
	set_index(b);
	set_median(b);
	stack = *a;
	while (stack)
	{
		stack->target_node = find_closest_smaller(stack->nb, *b);
		stack->push_cost += stack->target_node->push_cost;
		stack = stack->next;
	}
}

t_stack_node	*find_cheapest(t_stack_node *stack)
{
	t_stack_node	*cheapest;

	if (!stack)
		return (NULL);
	cheapest = stack;
	while (stack)
	{
		if (stack->push_cost < cheapest->push_cost)
			cheapest = stack;
		stack = stack->next;
	}
	return (cheapest);
}

void	sort_turk_move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	while (count_node(*a) > 3)
	{
		set_stack_a_to_b(a, b);
		cheapest = find_cheapest(*a);
		while ((*a)->nb != cheapest->nb)
		{
			if (cheapest->above_median)
				ra(a);
			else
				rra(a);
		}
		while ((*b)->nb != cheapest->target_node->nb)
		{
			if (cheapest->target_node->above_median)
				rb(b);
			else
				rrb(b);
		}
		pb(a, b);
	}
}
