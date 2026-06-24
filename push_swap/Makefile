NAME      = push_swap
CC        = gcc
CFLAGS    = -Wall -Werror -Wextra
Libraries = -lft -L ./libft

src_dir   = ./source
bonus_dir = ./source/bonus

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

obj       = $(src:.c=.o)
bonus_obj = $(bonus_src:.c=.o)
TOTAL     = $(words $(obj))

.PHONY: all libft bonus clean fclean re bre debug bdebug sanitize bsanitize

all: libft $(NAME)

libft:
	@$(MAKE) --no-print-directory -C ./libft

$(NAME): $(obj)
	@printf "  \033[0;34m[LD]\033[0m  Linking %s\n" "$@"
	@$(CC) $(CFLAGS) $^ $(Libraries) -o $@
	@echo "╔══════════════════════════════════╗"
	@echo "║         Build complete!          ║"
	@echo "║          $(NAME) ready           ║"
	@echo "╚══════════════════════════════════╝"

bonus: libft $(bonus_obj)
	@$(CC) $(CFLAGS) $(bonus_obj) $(Libraries) -o Checker_Mac_Stripet

%.o: %.c
	@N=$$(ls $(dir $<)*.o 2>/dev/null | wc -l | tr -d '[:space:]'); \
	 printf "  \033[0;32m[%3d%%]\033[0m  Compiling %s\n" \
	        "$$(( (N + 1) * 100 / $(TOTAL) ))" "$<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(src_dir)/*.o $(bonus_dir)/*.o

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
