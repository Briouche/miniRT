NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

DEPS = libft.h 
SRCS =	ft_memcpy.c \
		ft_putchar_fd.c ft_putstr_fd.c \
		ft_strdup.c ft_strjoin.c ft_strlen.c \
		get_next_line.c
OBJS = ${SRCS:.c=.o}

BONUS_SRCS =
BONUS_OBJS = ${BONUS_SRCS:.c=.o}

RM = rm -f
AR = ar crs


%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

bonus: all ${BONUS_OBJS}
	${AR} ${NAME} ${BONUS_OBJS}

clean: 
	$(RM) $(OBJS) ${BONUS_OBJS}

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re