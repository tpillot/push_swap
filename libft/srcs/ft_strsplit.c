/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:37:56 by tpillot           #+#    #+#             */
/*   Updated: 2018/11/23 13:37:58 by tpillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		countw(const char *s, char c)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static	int		countl(const char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		count;
	int		count2;
	char	**str;

	if (s == NULL)
		return (NULL);
	count = countw(s, c);
	if (!(str = malloc(sizeof(str) * (count + 1))))
		return (NULL);
	i = 0;
	while (i < count)
	{
		while (*s == c)
			s++;
		count2 = countl(s, c);
		str[i] = ft_strsub(s, 0, count2);
		if (str[i] == NULL)
			return (NULL);
		s += count2;
		i++;
	}
	str[i] = NULL;
	return (str);
}
