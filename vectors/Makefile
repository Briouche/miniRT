NAME= vectors.a

COL_DIR= colors
COL_LIB= colors.a

CC= cc
CFLAGS= -Wall -Werror -Wextra

UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
	LDFLAGS = -lm
else
	LDFLAGS =
endif

SRCS=	is_equal.c is_point.c is_vector.c \
		op_cross.c op_dot.c op_magnitude.c op_minus.c op_multi.c op_normalise.c op_opposite.c op_plus.c \
		point.c vector.c
OBJ_DIR= objs
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

DEPS= vectors.h

RM= rm -f
AR = ar crs

all: $(NAME)

$(NAME): $(OBJS) $(COL_LIB)
	@mkdir -p temp_objs
	cd temp_objs && ar x ../$(COL_DIR)/$(COL_LIB)
	$(AR) $@ $(OBJS) temp_objs/*.o
	@$(RM) -r temp_objs

$(OBJ_DIR)/%.o: %.c $(DEPS)
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@ $(CFLAGS)

$(COL_LIB):
	cd $(COL_DIR) ; make > /dev/null

clean:
	cd $(COL_DIR) ; make clean > /dev/null
	$(RM) -r $(OBJ_DIR)
	

fclean: clean
	cd $(COL_DIR) ; make fclean > /dev/null
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re