/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekauppil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:16:44 by ekauppil          #+#    #+#             */
/*   Updated: 2019/11/06 18:15:33 by ekauppil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	ft_memcpy(dst, src, (ft_strlen(src) < len) ? ft_strlen(src) : len);
	if (ft_strlen(src) < len)
		ft_memset(dst + ft_strlen(src), '\0', len - ft_strlen(src));
	return (dst);
}
