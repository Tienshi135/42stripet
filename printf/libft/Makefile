FLAGS = -Wall -Werror -Wextra
NAME  = libft.a

Base =	ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strlen.c\
		ft_strlcpy.c\
		ft_strlcat.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strnstr.c\
		ft_strncmp.c\
		ft_atoi.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_calloc.c\
		ft_strdup.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_split.c\
		ft_itoa.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\

Bonus = ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstsize.c\
		ft_lstlast.c\
		ft_lstadd_back.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstmap.c\

Extra = ft_isspace.c\
		ft_abs.c\

AllSrc = $(Base) $(Bonus) $(Extra)
AllObj = $(AllSrc:.c=.o)
TOTAL  = $(words $(AllObj))

all: $(NAME)

$(NAME): $(AllObj)
	@ar rcs $(NAME) $(AllObj)
	@echo "╔══════════════════════════════════╗"
	@echo "║            COMPILED!             ║"
	@echo "║        $(NAME) is ready!         ║"
	@echo "╚══════════════════════════════════╝"

%.o: %.c
	@N=$$(ls *.o 2>/dev/null | wc -l | tr -d '[:space:]'); \
	 printf "  \033[0;32m[%3d%%]\033[0m  Compiling %s\n" \
	        "$$(( (N + 1) * 100 / $(TOTAL) ))" "$<"
	@gcc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(AllObj)

fclean: clean
	@rm -f $(NAME)

re: fclean all

debug: fclean
	@gcc $(FLAGS) -g -c $(AllSrc)
	@$(MAKE) $(NAME)

.PHONY: all clean fclean re debug
