Name = fdf
Flags = -Wall -Werror -Wextra
Libraries = -lmlx -lm -lft -L ./libft -L ./minilibx_macos -framework OpenGL -framework AppKit

src =	fdf.c\
		fdf_utils.c\
		fdf_tools.c\
		control.c\

all:$(Name)

$(Name):
	gcc -fsanitize=address $(Flags) $(Libraries) $(src) -o $(Name)

re:
	rm fdf
	make

debug:
	gcc $(Flags) -g $(Libraries) $(src) -o $(Name)