CC        = cc
NAME      = minishell
CFLAGS    = -Wall -Werror -Wextra
Libraries = -lft -L ./libft -lreadline

src_dir = ./source

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

obj   = $(src:.c=.o)
deps  = $(src:.c=.d)
TOTAL = $(words $(obj))

all:
	@$(MAKE) --no-print-directory -C libft
	@$(MAKE) --no-print-directory $(NAME)

$(NAME): $(obj)
	@printf "  \033[0;34m[LD]\033[0m  Linking %s\n" "$@"
	@$(CC) $(CFLAGS) $^ $(Libraries) -o $@
	@echo "╔══════════════════════════════════╗"
	@echo "║         Build complete!          ║"
	@echo "║          $(NAME) ready           ║"
	@echo "╚══════════════════════════════════╝"

%.o: %.c
	@N=$$(find $(src_dir) -name "*.o" 2>/dev/null | wc -l | tr -d '[:space:]'); \
	 printf "  \033[0;32m[%3d%%]\033[0m  Compiling %s\n" \
	        "$$(( (N + 1) * 100 / $(TOTAL) ))" "$<"
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(CC) -MM $(CFLAGS) $< -MF $(@:.o=.d) -MT $@

-include $(deps)

clean:
	@rm -f $(obj) $(deps)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) --no-print-directory -C libft fclean

re: fclean all

debug:
	@$(CC) $(CFLAGS) -g $(src) $(Libraries) -o $(NAME)

sanitize:
	@$(CC) $(CFLAGS) -g3 -fsanitize=address $(Libraries) $(src) -o $(NAME)

.PHONY: all clean fclean re debug sanitize
