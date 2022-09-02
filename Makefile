CC = c++
CXXFLAGS = -Wall -Wextra -Werror


MAP = map
VECTOR = vector

VEC_DIR = srcs/vector_test/
VEC_SRCS_NAME = vector_assign_test.cpp vector_constructor_test.cpp vector_insert_test.cpp vector_operator_test.cpp vector_resize_test.cpp\
	vector_at_test.cpp vector_erase_test.cpp vector_iterator_test.cpp vector_push_pop_test.cpp

MAP_DIR = srcs/map_test/
MAP_SRCS_NAME = map_comp_test.cpp map_empty_test.cpp map_find_test.cpp map_iterator_test.cpp map_swap_test.cpp map_performance_test.cpp\
	map_insert_test.cpp map_erase_test.cpp map_constructor_test.cpp map_bound_test.cpp
VEC_SRCS = $(addprefix $(VEC_DIR), $(VEC_SRCS_NAME))
MAP_SRCS = $(addprefix $(MAP_DIR), $(MAP_SRCS_NAME))

VEC_OBJS = $(VEC_SRCS:.cpp=.o)
MAP_OBJS = $(MAP_SRCS:.cpp=.o)


INCLUDE = -I./include

VEC_TEST = $(basename $(VEC_SRCS))
MAP_TEST = $(basename $(MAP_SRCS))

NAME = test

all: $(NAME)

$(NAME): $(VEC_OBJS) $(MAP_OBJS)
	$(CC) $(CXXFLAGS) $(INCLUDE) $< $@

%.o: %.cpp
	$(CC) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(VEC_OBJS) $(MAP_OBJS)

# fclean:
# 	rm -rf $(OBJS) $(MAP_OBJS)
# 	rm -rf $(NAME) $(MAP)

# re:
# 	rm -rf $(OBJS) $(MAP_OBJS)
# 	rm -rf $(NAME) $(MAP)
# 	make -C . all
# 	make -C . map