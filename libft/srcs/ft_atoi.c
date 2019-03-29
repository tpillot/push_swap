/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:51:28 by tpillot           #+#    #+#             */
/*   Updated: 2018/11/15 17:51:30 by tpillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_atoi(const char *str)
{
	int				i;
	int				j;
	intmax_t		x;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	j = i;
	if (str[i] == '-' || str[i] == '+')
		i++;
	x = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		x = x * 10 + str[i] - 48;
		i++;
	}
	if (str[j] == '-')
		x = -x;
	return (x);
}
