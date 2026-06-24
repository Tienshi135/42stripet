Name = pipex
CFLAGS = -Wall -Werror -Wextra
Libraries = -lft -L ./libft

src_dir = ./source
bonus_dir = ./source/bonus
src = $(src_dir)/errors.c\
      $(src_dir)/pipex.c\
      $(src_dir)/utils.c\

bonus_src = $(bonus_dir)/errors_bonus.c\
			$(bonus_dir)/pipex_bonus.c\
			$(bonus_dir)/utils_bonus.c\

obj = $(src:.c=.o)
bonus_obj = $(bonus_src:.c=.o)

.PHONY: all libft bonus clean fclean re bre debug bdebug sanitize bsanitize test

all: libft $(Name)

libft:
	make -C ./libft

$(Name):$(obj)
	gcc $^ $(Libraries) -o $@

bonus: libft $(bonus_obj)
	gcc $(bonus_obj) $(Libraries) -o $(Name)

clean:
	rm -f $(src_dir)/*.o
	rm -f $(bonus_dir)/*.o

fclean: clean
	rm -f $(Name)

re: fclean all

bre: fclean bonus

debug:
	gcc -g $(CFLAGS) $(src) $(Libraries) -o $(Name)

bdebug:
	gcc -g $(CFLAGS) $(bonus_src) $(Libraries) -o $(Name)

sanitize:
	gcc -g -fsanitize=address $(CFLAGS) $(src) $(Libraries) -o $(Name)

bsanitize:
	gcc -g -fsanitize=address $(CFLAGS) $(bonus_src) $(Libraries) -o $(Name)
test:
	@make sanitize
	@printf '\n'
	-./$(Name)
	@printf '\n'
	-./$(Name) asdasd
	@printf '\n'
	-./$(Name) a s d a s d a s d

	@printf '\n'
	-./$(Name) "empty file" "cat" "hostname" "output.txt"
	@printf '\n'
	-./$(Name) "noperm.txt" "cat" "hostname" "noperm.txt"
	@printf '\n'
	-./$(Name) "input.txt" "cat" "wc -c" "output.txt"

	@printf '\n\n\n\n\n\n\n\n\n'

	@make re
	@printf '\n'
	-Leaks --atExit --quiet -- ./$(Name)
	@printf '\n'
	-Leaks --atExit --quiet -- ./$(Name) asdasd
	@printf '\n'
	-Leaks --atExit --quiet -- ./$(Name) a s d a s d a s d

	@printf '\n'
	-Leaks --atExit --quiet -- ./$(Name) "empty file" "cat" "hostname" "output.txt"
	@printf '\n'
	-Leaks --atExit --quiet -- ./$(Name) "noperm" "cat" "hostname" "noperm.txt"
	@printf '\n'
	-Leaks --atExit --quiet -- ./$(Name) "input.txt" "cat" "wc -c" "output.txt"
