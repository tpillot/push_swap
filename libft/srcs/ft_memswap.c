/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:52:41 by tpillot           #+#    #+#             */
/*   Updated: 2018/12/04 17:52:43 by tpillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memswap(void *ptr1, void *ptr2, size_t size)
{
	char tmp[size];

	ft_memcpy(tmp, ptr1, size);
	ft_memcpy(ptr1, ptr2, size);
	ft_memcpy(ptr2, tmp, size);
}
