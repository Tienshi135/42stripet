NAME      = philo
BONUS_NAME = philo_bonus
CC        = cc
CFLAGS    = -Wall -Werror -Wextra -pthread

src_dir   = ./source
bonus_dir = ./source/bonus

src = 	$(src_dir)/philo.c\
		$(src_dir)/utils.c\
		$(src_dir)/actions.c\

bonus_src =

obj       = $(src:.c=.o)
bonus_obj = $(bonus_src:.c=.o)
TOTAL     = $(words $(obj))

all: $(NAME)

$(NAME): $(obj)
	@printf "  \033[0;34m[LD]\033[0m  Linking %s\n" "$@"
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "╔══════════════════════════════════╗"
	@echo "║         Build complete!          ║"
	@echo "║           $(NAME) ready          ║"
	@echo "╚══════════════════════════════════╝"

bonus: $(bonus_obj)
	@$(CC) $(CFLAGS) $^ -o $(BONUS_NAME)

%.o: %.c
	@N=$$(ls $(dir $<)*.o 2>/dev/null | wc -l | tr -d '[:space:]'); \
	 printf "  \033[0;32m[%3d%%]\033[0m  Compiling %s\n" \
	        "$$(( (N + 1) * 100 / $(TOTAL) ))" "$<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(src_dir)/*.o
	@rm -f $(bonus_dir)/*.o

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all

bre: fclean bonus

debug:
	@gcc -g $(CFLAGS) $(src) -o $(NAME)

sanitize:
	@gcc -g -fsanitize=address $(CFLAGS) $(src) -o $(NAME)

.PHONY: all clean fclean re bonus bre debug sanitize
