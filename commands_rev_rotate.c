/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_rev_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:03:04 by ccormon           #+#    #+#             */
/*   Updated: 2024/01/23 11:04:40 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack_node **top)
{
	t_stack_node	*bottom;

	if (!(*top))
		return ;
	bottom = find_bottom(*top);
	bottom->prev->next = NULL;
	(*top)->prev = bottom;
	bottom->next = *top;
	bottom->prev = NULL;
	*top = (*top)->prev;
}

void	rra(t_stack_node **a)
{
	rev_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack_node **b)
{
	rev_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("rrr\n");
}
