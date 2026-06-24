NAME     = libft.a
CC       = gcc
CFLAGS   = -Wall -Werror -Wextra
INCLUDES = -I $(inc)

src_dir = .
obj_dir = ./obj
inc     = .

SRCS  = $(shell find $(src_dir) -name "*.c")
OBJS  = $(addprefix $(obj_dir)/,$(notdir $(SRCS:.c=.o)))
TOTAL = $(words $(OBJS))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "╔══════════════════════════════════╗"
	@echo "║            COMPILED!             ║"
	@echo "║        $(NAME) is ready!         ║"
	@echo "╚══════════════════════════════════╝"

$(obj_dir)/%.o: $(src_dir)/*/%.c | $(obj_dir)
	@N=$$(ls $(obj_dir)/*.o 2>/dev/null | wc -l | tr -d '[:space:]'); \
	 printf "  \033[0;32m[%3d%%]\033[0m  Compiling %s\n" \
	        "$$(( (N + 1) * 100 / $(TOTAL) ))" "$<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(obj_dir)/%.o: $(src_dir)/%.c | $(obj_dir)
	@N=$$(ls $(obj_dir)/*.o 2>/dev/null | wc -l | tr -d '[:space:]'); \
	 printf "  \033[0;32m[%3d%%]\033[0m  Compiling %s\n" \
	        "$$(( (N + 1) * 100 / $(TOTAL) ))" "$<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(obj_dir):
	@mkdir -p $(obj_dir)

clean:
	@rm -rf $(obj_dir)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
