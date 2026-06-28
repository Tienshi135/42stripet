# name of the executable
NAME = mutantStack

# variables
src_dir = ./src
obj_dir = ./obj

# compilator and compilation flags
CC = c++
CFLAGS = -Wall -Werror -Wextra --std=c++98
INCLUDES = -I ./header

# source files (recursively find all .c files)
SRCS = $(shell find $(src_dir) -name "*.cpp") main.cpp
OBJS = $(addprefix $(obj_dir)/,$(notdir $(SRCS:.cpp=.o)))
TOTAL = $(words $(OBJS))

###RULES###
all: $(NAME)

$(NAME):$(OBJS)
	@printf "\033[2K\r  \033[0;34m[LD]\033[0m  Linking %s\n" "$@"
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $@

# Create object files from source files
$(obj_dir)/%.o: $(src_dir)/%.cpp | $(obj_dir)
	@N=$$(ls $(obj_dir)/*.o 2>/dev/null | wc -l | tr -d '[:space:]'); \
	 printf "  \033[0;32m[%3d%%]\033[0m  %-50s\r" \
	        "$$(( (N + 1) * 100 / $(TOTAL) ))" "$(notdir $<)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(obj_dir)/%.o: %.cpp | $(obj_dir)
	@N=$$(ls $(obj_dir)/*.o 2>/dev/null | wc -l | tr -d '[:space:]'); \
	 printf "  \033[0;32m[%3d%%]\033[0m  %-50s\r" \
	        "$$(( (N + 1) * 100 / $(TOTAL) ))" "$(notdir $<)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Create object directory
$(obj_dir):
	@mkdir -p $(obj_dir)

# Clean object files
clean:
	@rm -rf $(obj_dir)

# Clean everything
fclean: clean
	@rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
