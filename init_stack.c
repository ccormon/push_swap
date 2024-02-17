/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:03:56 by ccormon           #+#    #+#             */
/*   Updated: 2024/01/23 11:04:40 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_bottom(t_stack_node *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	append_node(t_stack_node **stack, int nb)
{
	t_stack_node	*node;
	t_stack_node	*bottom;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		exit_error();
	node->next = NULL;
	node->nb = nb;
	if (!(*stack))
	{
		node->prev = NULL;
		*stack = node;
		return ;
	}
	bottom = find_bottom(*stack);
	bottom->next = node;
	node->prev = bottom;
}

void	init_stack_a(t_stack_node **a, char **argv)
{
	size_t			i;

	i = 0;
	while (argv[i])
		append_node(a, (int)ft_atoll(argv[i++]));
}
