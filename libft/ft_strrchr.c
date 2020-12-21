/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekauppil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:08:59 by ekauppil          #+#    #+#             */
/*   Updated: 2019/10/23 16:47:32 by ekauppil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s) + 1;
	while (i > 0)
		if (*(s + (i - 1)) == (char)c)
			return ((char*)(s + (i - 1)));
		else
		{
			i--;
			if (i == 0)
				return (NULL);
		}
	return (NULL);
}
