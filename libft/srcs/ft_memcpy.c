/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:19:37 by tpillot           #+#    #+#             */
/*   Updated: 2018/11/16 16:19:40 by tpillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptrd;
	unsigned char	*ptrs;
	size_t			i;

	ptrd = (unsigned char *)dst;
	ptrs = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		if (ptrd == ptrs)
			return (NULL);
		ptrd[i] = ptrs[i];
		i++;
	}
	return (dst);
}
