NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

DEPS = libft.h
SRCS =	ft_ato_utils.c ft_atod.c ft_atoi.c ft_atol.c \
		ft_isalpha.c ft_isdigit.c ft_islower.c ft_isdigit.c ft_isupper.c \
		ft_calloc.c ft_free_array.c ft_memcpy.c ft_memset.c \
		ft_putchar_fd.c ft_putstr_fd.c \
		ft_split.c ft_strchr.c ft_strcmp.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strndup.c \
		get_next_line.c
OBJS_DIR= objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

RM = rm -f
AR = ar crs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

$(OBJS_DIR)/%.o: %.c $(DEPS)
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
