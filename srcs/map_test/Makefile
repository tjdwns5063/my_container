CC = c++
CXXFLAGS = -Wall -Wextra -Werror
INCLUDE = -I../../include

COMP = map_comp_test
COMP_SRC = $(addsuffix .cpp, $(COMP))
COMP_OBJ = $(COMP_SRC:.cpp=.o)

EMPTY = map_empty_test
EMPTY_SRC = $(addsuffix .cpp, $(EMPTY))
EMPTY_OBJ = $(EMPTY_SRC:.cpp=.o)

FIND = map_find_test
FIND_SRC = $(addsuffix .cpp, $(FIND))
FIND_OBJ = $(FIND_SRC:.cpp=.o)

ITERATOR = map_iterator_test
ITERATOR_SRC = $(addsuffix .cpp, $(ITERATOR))
ITERATOR_OBJ = $(ITERATOR_SRC:.cpp=.o)

SWAP = map_swap_test
SWAP_SRC = $(addsuffix .cpp, $(SWAP))
SWAP_OBJ = $(SWAP_SRC:.cpp=.o)

PERFORMANCE = map_performance_test
PERFORMANCE_SRC = $(addsuffix .cpp, $(PERFORMANCE))
PERFORMANCE_OBJ = $(PERFORMANCE_SRC:.cpp=.o)

INSERT = map_insert_test
INSERT_SRC = $(addsuffix .cpp, $(INSERT))
INSERT_OBJ = $(INSERT_SRC:.cpp=.o)

ERASE = map_erase_test
ERASE_SRC = $(addsuffix .cpp, $(ERASE))
ERASE_OBJ = $(ERASE_SRC:.cpp=.o)

CONSTRUCT = map_constructor_test
CONSTRUCT_SRC = $(addsuffix .cpp, $(CONSTRUCT))
CONSTRUCT_OBJ = $(CONSTRUCT_SRC:.cpp=.o)

BOUND = map_bound_test
BOUND_SRC = $(addsuffix .cpp, $(BOUND))
BOUND_OBJ = $(BOUND_SRC:.cpp=.o)

NAME = $(COMP) $(EMPTY) $(FIND) $(ITERATOR) $(SWAP) $(PERFORMANCE) $(INSERT) $(ERASE) $(CONSTRUCT) $(BOUND)

all: $(NAME)

$(COMP): $(COMP_OBJ)
	$(CC) $(CXXFLAGS) $(INCLUDE) map_comp_test.cpp -o $@
$(EMPTY): $(EMPTY_OBJ)
	$(CC) $(CXXFLAGS) $(INCLUDE) map_empty_test.cpp -o $@
$(FIND): $(FIND_OBJ)
	$(CC) $(CXXFLAGS) $(INCLUDE) map_find_test.cpp -o $@
$(ITERATOR): $(ITERATOR_OBJ)
	$(CC) $(CXXFLAGS) $(INCLUDE) map_iterator_test.cpp -o $@
$(SWAP): $(SWAP_OBJ)
	$(CC) $(CXXFLAGS) $(INCLUDE) map_swap_test.cpp -o $@
$(PERFORMANCE): $(PERFORMANCE_OBJ)
	$(CC) $(CXXFLAGS) $(INCLUDE) map_performance_test.cpp -o $@
$(INSERT): $(INSERT_OBJ)
	$(CC) $(CXXFLAGS) $(INCLUDE) map_insert_test.cpp -o $@
$(ERASE): $(ERASE_OBJ)
	$(CC) $(CXXFLAGS) $(INCLUDE) map_erase_test.cpp -o $@
$(BOUND): $(BOUND_OBJ)
	$(CC) $(CXXFLAGS) $(INCLUDE) map_bound_test.cpp -o $@
$(CONSTRUCT): $(CONSTRUCT_OBJ)
	$(CC) $(CXXFLAGS) $(INCLUDE) map_constructor_test.cpp -o $@

%.o: %.cpp
	$(CC) $(CXXFLAGS) $(INCLUDE) -c $<

clean:
	rm -rf $(addsuffix .o, $(NAME))

fclean:
	rm -rf $(addsuffix .o, $(NAME))
	rm -rf $(NAME)

re:
	rm -rf $(addsuffix .o, $(NAME))
	rm -rf $(NAME)
	all
