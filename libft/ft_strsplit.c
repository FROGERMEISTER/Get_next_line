/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekauppil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:53:26 by ekauppil          #+#    #+#             */
/*   Updated: 2019/11/05 17:20:16 by ekauppil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strsplit_countwords(char const *s, char c)
{
	int	words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			words++;
		if (!(s = ft_strchr(s, c)))
			break ;
	}
	return (words);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**strs;
	size_t	words;
	size_t	i;
	size_t	length;

	words = ft_strsplit_countwords(s, c);
	strs = (char**)ft_memalloc(sizeof(char*) * (words + 1));
	if (!strs)
		return (NULL);
	i = 0;
	while (*s && i < words)
	{
		length = 0;
		while (*s == c)
			s++;
		while (*(s + length) && *(s + length) != c)
			length++;
		if (!(*(strs + i) = ft_strnew(length)))
			return (NULL);
		ft_strncpy(*(strs + i++), s, length);
		if (!(s = ft_strchr(s, c)))
			break ;
	}
	return (strs);
}
