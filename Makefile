NAME = ft_gkrellm

SRC = main.cpp NCurses.cpp RAM.cpp Time.cpp

OBJ = main.o NCurses.o RAM.o Time.o

FLAGS = -Wall -Wextra -Werror 


all: $(NAME)

$(NAME): $(OBJ)
	@clang++ -lncurses $(OBJ) -o $(NAME)

$(OBJ):%.o:%.cpp
	@clang++ -std=c++98  $(FLAGS) -c $(SRC)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean all