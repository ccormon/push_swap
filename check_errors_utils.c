/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:02:26 by ccormon           #+#    #+#             */
/*   Updated: 2024/01/23 12:00:11 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issame(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] || s2[i])
		return (0);
	return (1);
}

int	check_double(char **argv)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_issame(argv[i], argv[j])
				|| ft_atoll(argv[i]) == ft_atoll(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

long long	ft_atoll(char *s)
{
	long long	nb;
	int			sign;
	size_t		i;

	i = 0;
	sign = 1;
	if (s[i] && (s[i] == '+' || s[i] == '-'))
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	nb = 0;
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
	{
		nb = 10 * nb + s[i++] - '0';
		if (nb < INT_MIN || nb > INT_MAX)
			exit_error();
	}
	return (sign * nb);
}

int	ft_isdigit(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	if (s[i] && (s[i] == '+' || s[i] == '-'))
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_isint(char *s)
{
	if (!ft_isdigit(s))
		return (0);
	ft_atoll(s);
	return (1);
}
