/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:30:53 by tpillot           #+#    #+#             */
/*   Updated: 2018/12/10 19:53:47 by tpillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		countnbr(int n)
{
	int				count;
	unsigned int	t;

	count = 0;
	if (n < 0)
	{
		t = -n;
		count++;
	}
	else
		t = n;
	if (t == 0)
		count++;
	while (t > 0)
	{
		t /= 10;
		count++;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	char			*str;
	int				count;
	unsigned int	t;

	count = countnbr(n);
	if (!(str = ft_strnew(count)))
		return (NULL);
	str[count] = '\0';
	count--;
	if (n < 0)
		t = -n;
	else
		t = n;
	while (count >= 0)
	{
		str[count] = t % 10 + 48;
		t /= 10;
		count--;
	}
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	return (str);
}
