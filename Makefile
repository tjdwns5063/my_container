CC = c++
CXXFLAGS = -Wall -Wextra -Werror

NAME = test
SRCS = srcs/test.cpp
INCLUDE = -I./include
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS)
	rm -rf $(NAME)

re:
	rm -rf $(OBJS)
	rm -rf $(NAME)
	make -C . all