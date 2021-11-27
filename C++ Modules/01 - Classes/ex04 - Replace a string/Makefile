NAME = replace

SRC = main.cpp

HEAD = header.hpp

OBJ = $(SRC:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98

.cpp.o:
		clang++ $(FLAGS) -c $< -o ${<:.cpp=.o}

$(NAME): $(HEAD) $(OBJ)
		clang++ $(FLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ./tests/*.replace

test:
	 ./$(NAME) tests/1.txt "Replace me" "Replaced"
	 ././$(NAME) tests/2.txt "To replace" "Replaced"

re: fclean all

.PHONY: all clean fclean re