CC = c++
CXXFLAGS = -Wall -Wextra -Werror

NAME = test

MAP = map
VEC_SRCS = srcs/test.cpp
MAP_SRCS = srcs/map_test.cpp
INCLUDE = -I./include
OBJS = $(VEC_SRCS:.cpp=.o)
MAP_OBJS = $(MAP_SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)

$(MAP): $(MAP_OBJS)
	$(CC) $(CXXFLAGS) $(INCLUDE) $(MAP_OBJS) -o $(MAP)

%.o: %.cpp
	$(CC) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJS) $(MAP_OBJS)

fclean:
	rm -rf $(OBJS) $(MAP_OBJS)
	rm -rf $(NAME) $(MAP)

re:
	rm -rf $(OBJS)
	rm -rf $(NAME)
	make -C . all