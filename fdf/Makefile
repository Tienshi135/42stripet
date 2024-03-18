Name = fdf
Flags = -Wall -Werror -Wextra
Libraries = -lmlx -lm -lft -L ./libft -L ./minilibx_macos -framework OpenGL -framework AppKit

src =	./source/*.c

all:$(Name)

$(Name):
	gcc $(Flags) $(Libraries) $(src) -o $(Name)

re:
	make fclean
	make all

fclean:
	make clean

clean:
	rm -f $(Name)

debug:
	gcc $(Flags) -g $(Libraries) $(src) -o $(Name)

sanitize:
	gcc $(Flags) -g -fsanitize=address $(Libraries) $(src) -o $(Name)