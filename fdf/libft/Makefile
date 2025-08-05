###VARIABLES###
NAME = libft.a

# compilator and compilation flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra
INCLUDES = -I $(inc)

# variables
src_dir = .
obj_dir = ./obj
inc = .

# source files
SRCS = $(shell find $(src_dir) -name "*.c")
OBJS = $(addprefix $(obj_dir)/,$(notdir $(SRCS:.c=.o)))

###RULES###
all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs	$(NAME) $(OBJS) $@
	@echo "╔══════════════════════════════════╗"
	@echo "║            COMPILED!             ║"
	@echo "║        $(NAME) is ready!         ║"
	@echo "╚══════════════════════════════════╝"

$(obj_dir)/%.o: $(src_dir)/*/%.c | $(obj_dir)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(obj_dir)/%.o: $(src_dir)/%.c | $(obj_dir)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(obj_dir):
	mkdir -p $(obj_dir)

clean:
	rm -rf $(obj_dir)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
