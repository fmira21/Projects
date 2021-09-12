NAME =	philo

SRCS =	philosophers.c \
		threads.c \
		init.c \
		philutils.c \
		libutils.c

OBJS =	$(SRCS:.c=.o)

FLAGS =	-Wall -Werror -Wextra -pthread

.c.o:
		gcc $(FLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(OBJS) -o $(NAME)

all:	$(NAME)

clean:
		rm -f $(OBJS)
		rm -f $(SRC_D)

fclean:	clean
		rm -f $(NAME)

re:		fclean all

.SILENT: