/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:02:38 by ccormon           #+#    #+#             */
/*   Updated: 2024/01/23 11:43:47 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_errors(char **argv)
{
	size_t		i;

	if (!check_double(argv))
		exit_error();
	i = 0;
	while (argv[i])
	{
		if (!ft_isint(argv[i]))
			exit_error();
		i++;
	}
}
