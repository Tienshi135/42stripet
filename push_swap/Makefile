Name = push_swap
CFLAGS = -Wall -Werror -Wextra
Libraries = -lft -L ./libft

src_dir = ./source
bonus_dir = ./source/bonus
src = $(src_dir)/push_swap.c\
      $(src_dir)/reverse.c\
      $(src_dir)/rotate.c\
	  $(src_dir)/swap.c\
	  $(src_dir)/push.c\
	  $(src_dir)/utils.c\
	  $(src_dir)/errors.c\

bonus_src = $(bonus_dir)/errors_bonus.c\
			$(bonus_dir)/pipex_bonus.c\
			$(bonus_dir)/utils_bonus.c\

obj = $(src:.c=.o)
bonus_obj = $(bonus_src:.c=.o)

all: $(Name)

$(Name):$(obj)
	gcc $(Libraries) $^ -o $@

bonus:$(bonus_obj)
	gcc $(Libraries) $^ -o $(Name)

clean:
	rm -f $(src_dir)/*.o
	rm -f $(bonus_dir)/*.o

fclean: clean
	rm -f $(Name)

re: fclean all

bre: fclean bonus

debug:
	gcc -g $(CFLAGS) $(Libraries) $(src) -o $(Name)

bdebug:
	gcc -g $(CFLAGS) $(Libraries) $(bonus_src) -o $(Name)

sanitize:
	gcc -g -fsanitize=address $(CFLAGS) $(Libraries) $(src) -o $(Name)

bsanitize:
	gcc -g -fsanitize=address $(CFLAGS) $(Libraries) $(bonus_src) -o $(Name)
