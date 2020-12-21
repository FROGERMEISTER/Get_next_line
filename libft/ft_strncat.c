/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekauppil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:41:47 by ekauppil          #+#    #+#             */
/*   Updated: 2019/11/06 14:13:03 by ekauppil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	*(s1 + (ft_strlen(s1) + (ft_strlen(s2) < n ? ft_strlen(s2) : n))) = '\0';
	ft_memcpy(s1 + ft_strlen(s1), s2, (ft_strlen(s2) < n) ? ft_strlen(s2) : n);
	return (s1);
}
