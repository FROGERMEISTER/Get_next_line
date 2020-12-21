/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekauppil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:02:18 by ekauppil          #+#    #+#             */
/*   Updated: 2019/11/06 13:03:36 by ekauppil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	size_t	len;
	char	*str;

	i = n;
	len = 1;
	while ((i = i / 10))
		len++;
	if (n < 0)
		len++;
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (n == 0 && len--)
		*str = '0';
	while (len > 0 && n != 0)
	{
		*(str + --len) = ((n < 0) ? (n % 10) * -1 : n % 10) + '0';
		n = n / 10;
	}
	if (len > 0)
		*str = '-';
	return (str);
}
