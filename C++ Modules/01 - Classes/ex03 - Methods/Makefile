NAME = violence

SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

HEAD = Weapon.hpp HumanA.hpp HumanB.hpp

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

re: fclean all

.PHONY: all clean fclean re