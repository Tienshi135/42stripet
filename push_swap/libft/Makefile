NAME    = libft.a
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
SRC_DIR = srcs
OBJ_DIR = srcs/objs
GREEN   = \033[0;32m
RED		= \033[0;31m
RESET   = \033[0m

SRCS  = $(shell find $(SRC_DIR) -name "*.c")
OBJS  = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
TOTAL = $(words $(OBJS))
VPATH = $(sort $(dir $(SRCS)))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "╔══════════════════════════════════╗"
	@echo "║            $(GREEN)COMPILED!$(RESET)             ║"
	@echo "║        $(NAME) is ready!         ║"
	@echo "╚══════════════════════════════════╝"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@N=$$(ls $(OBJ_DIR)/*.o 2>/dev/null | wc -l | tr -d '[:space:]'); \
	 printf "  $(GREEN)[%3d%%]$(RESET)  %-50s\r" \
	        "$$(( (N + 1) * 100 / $(TOTAL) ))" "$(notdir $<)"
	@$(CC) $(CFLAGS) -Iinclude -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Cleaned $(OBJ_DIR)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Removed $(NAME)$(RESET)"

re: fclean all

debug: CFLAGS += -g
debug: re

.PHONY: all clean fclean re debug
