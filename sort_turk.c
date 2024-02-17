/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:04:27 by ccormon           #+#    #+#             */
/*   Updated: 2024/01/23 11:04:29 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_stack_b_to_a(t_stack_node **b, t_stack_node **a)
{
	t_stack_node	*stack;

	set_index(b);
	set_median(b);
	set_index(a);
	set_median(a);
	stack = *b;
	while (stack)
	{
		stack->target_node = find_closest_bigger(stack->nb, *a);
		stack->push_cost += stack->target_node->push_cost;
		stack = stack->next;
	}
}

void	sort_turk_move_b_to_a(t_stack_node **b, t_stack_node **a)
{
	t_stack_node	*cheapest;

	while ((*b))
	{
		set_stack_b_to_a(b, a);
		cheapest = find_cheapest(*b);
		while ((*b)->nb != cheapest->nb)
		{
			if (cheapest->above_median)
				rb(b);
			else
				rrb(b);
		}
		while ((*a)->nb != cheapest->target_node->nb)
		{
			if (cheapest->target_node->above_median)
				ra(a);
			else
				rra(a);
		}
		pa(b, a);
	}
}

void	sort_three(t_stack_node **a)
{
	if (count_node(*a) != 3)
		return ;
	if (ft_issort(a))
		return ;
	if ((*a)->nb < (*a)->next->nb)
	{
		rra(a);
		if (!ft_issort(a))
			sa(a);
		return ;
	}
	sa(a);
	if (!ft_issort(a))
	{
		rra(a);
		if (!ft_issort(a))
			sa(a);
	}
}

void	sort_turk(t_stack_node **a, t_stack_node **b)
{
	pb(a, b);
	if (count_node(*a) > 3)
		pb(a, b);
	sort_turk_move_a_to_b(a, b);
	sort_three(a);
	sort_turk_move_b_to_a(b, a);
	while (!ft_issort(a))
	{
		set_index(a);
		if (find_min(*a)->index <= find_bottom(*a)->index / 2)
			ra(a);
		else
			rra(a);
	}
}
