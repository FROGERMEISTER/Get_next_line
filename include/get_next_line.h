/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekauppil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:51:33 by ekauppil          #+#    #+#             */
/*   Updated: 2019/12/09 11:16:04 by ekauppil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "../libft/libft.h"
# define BUFF_SIZE 1000
# define MAXRC 30000
# define MAX_FD 512

int	get_next_line(const int fd, char **line);

#endif
