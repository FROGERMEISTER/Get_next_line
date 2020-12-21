/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekauppil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:15:38 by ekauppil          #+#    #+#             */
/*   Updated: 2019/10/21 19:07:32 by ekauppil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	char		*str;
	size_t		length;
	size_t		i;

	length = ft_strlen(s);
	str = ft_strnew(length);
	if (!str)
		return (NULL);
	i = 0;
	while (i < length)
	{
		*(str + i) = f(i, *(s + i));
		i++;
	}
	return (str);
}
