/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekauppil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 19:33:40 by ekauppil          #+#    #+#             */
/*   Updated: 2019/11/05 13:09:15 by ekauppil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlst;

	newlst = (t_list*)malloc(sizeof(*newlst));
	if (!newlst)
		return (NULL);
	newlst->next = NULL;
	if (!content || content_size == 0)
	{
		newlst->content = NULL;
		newlst->content_size = 0;
		return (newlst);
	}
	newlst->content = malloc(content_size);
	ft_memcpy(newlst->content, content, content_size);
	newlst->content_size = content_size;
	return (newlst);
}
