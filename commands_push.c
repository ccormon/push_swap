/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:02:55 by ccormon           #+#    #+#             */
/*   Updated: 2024/01/23 11:02:57 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack_node **src, t_stack_node **dest)
{
	if (!src || !(*src))
		return ;
	if (!(*dest))
	{
		*dest = *src;
		*src = (*src)->next;
		(*src)->prev = NULL;
		(*dest)->next = NULL;
		return ;
	}
	(*dest)->prev = *src;
	if (!(*src)->next)
		*src = NULL;
	else
	{
		*src = (*src)->next;
		(*src)->prev = NULL;
	}
	(*dest)->prev->next = *dest;
	*dest = (*dest)->prev;
}

void	pa(t_stack_node **b, t_stack_node **a)
{
	push(b, a);
	ft_printf("pa\n");
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	ft_printf("pb\n");
}
