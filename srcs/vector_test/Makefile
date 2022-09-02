CC = c++
CXXFLAGS = -Wall -Wextra -Werror
INCLUDE = -I../../include


CONSTRUCT = vector_constructor_test
CONSTRUCT_SRC = $(addsuffix .cpp, $(CONSTRUCT))
CONSTRUCT_OBJ = $(CONSTRUCT_SRC:.cpp=.o)

INSERT = vector_insert_test
INSERT_SRC = $(addsuffix .cpp, $(INSERT))
INSERT_OBJ = $(INSERT_SRC:.cpp=.o)

OPERATOR = vector_operator_test
OPERATOR_SRC = $(addsuffix .cpp, $(OPERATOR))
OPERATOR_OBJ = $(OPERATOR_SRC:.cpp=.o)

RESIZE = vector_resize_test
RESIZE_SRC = $(addsuffix .cpp, $(RESIZE))
RESIZE_OBJ = $(RESIZE_SRC:.cpp=.o)

AT = vector_at_test
AT_SRC = $(addsuffix .cpp, $(ASSIGN))
AT_OBJ = $(ASSIGN_SRC:.cpp=.o)

ERASE = vector_erase_test
ERASE_SRC = $(addsuffix .cpp, $(ERASE))
ERASE_OBJ = $(ERASE_SRC:.cpp=.o)

ITERATOR = vector_iterator_test
ITERATOR_SRC = $(addsuffix .cpp, $(ITERATOR))
ITERATOR_OBJ = $(ITERATOR_SRC:.cpp=.o)

PUSH_POP = vector_push_pop_test
PUSH_POP_SRC = $(addsuffix .cpp, $(PUSH_POP))
PUSH_POP_OBJ = $(PUSH_POP_SRC:.cpp=.o)

NAME = $(CONSTRUCT) $(INSERT) $(OPERATOR) $(RESIZE) $(AT) $(ERASE) $(ITERATOR) $(PUSH_POP)

all: $(NAME)

$(CONSTRUCT): $(CONSTRUCT_OBJ)
	$(CC) $(CXXFLAGS) $(INCLUDE) vector_constructor_test.o -o $@

$(INSERT): $(INSERT_OBJ)
	$(CC) $(CXXFLAGS) $(INCLUDE) vector_insert_test.cpp -o $@

$(OPERATOR): $(OPERATOR_OBJ)
	$(CC) $(CXXFLAGS) $(INCLUDE) vector_operator_test.cpp -o $@

$(RESIZE): $(RESIZE_OBJ)
	$(CC) $(CXXFLAGS) $(INCLUDE) vector_resize_test.cpp -o $@

$(AT): $(AT_OBJ)
	$(CC) $(CXXFLAGS) $(INCLUDE) vector_at_test.cpp -o $@

$(ERASE): 
	$(CC) $(CXXFLAGS) $(INCLUDE) vector_erase_test.cpp -o $@

$(ITERATOR): $(ITERATOR_OBJ)
	$(CC) $(CXXFLAGS) $(INCLUDE) vector_iterator_test.cpp -o $@

$(PUSH_POP): $(PUSH_POP_OBJ)
	$(CC) $(CXXFLAGS) $(INCLUDE) vector_push_pop_test.cpp -o $@

%.o: %.cpp
	$(CC) $(CXXFLAGS) $(INCLUDE) -c $<

clean:
	rm -rf $(addsuffix .o, $(NAME))

make fclean:
	rm -rf $(addsuffix .o, $(NAME))
	rm -rf $(NAME)

re:
	rm -rf $(addsuffix .o, $(NAME))
	rm -rf $(NAME)
	make -C . all
