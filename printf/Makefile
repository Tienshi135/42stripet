CC      = gcc
CFLAGS  = -Wall -Werror -Wextra
NAME    = libftprintf.a

ConvDir = ./ConversationFunctions/
obj_dir = ./obj

src = ft_printf.c\
      $(ConvDir)printchar.c\
      $(ConvDir)printdecimal.c\
      $(ConvDir)printhexadecimall.c\
      $(ConvDir)printhexadecimalu.c\
      $(ConvDir)printinteger.c\
      $(ConvDir)printpointer.c\
      $(ConvDir)printstring.c\
      $(ConvDir)printunsigneddecimal.c\

obj   = $(addprefix $(obj_dir)/,$(notdir $(src:.c=.o)))
TOTAL = $(words $(obj))

all: $(NAME)

$(NAME): $(obj)
	@$(MAKE) --no-print-directory -C ./libft all
	@printf "\033[2K\r  \033[0;34m[AR]\033[0m  Archiving %s\n" "$@"
	@cp ./libft/libft.a $(NAME)
	@ar rcs $(NAME) $(obj)
	@echo "╔══════════════════════════════════╗"
	@echo "║         Build complete!          ║"
	@echo "║          $(NAME) ready           ║"
	@echo "╚══════════════════════════════════╝"

$(obj_dir)/%.o: %.c | $(obj_dir)
	@N=$$(ls $(obj_dir)/*.o 2>/dev/null | wc -l | tr -d '[:space:]'); \
	 printf "  \033[0;32m[%3d%%]\033[0m  %-50s\r" \
	        "$$(( (N + 1) * 100 / $(TOTAL) ))" "$(notdir $<)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(obj_dir)/%.o: $(ConvDir)%.c | $(obj_dir)
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
	@rm -f $(NAME)
	@$(MAKE) --no-print-directory -C ./libft fclean

re: fclean all

executable:
	@$(CC) $(CFLAGS) main.c -L. libftprintf.a

.PHONY: all clean fclean re executable
