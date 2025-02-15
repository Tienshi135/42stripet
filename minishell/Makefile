CC = cc
NAME = minishell
CFLAGS = -Wall -Werror -Wextra $(Inc_readl)
Libraries = -lft -L ./libft $(Lib_readl)

src_dir = ./source

Lib_readl =  -L/Users/mgodel/.brew/opt/readline/lib -lreadline
Inc_readl = -I/Users/mgodel/.brew/opt/readline/include

src = 	$(src_dir)/minishell.c\
		$(src_dir)/errors.c\
		$(src_dir)/errors_2.c\
		$(src_dir)/quote_removal.c\
		$(src_dir)/utils/utils.c\
		$(src_dir)/utils/utils_2.c\
		$(src_dir)/utils/get_command_args.c\
		$(src_dir)/utils/free_utils.c\
		$(src_dir)/utils/free_utils_2.c\
		$(src_dir)/utils/tokenize/tokenize.c\
		$(src_dir)/utils/tokenize/tokenize_utils.c\
		$(src_dir)/utils/environ/environ.c\
		$(src_dir)/utils/environ/environ_utils.c\
		$(src_dir)/utils/environ/environ_utils_2.c\
		$(src_dir)/history.c\
		$(src_dir)/handle_incomplete_cmd.c\
		$(src_dir)/expansions.c\
		$(src_dir)/execute/execute.c\
		$(src_dir)/execute/execute_utils.c\
		$(src_dir)/execute/redirections.c\
		$(src_dir)/execute/redirections_utils.c\
		$(src_dir)/execute/redirections_access.c\
		$(src_dir)/execute/execute_script.c\
		$(src_dir)/signal.c\
		$(src_dir)/signal_2.c\
		$(src_dir)/builtins/builtins.c\
		$(src_dir)/builtins/cd.c\
		$(src_dir)/builtins/echo.c\
		$(src_dir)/builtins/env.c\
		$(src_dir)/builtins/exit.c\
		$(src_dir)/builtins/export_display.c\
		$(src_dir)/builtins/export.c\
		$(src_dir)/builtins/pwd.c\
		$(src_dir)/builtins/unset.c\
		$(src_dir)/execute/pipes.c\
		$(src_dir)/execute/pipe_utils.c\
		$(src_dir)/execute/wait_process.c\
		$(src_dir)/utils/word_splitting/word_splitting_start.c\
		$(src_dir)/utils/word_splitting/word_splitting_1.c\
		$(src_dir)/utils/word_splitting/word_splitting_2.c\
		$(src_dir)/segment.c\
		$(src_dir)/segment_utils.c\
		$(src_dir)/heredoc.c\
		$(src_dir)/free_pipeline.c\
		$(src_dir)/parsing/pars_token.c\
		$(src_dir)/debug.c

obj = $(src:.c=.o)
deps = $(src:.c=.d)

all: 
	$(MAKE) -C libft
	$(MAKE) $(NAME)

$(NAME):$(obj)
	$(CC) $(CFLAGS) $^ $(Libraries) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@$(CC) -MM $(CFLAGS) $< -MF $(@:.o=.d) -MT $@

-include $(deps)

clean:
	rm -f $(obj)
	rm -f $(deps)

fclean: clean
	rm -f $(NAME)

re: fclean all
	make clean

debug:
	$(CC) $(CFLAGS) -g $(src) $(Libraries) -o $(NAME)

sanitize:
	$(CC) $(CFLAGS) -g3 -fsanitize=address $(CFLAGS) $(Libraries) $(src) -o $(NAME)
