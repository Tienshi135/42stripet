NAME       = philo
BONUS_NAME = philo_bonus
CC         = cc
CFLAGS     = -Wall -Werror -Wextra -pthread

src_dir   = ./source
bonus_dir = ./source/bonus
obj_dir   = ./obj

src = $(src_dir)/philo.c\
      $(src_dir)/utils.c\
      $(src_dir)/actions.c\

bonus_src =

obj       = $(addprefix $(obj_dir)/,$(notdir $(src:.c=.o)))
bonus_obj = $(addprefix $(obj_dir)/,$(notdir $(bonus_src:.c=.o)))
TOTAL     = $(words $(obj))

.PHONY: all clean fclean re bonus bre debug sanitize

all: $(NAME)

$(NAME): $(obj)
	@printf "\033[2K\r  \033[0;34m[LD]\033[0m  Linking %s\n" "$@"
	@$(CC) $(CFLAGS) $(obj) -o $@
	@echo "╔══════════════════════════════════╗"
	@echo "║         Build complete!          ║"
	@echo "║           $(NAME) ready          ║"
	@echo "╚══════════════════════════════════╝"

bonus: $(bonus_obj)
	@$(CC) $(CFLAGS) $(bonus_obj) -o $(BONUS_NAME)

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

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all

bre: fclean bonus

debug:
	@gcc -g $(CFLAGS) $(src) -o $(NAME)

sanitize:
	@gcc -g -fsanitize=address $(CFLAGS) $(src) -o $(NAME)
