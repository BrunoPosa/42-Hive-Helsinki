NAME	= Repetitive_work
CXX		= c++
FLAGS	= -std=c++11 -Wall -Wextra -Werror
RM		= rm -rf

HEADERS	=	ClapTrap.hpp \
			ScavTrap.hpp \
			FragTrap.hpp

SRCS	=	main.cpp \
			ClapTrap.cpp \
			ScavTrap.cpp \
			FragTrap.cpp

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	$(CXX) $(FLAGS) -o $(NAME) $(SRCS)

clean:
	@echo nothing to clean, use fclean

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re