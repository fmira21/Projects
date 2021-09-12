cmake_minimum_required(VERSION 3.19)
#SET(MYCOMPILE_FLAGS "-ledit -lreadline -L/Users/fmira/.brew/Cellar/readline/8.1/lib/ -I/Users/fmira/.brew/Cellar/readline/8.1/include")
SET(MYCOMPILE_FLAGS "-ledit -lreadline -L/Users/buthor/.brew/Cellar/readline/8.1/lib/ -I/Users/buthor/.brew/Cellar/readline/8.1/include")
SET(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} ${MYCOMPILE_FLAGS}")
project(msh C)

set(CMAKE_C_STANDARD 99)

add_executable(msh includes/minishell.h pasha.c dima.c main.c signals.c redirects.c)