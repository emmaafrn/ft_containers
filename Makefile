NAME = ft_containers

SRCS = main.cpp

OBJS = ${SRCS:.cpp=.o}

INC = Includes/Iterator.hpp Includes/Vector.hpp

CXX  = clang++

RM  = rm -f

INC_CMP = -I .

CXXFLAGS = -g3 -Wall -Wextra -Werror -std=c++98 #-g3 -fsanitize=address

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) $(INC_CMP) $(OBJS) -o $(NAME)

$(OBJS):		$(INC)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:			 fclean all

.PHONY: all clean fclean re