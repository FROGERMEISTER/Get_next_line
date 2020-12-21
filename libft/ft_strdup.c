/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekauppil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:38:14 by ekauppil          #+#    #+#             */
/*   Updated: 2019/10/21 18:50:12 by ekauppil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = -1;
	str = ft_strnew(ft_strlen(s1));
	if (str)
	{
		while (s1[++i])
			str[i] = s1[i];
		str[i] = '\0';
	}
	return (str);
}
