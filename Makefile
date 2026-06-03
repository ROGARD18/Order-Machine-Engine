CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -I include

SRC_DIR = src
SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/Order.cpp \
	   $(SRC_DIR)/OrderBook.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = engine

all: $(NAME)

$(NAME): $(OBJS)
	@clear
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@./engine

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re