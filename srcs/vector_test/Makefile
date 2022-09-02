CC = c++
CXXFLAGS = -Wall -Wextra -Werror
INCLUDE = -I../../include

ASSIGN = vector_assign_test
CONSTRUCT = vector_constructor_test
INSERT = vector_insert_test
OPERATOR = vector_operator_test
RESIZE = vector_resize_test
AT = vector_at_test
ERASE = vector_erase_test
ITERATOR = vector_iterator_test
PUSH_POP = vector_push_pop_test

NAME = test

all: $(NAME)

$(NAME):  $(CONSTRUCT) $(INSERT) $(OPERATOR) $(RESIZE) $(AT) $(ERASE) $(ITERATOR) $(PUSH_POP)

$(CONSTRUCT):
	$(CC) $(CXXFLAGS) $(INCLUDE) vector_constructor_test.cpp -o $@

$(INSERT): 
	$(CC) $(CXXFLAGS) $(INCLUDE) vector_insert_test.cpp -o $@

$(OPERATOR): 
	$(CC) $(CXXFLAGS) $(INCLUDE) vector_operator_test.cpp -o $@

$(RESIZE): 
	$(CC) $(CXXFLAGS) $(INCLUDE) vector_resize_test.cpp -o $@

$(AT): 
	$(CC) $(CXXFLAGS) $(INCLUDE) vector_at_test.cpp -o $@

$(ERASE): 
	$(CC) $(CXXFLAGS) $(INCLUDE) vector_erase_test.cpp -o $@

$(ITERATOR): 
	$(CC) $(CXXFLAGS) $(INCLUDE) vector_iterator_test.cpp -o $@

$(PUSH_POP): 
	$(CC) $(CXXFLAGS) $(INCLUDE) vector_push_pop_test.cpp -o $@

clean:
	rm -rf $(ASSIGN) $(CONSTRUCT) $(INSERT) $(OPERATOR) $(RESIZE) $(AT) $(ERASE) $(ITERATOR) $(PUSH_POP)

re:
	rm -rf $(NAME)
	make -C . all
