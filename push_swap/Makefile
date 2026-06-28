NAME      = push_swap
CC        = gcc
CFLAGS    = -Wall -Werror -Wextra
Libraries = -lft -L ./libft

src_dir   = ./source
bonus_dir = ./source/bonus
obj_dir   = ./obj

src = $(src_dir)/push_swap.c\
      $(src_dir)/reverse.c\
      $(src_dir)/rotate.c\
      $(src_dir)/swap.c\
      $(src_dir)/push.c\
      $(src_dir)/utils.c\
      $(src_dir)/errors.c\
      $(src_dir)/math.c\
      $(src_dir)/algorythm.c\
      $(src_dir)/sort_utils.c\
      $(src_dir)/list_utils.c\
      $(src_dir)/list_utils2.c\

bonus_src = $(bonus_dir)/push_swap_checker_bonus.c\
            $(bonus_dir)/error_bonus.c\
            $(src_dir)/utils.c\
            $(src_dir)/list_utils.c\
            $(src_dir)/list_utils2.c\
            $(src_dir)/reverse.c\
            $(src_dir)/rotate.c\
            $(src_dir)/swap.c\
            $(src_dir)/push.c\
            $(src_dir)/math.c\

obj       = $(addprefix $(obj_dir)/,$(notdir $(src:.c=.o)))
bonus_obj = $(addprefix $(obj_dir)/,$(notdir $(bonus_src:.c=.o)))
TOTAL     = $(words $(obj))

.PHONY: all libft bonus clean fclean re bre debug bdebug sanitize bsanitize random_test

all: libft $(NAME)

libft:
	@$(MAKE) --no-print-directory -C ./libft

$(NAME): $(obj)
	@printf "\033[2K\r  \033[0;34m[LD]\033[0m  Linking %s\n" "$@"
	@$(CC) $(CFLAGS) $(obj) $(Libraries) -o $@
	@echo "╔══════════════════════════════════╗"
	@echo "║         Build complete!          ║"
	@echo "║          $(NAME) ready           ║"
	@echo "╚══════════════════════════════════╝"

bonus: libft $(bonus_obj)
	@$(CC) $(CFLAGS) $(bonus_obj) $(Libraries) -o Checker_Mac_Stripet

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
	@rm -f $(NAME) Checker_Mac_Stripet
	@$(MAKE) --no-print-directory -C ./libft fclean

re: fclean all

bre: fclean bonus

debug:
	@$(CC) -g $(CFLAGS) $(src) $(Libraries) -o $(NAME)

bdebug:
	@$(CC) -g $(CFLAGS) $(bonus_src) $(Libraries) -o $(NAME)

sanitize:
	@$(CC) -g -fsanitize=address $(CFLAGS) $(src) $(Libraries) -o $(NAME)

bsanitize:
	@$(CC) -g -fsanitize=address $(CFLAGS) $(bonus_src) $(Libraries) -o $(NAME)

random_test:
	@NUMBERS=$$(jot -r 1000 -300 300 | sort -n | uniq | awk 'BEGIN {srand()} {print rand(), $$0}' | sort -n | cut -d ' ' -f2- | head -5); \
	echo $$NUMBERS; \
	./push_swap $$NUMBERS | ./Checker_Mac_Stripet $$NUMBERS
