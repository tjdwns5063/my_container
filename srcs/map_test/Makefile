CC = c++
CXXFLAGS = -Wall -Wextra -Werror
INCLUDE = -I../../include


MAP_SRCS_NAME = map_comp_test.cpp map_empty_test.cpp map_find_test.cpp map_iterator_test.cpp map_swap_test.cpp map_performance_test.cpp\
	map_insert_test.cpp map_erase_test.cpp map_constructor_test.cpp map_bound_test.cpp

NAME = test

COMP = map_comp_test
EMPTY = map_empty_test
FIND = map_find_test
ITERATOR = map_iterator_test
SWAP = map_swap_test
PERFORMANCE = map_performance_test
INSERT = map_insert_test
ERASE = map_erase_test
CONSTRUCT = map_constructor_test
BOUND = map_bound_test

all: $(NAME)

$(NAME): $(COMP) $(EMPTY) $(FIND) $(ITERATOR) $(SWAP) $(PERFORMANCE) $(INSERT) $(ERASE) $(CONSTRUCT) $(BOUND)

$(COMP):
	$(CC) $(CXXFLAGS) $(INCLUDE) map_comp_test.cpp -o $@
$(EMPTY):
	$(CC) $(CXXFLAGS) $(INCLUDE) map_empty_test.cpp -o $@
$(FIND):
	$(CC) $(CXXFLAGS) $(INCLUDE) map_find_test.cpp -o $@
$(ITERATOR):
	$(CC) $(CXXFLAGS) $(INCLUDE) map_iterator_test.cpp -o $@
$(SWAP):
	$(CC) $(CXXFLAGS) $(INCLUDE) map_swap_test.cpp -o $@
$(PERFORMANCE):
	$(CC) $(CXXFLAGS) $(INCLUDE) map_performance_test.cpp -o $@
$(INSERT):
	$(CC) $(CXXFLAGS) $(INCLUDE) map_insert_test.cpp -o $@
$(ERASE):
	$(CC) $(CXXFLAGS) $(INCLUDE) map_erase_test.cpp -o $@
$(BOUND):
	$(CC) $(CXXFLAGS) $(INCLUDE) map_bound_test.cpp -o $@
$(CONSTRUCT):
	$(CC) $(CXXFLAGS) $(INCLUDE) map_constructor_test.cpp -o $@


clean:
	rm -rf $(COMP) $(EMPTY) $(FIND) $(ITERATOR) $(SWAP) $(PERFORMANCE) $(INSERT) $(ERASE) $(CONSTRUCT) $(BOUND)

re:
	rm -rf $(COMP) $(EMPTY) $(FIND) $(ITERATOR) $(SWAP) $(PERFORMANCE) $(INSERT) $(ERASE) $(CONSTRUCT) $(BOUND)
	all
