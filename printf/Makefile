CC     = gcc
CFLAGS = -Wall -Werror -Wextra
NAME   = libftprintf.a

ConvDir = ./ConversationFunctions/

src = ft_printf.c\
	  $(ConvDir)printchar.c\
	  $(ConvDir)printdecimal.c\
	  $(ConvDir)printhexadecimall.c\
	  $(ConvDir)printhexadecimalu.c\
	  $(ConvDir)printinteger.c\
	  $(ConvDir)printpointer.c\
	  $(ConvDir)printstring.c\
	  $(ConvDir)printunsigneddecimal.c\

obj   = $(src:%.c=%.o)
TOTAL = $(words $(obj))

all: $(NAME)

$(NAME): $(obj)
	@$(MAKE) --no-print-directory -C ./libft all
	@cp ./libft/libft.a $(NAME)
	@ar rcs $(NAME) $(obj)
	@echo "╔══════════════════════════════════╗"
	@echo "║         Build complete!          ║"
	@echo "║          $(NAME) ready           ║"
	@echo "╚══════════════════════════════════╝"

%.o: %.c
	@N=$$(ls $(dir $<)*.o 2>/dev/null | wc -l | tr -d '[:space:]'); \
	 printf "  \033[0;32m[%3d%%]\033[0m  Compiling %s\n" \
	        "$$(( (N + 1) * 100 / $(TOTAL) ))" "$<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(obj)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) --no-print-directory -C ./libft fclean

re: fclean all

executable:
	@$(CC) $(CFLAGS) main.c -L. libftprintf.a

.PHONY: all clean fclean re executable
