CC = gcc
NAME = minishell
BONUS_NAME = minishell_bonus
CFLAGS = -Wall -Werror -Wextra
Libraries = -lft -L ./libft -lreadline

src_dir = ./source
bonus_dir =
src = 	$(src_dir)/minishell.c\
		$(src_dir)/errors.c\
		$(src_dir)/utils.c\
		$(src_dir)/parse.c\

bonus_src =

obj = $(src:.c=.o)
bonus_obj = $(bonus_src:.c=.o)

all: $(NAME)

$(NAME):$(obj)
	cc $(Libraries) $^ -o $@

bonus:$(bonus_obj)
	cc $(Libraries) $^ -o $(BONUS_NAME)

clean:
	rm -f $(src_dir)/*.o
	rm -f $(bonus_dir)/*.o

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all
	make clean

bre: fclean bonus
	make clean

debug:
	gcc -g $(CFLAGS) $(Libraries) $(src) -o $(NAME)

bdebug:
	gcc -g $(CFLAGS) $(Libraries) $(bonus_src) -o $(NAME)

sanitize:
	gcc -g -fsanitize=address $(CFLAGS) $(Libraries) $(src) -o $(NAME)

bsanitize:
	gcc -g -fsanitize=address $(CFLAGS) $(Libraries) $(bonus_src) -o $(NAME)