Name = push_swap
CFLAGS = -Wall -Werror -Wextra
Libraries = -lft -L ./libft

src_dir = ./source
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

bonus_src = $(bonus_dir)/errors_bonus.c\
			$(bonus_dir)/pipex_bonus.c\
			$(bonus_dir)/utils_bonus.c\

obj = $(src:.c=.o)
bonus_obj = $(bonus_src:.c=.o)

all: $(Name)

$(Name):$(obj)
	gcc $(Libraries) $^ -o $@

bonus:$(bonus_obj)
	gcc $(Libraries) $^ -o $(Name)

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
	-./$(Name) "270284 394749 -223162 283973 -490820 -434218 4562 348454 409752 -286498 373741 -18099 -106742 111432 212119 377419 49857 406729 -105914 173040" | wc -l
	ARG="270284 394749 -223162 283973 -490820 -434218 4562 348454 409752 -286498 373741 -18099 -106742 111432 212119 377419 49857 406729 -105914 173040"; ./push_swap $$ARG | ./checker_Mac $$ARG
	@printf '\n'
	-./$(Name) "240801 -87713 351766 319398 -273624 -373765 -100864 -455759 -253289 -480648 -11506 -368913 159660 332997 -11770 329079 -467708 142050 -309518 -31721 -16534 460591 -200140 -114877 62042 -176836 368833 194427 127634 106147 -343196 400948 374163 -480965 289949 460101 -273119 400327 183859 5630 454263 34969 -26961 61255 394082 -74357 234981 305915 53630 -429778" | wc -l
	ARG="240801 -87713 351766 319398 -273624 -373765 -100864 -455759 -253289 -480648 -11506 -368913 159660 332997 -11770 329079 -467708 142050 -309518 -31721 -16534 460591 -200140 -114877 62042 -176836 368833 194427 127634 106147 -343196 400948 374163 -480965 289949 460101 -273119 400327 183859 5630 454263 34969 -26961 61255 394082 -74357 234981 305915 53630 -429778"; ./push_swap $$ARG | ./checker_Mac $$ARG
	@printf '\n'
	-./$(Name) "209432 -342825 -452289 17349 -87098" | wc -l
	ARG="209432 -342825 -452289 17349 -87098"; ./push_swap $$ARG | ./checker_Mac $$ARG

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
	-Leaks --atExit --quiet -- ./$(Name) "270284 394749 -223162 283973 -490820 -434218 4562 348454 409752 -286498 373741 -18099 -106742 111432 212119 377419 49857 406729 -105914 173040"
	ARG="270284 394749 -223162 283973 -490820 -434218 4562 348454 409752 -286498 373741 -18099 -106742 111432 212119 377419 49857 406729 -105914 173040"; ./push_swap $$ARG | ./checker_Mac $$ARG
	@printf '\n'
	-Leaks --atExit --quiet -- ./$(Name) "240801 -87713 351766 319398 -273624 -373765 -100864 -455759 -253289 -480648 -11506 -368913 159660 332997 -11770 329079 -467708 142050 -309518 -31721 -16534 460591 -200140 -114877 62042 -176836 368833 194427 127634 106147 -343196 400948 374163 -480965 289949 460101 -273119 400327 183859 5630 454263 34969 -26961 61255 394082 -74357 234981 305915 53630 -429778"
	ARG="240801 -87713 351766 319398 -273624 -373765 -100864 -455759 -253289 -480648 -11506 -368913 159660 332997 -11770 329079 -467708 142050 -309518 -31721 -16534 460591 -200140 -114877 62042 -176836 368833 194427 127634 106147 -343196 400948 374163 -480965 289949 460101 -273119 400327 183859 5630 454263 34969 -26961 61255 394082 -74357 234981 305915 53630 -429778"; ./push_swap $$ARG | ./checker_Mac $$ARG
	@printf '\n'
	-Leaks --atExit --quiet -- ./$(Name) "209432 -342825 -452289 17349 -87098"
	ARG="209432 -342825 -452289 17349 -87098"; ./push_swap $$ARG | ./checker_Mac $$ARG

	@printf 'end of leaks tests\n'