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

src =	ft_printf.c\
		./ConversationFunctions/printchar.c\
		./ConversationFunctions/printdecimal.c\
		./ConversationFunctions/printhexadecimall.c\
		./ConversationFunctions/printhexadecimalu.c\
		./ConversationFunctions/printinteger.c\
		./ConversationFunctions/printpointer.c\
		./ConversationFunctions/printstring.c\
		./ConversationFunctions/printunsigneddecimal.c\

obj = $(src:%.c=%.o)

all:$(NAME)

$(NAME):$(obj)
	make -C ./libft all
	cp ./libft/libft.a $(NAME)
	ar rcs	$(NAME) $(obj) 
	
clean:
	rm -f $(obj)

fclean:
	rm -f $(NAME)
	make clean

libftclean:
	make -C ./libft clean

libftfclean:
	make -C ./libft fclean

allclean:
	make clean
	make libftclean

allfclean:
	make fclean
	make libftfclean

re:
	make fclean
	make all
	
debug:
	gcc -g *.c ./ConversationFunctions/*.c -L. ./libft/libft.a

executable:
	gcc $(CFLAGS) main.c -L. libftprintf.a
