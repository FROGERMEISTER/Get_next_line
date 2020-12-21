/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekauppil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:03:42 by ekauppil          #+#    #+#             */
/*   Updated: 2019/10/28 15:18:13 by ekauppil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	resultlen;

	len = ft_strlen(dst);
	len = (dstsize < len ? dstsize : len) + ft_strlen(src);
	if (dstsize <= ft_strlen(dst))
		return (len);
	if (dstsize - ft_strlen(dst) - 1 < ft_strlen(src))
		resultlen = dstsize - ft_strlen(dst) - 1;
	else
		resultlen = ft_strlen(src);
	*(dst + ft_strlen(dst) + resultlen) = '\0';
	ft_memcpy(dst + ft_strlen(dst), src, resultlen);
	return (len);
}
