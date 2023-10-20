# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stripet <stripet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 10:21:12 by tienshi           #+#    #+#              #
#    Updated: 2023/10/18 11:30:38 by stripet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

src =	printf.c\
		
	
obj = $(src:%.c=%.o)

all:$(NAME)

$(NAME):$(obj)
	ar rcs	$(NAME) $(obj)
	
clean:
	rm -f $(obj)

fclean:
	rm -f $(NAME)
	make clean

re:
	make fclean
	make all
	
debug:
	make fclean
	gcc $(CFLAGS) -g -c $(src)
	make $(NAME)

executable:$(NAME)
	gcc $(CFLAGS) main.c -L. $(Name) -L. libft/libft.a
