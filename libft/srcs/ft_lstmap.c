/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:52:15 by tpillot           #+#    #+#             */
/*   Updated: 2018/12/04 17:52:17 by tpillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*begin;

	if (lst == NULL)
		return (NULL);
	tmp1 = f(lst);
	new = ft_lstnew(tmp1->content, tmp1->content_size);
	if (new == NULL)
		return (NULL);
	tmp2 = new;
	begin = new;
	lst = lst->next;
	while (lst)
	{
		tmp1 = f(lst);
		new = ft_lstnew(tmp1->content, tmp1->content_size);
		if (new == NULL)
			return (NULL);
		tmp2->next = new;
		tmp2 = new;
		lst = lst->next;
	}
	return (begin);
}
