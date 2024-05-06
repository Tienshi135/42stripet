Name = push_swap
CFLAGS = -Wall -Werror -Wextra
Libraries = -lft -L ./libft

src_dir = ./source
bonus_dir = ./source
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
			$(bonus_dir)/push_bonus.c\
			$(bonus_dir)/reverse_bonus.c\
			$(bonus_dir)/rotate_bonus.c\
			$(bonus_dir)/swap_bonus.c\
			$(src_dir)/utils.c\
			$(src_dir)/list_utils.c\
			$(src_dir)/math.c\

obj = $(src:.c=.o)
bonus_obj = $(bonus_src:.c=.o)

all: $(Name)

$(Name):$(obj)
	gcc $(Libraries) $^ -o $@

bonus:$(bonus_obj)
	gcc $(Libraries) $^ -o Checker_Mac_Stripet

clean:
	rm -f $(src_dir)/*.o
	rm -f $(bonus_dir)/*.o

fclean: clean
	rm -f $(Name)

re: fclean all

bre: fclean bonus

debug:
	gcc -g $(CFLAGS) $(Libraries) $(src) -o $(Name)

bdebug:
	gcc -g $(CFLAGS) $(Libraries) $(bonus_src) -o $(Name)

sanitize:
	gcc -g -fsanitize=address $(CFLAGS) $(Libraries) $(src) -o $(Name)

bsanitize:
	gcc -g -fsanitize=address $(CFLAGS) $(Libraries) $(bonus_src) -o $(Name)

random_test:
	@NUMBERS=$$(jot -r 1000 -300 300 | sort -n | uniq | awk 'BEGIN {srand()} {print rand(), $$0}' | sort -n | cut -d ' ' -f2- | head -4); \
	echo $$NUMBERS; \
	./push_swap $$NUMBERS | ./checker_Mac $$NUMBERS

test:
	@printf 'begining of sanitize tests\n'
	@make sanitize
	@printf '\n'
	-./$(Name)
	@printf '\n'
	-./$(Name) wrong
	@printf '\n'
	-./$(Name) 1
	@printf '\n'
	-./$(Name) 1 wrong 2 3
	@printf '\n'
	-./$(Name) 1 2 5 2 1
	@printf '\n'
	-./$(Name) "1" "wrong" "2" "3"
	@printf '\n'
	-./$(Name) "1" "2" "5" "2" "1"

	@printf '\n'
	-./$(Name) "0 1 2 3 4 5 6 7 8 9 10" | wc -l
	ARG="0 1 2 3 4 5 6 7 8 9 10"; ./push_swap $$ARG | ./checker_Mac $$ARG
	@printf '\n'
	-./$(Name) "10 9 8 7 6 5 4 3 2 1 0" | wc -l
	ARG="10 9 8 7 6 5 4 3 2 1 0"; ./push_swap $$ARG | ./checker_Mac $$ARG
	@printf '\n'
	-./$(Name) "4 67 3 87 23" | wc -l
	ARG="4 67 3 87 23"; ./push_swap $$ARG | ./checker_Mac $$ARG
	@printf '\n'

	@printf 'End of sanitize tests\n\n\n\n\n\n\n\n\n'

	@printf 'begining of leaks tests\n'
	@make re
	@printf '\n'
	-Leaks --atExit --quiet -- ./$(Name)
	@printf '\n'
	-Leaks --atExit --quiet -- ./$(Name) wrong
	@printf '\n'
	-Leaks --atExit --quiet -- ./$(Name) 1
	@printf '\n'
	-Leaks --atExit --quiet -- ./$(Name) 1 wrong 2 3
	@printf '\n'
	-Leaks --atExit --quiet -- ./$(Name) 1 2 5 2 1
	@printf '\n'
	-Leaks --atExit --quiet -- ./$(Name) "1" "wrong" "2" "3"
	@printf '\n'
	-Leaks --atExit --quiet -- ./$(Name) "1" "2" "5" "2" "1"

	@printf '\n'
	-Leaks --atExit --quiet -- ./$(Name) "0 1 2 3 4 5 6 7 8 9 10"
	ARG="0 1 2 3 4 5 6 7 8 9 10"; ./push_swap $$ARG | ./checker_Mac $$ARG
	@printf '\n'
	-Leaks --atExit --quiet -- ./$(Name) "10 9 8 7 6 5 4 3 2 1 0"
	ARG="10 9 8 7 6 5 4 3 2 1 0"; ./push_swap $$ARG | ./checker_Mac $$ARG
	@printf '\n'
	-Leaks --atExit --quiet -- ./$(Name) "4 67 3 87 23"
	ARG="4 67 3 87 23"; ./push_swap $$ARG | ./checker_Mac $$ARG
	@printf '\n'

	@printf 'end of leaks tests\n'
