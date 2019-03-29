/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:33:14 by tpillot           #+#    #+#             */
/*   Updated: 2018/11/29 14:33:16 by tpillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	t;

	if (n < 0)
	{
		t = -n;
		ft_putchar_fd('-', fd);
	}
	else
		t = n;
	if (t > 9)
		ft_putnbr_fd(t / 10, fd);
	ft_putchar_fd(t % 10 + 48, fd);
}
