RED=\033[0;31m
GREEN=\033[0;32m
BLUE=\033[0;34m
NC=\033[0m

NAME = violence
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -I $(INCDIR)
INCDIR = ./header

src =	./main.cpp \
		./src/HumanA.cpp \
		./src/HumanB.cpp \
		./src/Weapon.cpp \

obj = $(src:.cpp=.o)

all: $(NAME)
	@echo "${GREEN}$(NAME)${NC} is up to date"

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(obj)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "${GREEN}$(NAME)${NC} compiled successfully"

debug: CFLAGS += -g
debug: re
	@echo "${BLUE}Debug mode${NC}"

sanitize: CFLAGS += -fsanitize=address
sanitize: re
	@echo "${BLUE}Sanitize mode${NC}"

clean:
	@cleaned_obj=false; \
	for file in $(obj); do \
		if [ -f "$$file" ]; then rm -f $$file; cleaned_obj=true; fi; \
	done; \
	cleaned_dsym=false; \
	if [ -d "$(NAME).dSYM" ]; then rm -rf $(NAME).dSYM; cleaned_dsym=true; fi; \
	if $$cleaned_obj && $$cleaned_dsym; then \
		echo "${BLUE}Cleaned$(NC) : ${RED}$(obj) $(NAME).dSYM${NC}"; \
	elif $$cleaned_obj; then \
		echo "${BLUE}Cleaned$(NC) : ${RED}$(obj)${NC}"; \
	elif $$cleaned_dsym; then \
		echo "${BLUE}Cleaned$(NC) : ${RED}$(NAME).dSYM${NC}"; \
	else \
		echo "${RED}Nothing to clean${NC}"; \
	fi

fclean: clean
	@cleaned_name=false; \
	if [ -f "$(NAME)" ]; then rm -f $(NAME); cleaned_name=true; fi; \
	if $$cleaned_name; then \
		echo "${BLUE}Cleaned$(NC) : ${RED}$(NAME)${NC}"; \
	else \
		echo "${RED}$(NAME) does not exist${NC}"; \
	fi

re: fclean all