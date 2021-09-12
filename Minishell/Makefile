NAME = minishell
UNAME = $(shell whoami)
CFLAGS = -Wall -Werror -Wextra
COMPILER = gcc
HEADER_DIR = includes
SRC_FILES = main.c\
			cd.c\
			cmd_parser.c\
			darray_utils.c\
			echo_utils.c\
			echo.c\
			entrypoints.c\
			env_vars.c\
			env.c\
			execution.c\
			export_utils.c\
			export.c\
			ft_split.c\
			ft_split2.c\
			keyv_utils.c\
			libutils.c\
			libutils2.c\
			list_utils.c\
			parser_utils.c\
			parser_utils2.c\
			parser_utils3.c\
			pipe_utils.c\
			pwd_unset.c\
			redirects.c\
			redir_utils.c\
			redir_utils2.c\
			redir_utils3.c\
			signals.c
OBJ_FILES = $(SRC_FILES:.c=.o)
#FLAGS = -lreadline -L/opt/homebrew/opt/readline/lib -I/opt/homebrew/opt/readline/include
FLAGS = -lreadline -L/Users/$(UNAME)/.brew/Cellar/readline/8.1/lib/ -I/Users/$(UNAME)/.brew/Cellar/readline/8.1/include -g -fsanitize=address


all: $(OBJ) $(NAME)

$(NAME): $(OBJ_FILES)
		gcc $(CFLAGS) $(OBJ_FILES) -I $(HEADER_DIR) $(FLAGS) -o $(NAME)

clean:
	rm $(OBJ_FILES)

fclean: clean
	rm $(NAME)

re: clean all