/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekauppil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:50:24 by ekauppil          #+#    #+#             */
/*   Updated: 2019/10/23 16:52:54 by ekauppil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	j;
	size_t	i;
	size_t	nlength;

	i = 0;
	nlength = ft_strlen(needle);
	if (nlength == 0)
		return ((char*)haystack);
	while (*(haystack + i) && i < len)
	{
		j = 0;
		while (*(haystack + (i + j)) == *(needle + j) && i + j < len)
		{
			if (j + 1 == nlength)
				return ((char*)(haystack + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
