/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekauppil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:00:16 by ekauppil          #+#    #+#             */
/*   Updated: 2019/10/21 19:04:37 by ekauppil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char *s, char (*f)(char))
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
		*(str + i) = f(*(s + i));
		i++;
	}
	return (str);
}
