/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekauppil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:05:13 by ekauppil          #+#    #+#             */
/*   Updated: 2019/11/05 17:18:41 by ekauppil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	index;
	size_t	start;
	size_t	length;
	char	*str;

	if (ft_strlen(s) == 0)
		return (ft_strnew(0));
	index = 0;
	while (*(s + index) && (*(s + index) == ' '
		|| *(s + index) == '\n' || *(s + index) == '\t'))
		index++;
	start = index;
	index = ft_strlen(s) - 1;
	while (*(s + index) && index > start && (*(s + index) == ' '
		|| *(s + index) == '\n' || *(s + index) == '\t'))
		index--;
	length = index - start + 1;
	if (!(str = ft_strnew(length)))
		return (NULL);
	return (ft_strncpy(str, s + start, length));
}
