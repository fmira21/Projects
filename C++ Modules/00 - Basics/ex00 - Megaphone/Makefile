NAME = megaphone

SRC = megaphone.cpp

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

test:
	./$(NAME)  "shhhhh... I think the students are asleep..." ; ./$(NAME)  Damnit " ! " "Sorry students, I thought this thing was off." ; ./$(NAME)

.PHONY: all clean fclean re