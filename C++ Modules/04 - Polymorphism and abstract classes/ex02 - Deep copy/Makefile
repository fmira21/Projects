NAME = animal

SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp Worm.cpp

HEAD = main.hpp Animal.hpp Dog.hpp Cat.hpp Brain.hpp Worm.hpp

OBJ = $(SRC:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

.cpp.o:
		c++ $(FLAGS) -c $< -o ${<:.cpp=.o}

$(NAME): $(HEAD) $(OBJ)
		c++ $(FLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
