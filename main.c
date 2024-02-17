/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:01:57 by ccormon           #+#    #+#             */
/*   Updated: 2024/02/01 17:54:20 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(void) // je ne free pas
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*tmp;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

bool	ft_issort(t_stack_node **stack)
{
	t_stack_node	*current;
	int				n;

	n = (*stack)->nb;
	current = (*stack)->next;
	while (current)
	{
		if (n > current->nb)
			return (false);
		n = current->nb;
		current = current->next;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc <= 1)
		return (EXIT_FAILURE);
	argv++;
	if (argc == 2)
		argv = ft_split(*argv, ' ');
	check_errors(argv);
	init_stack_a(&a, argv);
	if (!ft_issort(&a))
	{
		if (argc == 3)
			sa(&a);
		else if (argc == 4)
			sort_three(&a);
		else
			sort_turk(&a, &b);
	}
	free_stack(&a);
	return (EXIT_SUCCESS);
}
