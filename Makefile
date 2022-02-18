NAME = my_containers
NAME_STD = real_containers

SRCS = main.cpp
SRCS_STD = other_main.cpp

OBJS = ${SRCS:.cpp=.o}
OBJS_STD = ${SRCS_STD:.cpp=.o}

INC = Includes/

CXX  = clang++

RM  = rm -f

INC_CMP = -I .

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address

all:			$(NAME) $(NAME_STD)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) $(INC_CMP) $(OBJS) -o $(NAME)

$(NAME_STD):		$(OBJS_STD)
				$(CXX) $(CXXFLAGS) $(INC_CMP) $(OBJS_STD) -o $(NAME_STD)

$(OBJS):		$(INC)
$(OBJS_STD):	$(INC)

clean:
				$(RM) $(OBJS) $(OBJS_STD)

fclean:			clean
				$(RM) $(NAME) $(NAME_STD)

re:			 fclean all

.PHONY: all clean fclean re