NAME	= Now_were_talking
CXX		= clang++
FLAGS	= -std=c++11 -Wall -Wextra -Werror
RM		= rm -rf

HEADERS	= Fixed.hpp

SRCS	=	main.cpp \
			Fixed.cpp

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	$(CXX) $(FLAGS) -o $(NAME) $(SRCS)

clean:
	@echo nothing to clean, use fclean

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re