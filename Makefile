CC		= g++

NAME		= Gomoku

SRCSDIR		= srcs
COREDIR		= $(SRCSDIR)/core/
RULEDIR		= $(SRCSDIR)/rule/

CORESRCS	= GameMap.cpp \
		  GameManager.cpp \
		  Player.cpp \
		  Human.cpp \
		  AI.cpp \
		  Game.cpp \
		  Judge.cpp

RULESRCS	= BasicCheck.cpp \
		  Win.cpp \
		  EatThem.cpp


SRCS		+= $(addprefix $(COREDIR), $(CORESRCS))
SRCS		+= $(addprefix $(RULEDIR), $(RULESRCS))
OBJS		= $(SRCS:.cpp=.o)

CXXFLAGS	+= -W -Wall -Werror -Wextra -std=c++11 -O3 -march=native
CXXFLAGS	+= -I./$(COREDIR)/ -I./$(RULEDIR)/

LDFLAGS		+=

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
