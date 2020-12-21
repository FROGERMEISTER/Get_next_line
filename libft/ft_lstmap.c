/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekauppil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:01:08 by ekauppil          #+#    #+#             */
/*   Updated: 2019/11/05 17:22:18 by ekauppil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*tmp;

	if (!(first = f(lst)))
		return (NULL);
	lst = lst->next;
	tmp = first;
	while (lst)
	{
		if (!(tmp->next = f(lst)))
			return (NULL);
		lst = lst->next;
		tmp = tmp->next;
	}
	return (first);
}
