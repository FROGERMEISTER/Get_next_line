# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekauppil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/14 13:42:32 by ekauppil          #+#    #+#              #
#    Updated: 2020/08/07 14:12:48 by ekauppil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line
SRCS = ./get_next_line.c ./main.c
OBJS = ./get_next_line.o ./main.o
HDR = ./include
FLAGS = -g

LIBFT = ./libft/

all: $(NAME)

$(NAME):
	mingw32-make.exe -C $(LIBFT)
	gcc $(FLAGS) -o $(NAME) $(SRCS) -I$(HDR) -Llibft/ -lft

clean:
	del $(OBJS)
	mingw32-make.exe -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	mingw32-make.exe -C $(LIBFT) fclean

re: fclean all
