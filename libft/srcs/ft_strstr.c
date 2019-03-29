/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:48:20 by tpillot           #+#    #+#             */
/*   Updated: 2018/11/15 16:48:24 by tpillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (haystack[i] == '\0' && needle[i] == '\0')
		return ((char*)haystack);
	while (haystack[i])
	{
		k = i;
		while (haystack[k] == needle[j] && haystack[k] != '\0')
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
