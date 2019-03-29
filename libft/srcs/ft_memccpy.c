/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:57:09 by tpillot           #+#    #+#             */
/*   Updated: 2018/11/16 18:57:12 by tpillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ptrd;
	unsigned char	*ptrs;
	unsigned char	a;
	size_t			i;

	ptrd = (unsigned char*)dst;
	ptrs = (unsigned char*)src;
	a = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		ptrd[i] = ptrs[i];
		if (ptrd[i] == a)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
