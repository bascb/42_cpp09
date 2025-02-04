NAME = PmergeMe
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Werror -Wextra -g
SRC = PmergeMe.cpp main.cpp
OBJ = PmergeMe.o main.o
DEPS = PmergeMe.hpp
	
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

$(OBJ): $(SRC) $(DEPS)
	$(CXX) $(CXXFLAGS) -c $(SRC)
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all