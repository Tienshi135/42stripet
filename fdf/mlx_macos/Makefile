MODULE_SRC= mlx_image.swift mlx_window.swift mlx_init.swift
SRC= interface.swift $(MODULE_SRC)
OBJ=$(SRC:.swift=.o)

C_SRC= mlx_xpm.c mlx_png.c mlx_string_put.c
C_OBJ=$(C_SRC:.c=.o)
CFLAGS=-O3

NAME=libmlx.dylib

INC=-I.
#OPTI=-Ounchecked

all: $(NAME)

$(NAME): .swift_built $(C_OBJ)
	swiftc $(OPTI) $(INC) -o $(NAME) -emit-library $(OBJ) $(C_OBJ) -lz \
		-Xlinker -install_name -Xlinker @rpath/$(NAME)

# Swift 6 two-phase build:
# Phase 1 - emit .swiftmodule files in dependency order so each module's
#            imports are resolvable by the next one.
# Phase 2 - compile each .swift to .o using the modules from phase 1.
# Separate swiftc processes avoid the Swift 6 multi-job-executor crash that
# occurs when -c and -emit-module target the same .swiftmodule in one invocation.
.swift_built: $(SRC)
	swiftc $(OPTI) $(INC) -parse-as-library -emit-module -module-name mlx_image mlx_image.swift
	swiftc $(OPTI) $(INC) -parse-as-library -emit-module -module-name mlx_window mlx_window.swift
	swiftc $(OPTI) $(INC) -parse-as-library -emit-module -module-name mlx_init mlx_init.swift
	swiftc $(OPTI) $(INC) -parse-as-library -c mlx_image.swift -o mlx_image.o
	swiftc $(OPTI) $(INC) -parse-as-library -c mlx_window.swift -o mlx_window.o
	swiftc $(OPTI) $(INC) -parse-as-library -c mlx_init.swift -o mlx_init.o
	swiftc $(OPTI) $(INC) -parse-as-library -c interface.swift -o interface.o
	@touch $@

%.o: %.c
	gcc $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(NAME) $(OBJ) $(C_OBJ) .swift_built *.swiftmodule *.swiftdoc *~
