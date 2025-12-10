NAME= vectors.a

CC= cc
CFLAGS= -Wall -Werror -Wextra

LDFLAGS = -lm

SRCS=	is_equal.c is_point.c is_vector.c is_equal_matrix.c \
		op_cross.c op_dot.c op_magnitude.c op_minus.c op_multi_scalar.c \
		op_normalise.c op_opposite.c op_plus.c op_perpendicular_comp.c \
		add_colors.c multi_colors.c multi_scalar_colors.c sub_colors.c \
		point.c vector.c vec_color.c matrix.c \
		matrices_add.c matrices_multiply.c \
		matrix_cofactor.c matrix_det_d2.c matrix_determinant.c matrix_minor.c \
		matrix_inverse.c matrix_reduce.c matrix_transpose.c matrix_vector_multi.c \
		trsfrm_rotate.c trsfrm_scale.c trsfrm_shear.c trsfrm_translate.c \
		prints.c
OBJ_DIR= objs
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

DEPS= vectors.h

RM= rm -f
AR = ar crs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $(OBJS)

$(OBJ_DIR)/%.o: %.c $(DEPS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
