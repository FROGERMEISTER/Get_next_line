/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekauppil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:23:22 by ekauppil          #+#    #+#             */
/*   Updated: 2019/11/06 18:15:12 by ekauppil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i && *(s1 + i) && *(s2 + i) &&
		*(unsigned char*)(s1 + i) == *(unsigned char*)(s2 + i))
	{
		i++;
	}
	if (i == n)
		return (0);
	return (*(unsigned char*)(s1 + i) - *(unsigned char*)(s2 + i));
}
