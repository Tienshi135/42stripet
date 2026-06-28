NAME    = libft.a
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
SRC_DIR = srcs
OBJ_DIR = srcs/objs

SRCS  = $(shell find $(SRC_DIR) -name "*.c")
OBJS  = $(addprefix $(OBJ_DIR)/,$(notdir $(SRCS:.c=.o)))
TOTAL = $(words $(OBJS))
VPATH = $(sort $(dir $(SRCS)))

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\033[2K\r  \033[0;34m[AR]\033[0m  Archiving %s\n" "$@"
	@ar rcs $(NAME) $(OBJS)
	@echo "╔══════════════════════════════════╗"
	@echo "║            COMPILED!             ║"
	@echo "║        $(NAME) is ready!         ║"
	@echo "╚══════════════════════════════════╝"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@N=$$(ls $(OBJ_DIR)/*.o 2>/dev/null | wc -l | tr -d '[:space:]'); \
	 printf "  \033[0;32m[%3d%%]\033[0m  %-50s\r" \
	        "$$(( (N + 1) * 100 / $(TOTAL) ))" "$(notdir $<)"
	@$(CC) $(CFLAGS) -Iinclude -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

debug: CFLAGS += -g
debug: re

.PHONY: all clean fclean re debug
