/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:03:10 by ccormon           #+#    #+#             */
/*   Updated: 2024/01/23 11:04:40 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack_node **top)
{
	t_stack_node	*bottom;

	if (!(*top))
		return ;
	bottom = find_bottom(*top);
	(*top)->next->prev = NULL;
	bottom->next = *top;
	(*top)->next = NULL;
	(*top)->prev = bottom;
	while ((*top)->prev)
		*top = (*top)->prev;
}

void	ra(t_stack_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
