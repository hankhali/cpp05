# Program
NAME := bureaucrat

# Compiler and flags
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

# Source files
SRC := Bureaucrat.cpp main.cpp Form.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
OBJ := $(SRC:.cpp=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $@ $(CXXFLAGS) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) Home_shrubbery

re: fclean all

.PHONY: all clean fclean re

