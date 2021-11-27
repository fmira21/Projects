NAME = mstack

SRC = main.cpp mutantstack.cpp

HEAD = mutantstack.hpp

OBJ = $(SRC:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98

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
