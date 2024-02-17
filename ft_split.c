/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccormon <ccormon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:03:48 by ccormon           #+#    #+#             */
/*   Updated: 2024/01/23 11:04:40 by ccormon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*addtoreaded(char *s, int c)
{
	char	*new_s;
	size_t	i;

	i = 0;
	if (!s)
	{
		new_s = malloc(2 * sizeof(char));
		if (!new_s)
			return (NULL);
	}
	else
	{
		new_s = malloc((ft_strlen(s) + 2) * sizeof(char));
		if (!new_s)
			return (NULL);
		while (s[i])
		{
			new_s[i] = s[i];
			i++;
		}
	}
	new_s[i] = c;
	new_s[i + 1] = '\0';
	free(s);
	return (new_s);
}

int	ft_countword(char const *s, char c)
{
	int	nbword;
	int	i;

	if (s[0] == '\0')
		return (0);
	nbword = 0;
	i = 0;
	if (s[i] != c)
	{
		nbword++;
		i++;
	}
	while (s[i] != '\0')
	{
		if (s[i - 1] == c && s[i] != c)
			nbword++;
		i++;
	}
	return (nbword);
}

char	*ft_allocword(char const *s, char c, int const i)
{
	char	*word;
	int		j;

	j = 0;
	while (s[i + j] != '\0' && s[i + j] != c)
		j++;
	word = malloc((j + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	j = 0;
	while (s[i + j] != '\0' && s[i + j] != c)
	{
		word[j] = s[i + j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		nbword;
	int		word;
	int		i;

	nbword = ft_countword(s, c);
	tab = (char **)malloc((nbword + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	i = 0;
	word = 0;
	while (s[i] != '\0' && word < nbword)
	{
		if ((i > 0 && s[i - 1] == c && s[i] != c) || (i == 0 && s[i] != c))
		{
			tab[word] = ft_allocword(s, c, i);
			word++;
		}
		i++;
	}
	tab[word] = NULL;
	return (tab);
}
