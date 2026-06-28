Name      = pipex
CC        = gcc
CFLAGS    = -Wall -Werror -Wextra
Libraries = -lft -L ./libft

src_dir   = ./source
bonus_dir = ./source/bonus
obj_dir   = ./obj

src = $(src_dir)/errors.c\
      $(src_dir)/pipex.c\
      $(src_dir)/utils.c\

bonus_src = $(bonus_dir)/errors_bonus.c\
            $(bonus_dir)/pipex_bonus.c\
            $(bonus_dir)/utils_bonus.c\

obj       = $(addprefix $(obj_dir)/,$(notdir $(src:.c=.o)))
bonus_obj = $(addprefix $(obj_dir)/,$(notdir $(bonus_src:.c=.o)))
TOTAL     = $(words $(obj))

.PHONY: all libft bonus clean fclean re bre debug bdebug sanitize bsanitize

all: libft $(Name)

libft:
	@$(MAKE) --no-print-directory -C ./libft

$(Name): $(obj)
	@printf "\033[2K\r  \033[0;34m[LD]\033[0m  Linking %s\n" "$@"
	@$(CC) $(CFLAGS) $(obj) $(Libraries) -o $@
	@echo "╔══════════════════════════════════╗"
	@echo "║         Build complete!          ║"
	@echo "║           $(Name) ready          ║"
	@echo "╚══════════════════════════════════╝"

bonus: libft $(bonus_obj)
	@$(CC) $(CFLAGS) $(bonus_obj) $(Libraries) -o $(Name)

$(obj_dir)/%.o: $(src_dir)/%.c | $(obj_dir)
	@N=$$(ls $(obj_dir)/*.o 2>/dev/null | wc -l | tr -d '[:space:]'); \
	 printf "  \033[0;32m[%3d%%]\033[0m  %-50s\r" \
	        "$$(( (N + 1) * 100 / $(TOTAL) ))" "$(notdir $<)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(obj_dir)/%.o: $(bonus_dir)/%.c | $(obj_dir)
	@N=$$(ls $(obj_dir)/*.o 2>/dev/null | wc -l | tr -d '[:space:]'); \
	 printf "  \033[0;32m[%3d%%]\033[0m  %-50s\r" \
	        "$$(( (N + 1) * 100 / $(TOTAL) ))" "$(notdir $<)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(obj_dir):
	@mkdir -p $(obj_dir)

clean:
	@rm -rf $(obj_dir)
	@$(MAKE) --no-print-directory -C ./libft clean

fclean: clean
	@rm -f $(Name)
	@$(MAKE) --no-print-directory -C ./libft fclean

re: fclean all

bre: fclean bonus

debug:
	@$(CC) -g $(CFLAGS) $(src) $(Libraries) -o $(Name)

bdebug:
	@$(CC) -g $(CFLAGS) $(bonus_src) $(Libraries) -o $(Name)

sanitize:
	@$(CC) -g -fsanitize=address $(CFLAGS) $(src) $(Libraries) -o $(Name)

bsanitize:
	@$(CC) -g -fsanitize=address $(CFLAGS) $(bonus_src) $(Libraries) -o $(Name)
