NAME = bureaucrat

SRC = main.cpp Bureaucrat.cpp Form.cpp

HEAD = Bureaucrat.hpp Form.hpp

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
