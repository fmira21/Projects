NAME = brain

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98

.cpp.o:
		clang++ $(FLAGS) -c $< -o ${<:.cpp=.o}

$(NAME): $(OBJ)
		clang++ $(FLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean: 
	rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re