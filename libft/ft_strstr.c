/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekauppil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:18:17 by ekauppil          #+#    #+#             */
/*   Updated: 2019/10/23 16:48:45 by ekauppil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	j;
	size_t	i;
	size_t	nlength;

	i = 0;
	nlength = ft_strlen(needle);
	if (nlength == 0)
		return ((char*)haystack);
	while (*(haystack + i))
	{
		j = 0;
		while (*(haystack + (i + j)) == *(needle + j))
		{
			if (j + 1 == nlength)
				return ((char*)(haystack + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
