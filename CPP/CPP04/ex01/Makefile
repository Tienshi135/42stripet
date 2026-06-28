RED=\033[0;31m
GREEN=\033[0;32m
BLUE=\033[0;34m
NC=\033[0m

NAME    = WorldOnFire
CC      = c++
CFLAGS  = -Wall -Werror -Wextra -std=c++98 -I $(INCDIR)
INCDIR  = ./header

src =	./main.cpp \
		./Animal.cpp \
		./Dog.cpp \
		./Cat.cpp \
		./Brain.cpp\

obj_dir = ./obj
OBJS    = $(addprefix $(obj_dir)/,$(notdir $(src:.cpp=.o)))
TOTAL   = $(words $(OBJS))

all: $(NAME)
	@echo "${GREEN}$(NAME)${NC} is up to date"

$(obj_dir)/%.o: %.cpp | $(obj_dir)
	@N=$$(ls $(obj_dir)/*.o 2>/dev/null | wc -l | tr -d '[:space:]'); \
	 printf "  \\033[0;32m[%3d%%]\\033[0m  %-50s\\r" \
	        "$$(( (N + 1) * 100 / $(TOTAL) ))" "$(notdir $<)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@printf "\\033[2K\\r  \\033[0;34m[LD]\\033[0m  Linking %s\\n" "$@"
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "${GREEN}$(NAME)${NC} compiled successfully"

debug: CFLAGS += -g
debug: re
	@echo "${BLUE}Debug mode${NC}"

sanitize: CFLAGS += -fsanitize=address
sanitize: re
	@echo "${BLUE}Sanitize mode${NC}"

$(obj_dir):
	@mkdir -p $(obj_dir)

clean:
	@rm -rf $(obj_dir)

fclean: clean
	@rm -f $(NAME)

re: fclean all
