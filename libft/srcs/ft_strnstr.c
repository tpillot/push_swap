/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:01:00 by tpillot           #+#    #+#             */
/*   Updated: 2018/11/15 17:01:04 by tpillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;
	size_t	k;

	i = 0;
	j = 0;
	while (haystack[i] && i < len)
	{
		k = i;
		while (haystack[k] == needle[j] && haystack[k] != '\0' && k < len)
		{
			j++;
			k++;
		}
		if (needle[j] == '\0')
			return ((char*)haystack + i);
		j = 0;
		i++;
	}
	if (haystack[i] == '\0')
		return (NULL);
	return (0);
}
