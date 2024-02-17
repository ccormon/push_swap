/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:03:25 by ccormon           #+#    #+#             */
/*   Updated: 2024/01/23 11:04:40 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_printfchar(int c)
{
	ft_putchar(c);
	return (1);
}

int	ft_printfhex(unsigned long long n, char *basehex)
{
	int	nlen;

	ft_puthex(n, basehex);
	if (n == 0)
		return (1);
	nlen = 0;
	while (n != 0)
	{
		n /= 16;
		nlen++;
	}
	return (nlen);
}

int	ft_printfnbr(int n)
{
	unsigned int	number;
	int				nlen;

	nlen = 0;
	if (n < 0)
	{
		ft_putchar('-');
		nlen++;
		number = -n;
	}
	else
		number = n;
	ft_putnbr(number);
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number /= 10;
		nlen++;
	}
	return (nlen);
}

int	ft_printfpointer(unsigned long long n, char *basehex)
{
	int	nlen;

	if (n == 0)
		return (ft_printfstr("(nil)"));
	ft_putstr("0x");
	nlen = 2;
	ft_puthex(n, basehex);
	while (n != 0)
	{
		n /= 16;
		nlen++;
	}
	return (nlen);
}

int	ft_printfstr(char *s)
{
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr(s);
	return (ft_strlen(s));
}
