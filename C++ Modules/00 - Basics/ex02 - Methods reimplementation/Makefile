NAME = accounts

SRC = Account.cpp tests.cpp

HEAD = Account.hpp

OBJ = $(SRC:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98

#Testing variables
TESTLOG = test.log # Do not forget to paste the testing log into the folder
TESTINDEX = 0      # Account index to test (0 - 7)
TESTDIFF = diff <(./accounts |  grep index:$(TESTINDEX) | cut -c 18-) <(cat $(TESTLOG) |  grep index:$(TESTINDEX) | cut -c 18-)
###################


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

test:
	bash -c '$(TESTDIFF)'

.PHONY: all clean fclean re