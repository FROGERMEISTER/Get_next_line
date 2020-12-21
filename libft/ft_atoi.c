/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekauppil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:29:57 by ekauppil          #+#    #+#             */
/*   Updated: 2019/10/28 16:09:33 by ekauppil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int negative_nb;
	int nb;

	negative_nb = 0;
	while (*str && ((*str > 8 && *str < 14) || *str == 32))
		str++;
	if (*str == '-' && *(str + 1))
	{
		negative_nb = 1;
		str++;
	}
	else if (*str == '+' && *(str + 1))
		str++;
	nb = 0;
	while (*str && *str >= '0' && *str <= '9')
		nb = nb * 10 + ((*str++ - '0') * ((negative_nb) ? -1 : 1));
	return (nb);
}
