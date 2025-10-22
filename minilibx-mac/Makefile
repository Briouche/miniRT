


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

$(NAME): $(OBJ) $(C_OBJ)
	swiftc $(OPTI) $(INC) -o $(NAME) -emit-library $(OBJ) $(C_OBJ) -lz


# Swift module dependencies
mlx_window.swiftmodule: mlx_image.swiftmodule
mlx_init.swiftmodule: mlx_image.swiftmodule mlx_window.swiftmodule
interface.o: mlx_image.swiftmodule mlx_window.swiftmodule mlx_init.swiftmodule


%.o %.swiftmodule: %.swift
	swiftc $(OPTI) $(INC) -I. -parse-as-library -emit-module -emit-module-path $(patsubst %.swift,%.swiftmodule,$<) -c $< -o $(patsubst %.swift,%.o,$<)




clean:
	rm -f $(NAME) $(OBJ) $(MODULE_OBJ) $(C_OBJ) *.swiftdoc *~

fclean: clean
	rm -f *.json *.swiftmodule *.swiftsourceinfo
