/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekauppil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:11:34 by ekauppil          #+#    #+#             */
/*   Updated: 2019/10/21 18:41:55 by ekauppil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	void	*start;

	if (len < 1 || !b)
		return (b);
	start = b;
	while (len-- > 0)
		*(unsigned char*)(b++) = (unsigned char)c;
	return (start);
}
