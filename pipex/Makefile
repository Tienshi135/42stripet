Name = pipex
Flags = -Wall -Werror -Wextra
Libraries = -lft -L ./libft

src =	./source/*.c

all:$(Name)

$(Name):
	gcc $(Flags) $(Libraries) $(src) -o $(Name)

clean:
	rm -f $(Name)

fclean:
	make clean
	rm -rf $(Name:%=%.dSYM)

re:
	make clean
	make $(Name)

debug:
	gcc $(Flags) -g $(Libraries) $(src) -o $(Name)

sanitize:
	gcc $(Flags) -g -fsanitize=address $(Libraries) $(src) -o $(Name)