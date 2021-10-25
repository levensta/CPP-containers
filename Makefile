NAME = test_containers.out

GCC = clang++

LOG_FOLDERS =	unit-tests/*/const_iterator/ \
				unit-tests/*/const_reverse_iterator/ \
				unit-tests/*/iterator/ \
				unit-tests/*/reverse_iterator/

SRC =	main.cpp \
		unit-tests/print_test.cpp \
        unit-tests/vector/capacity.cpp \
		unit-tests/vector/access.cpp \
        unit-tests/vector/const_iterator.cpp \
        unit-tests/vector/const_reverse_iterator.cpp \
        unit-tests/vector/constructors.cpp \
        unit-tests/vector/iterator.cpp \
        unit-tests/vector/modifiers.cpp \
        unit-tests/vector/operators.cpp \
        unit-tests/vector/reverse_iterator.cpp \
        unit-tests/vector/test_vector.cpp \
		unit-tests/stack/methods.cpp \
		unit-tests/stack/operators.cpp \
		unit-tests/stack/test_stack.cpp \
		unit-tests/map/access.cpp \
		unit-tests/map/capacity.cpp \
		unit-tests/map/const_iterator.cpp \
		unit-tests/map/const_reverse_iterator.cpp \
		unit-tests/map/constructors.cpp \
		unit-tests/map/iterator.cpp \
		unit-tests/map/modifiers.cpp \
		unit-tests/map/observers.cpp \
		unit-tests/map/operations.cpp \
		unit-tests/map/reverse_iterator.cpp \
		unit-tests/map/test_map.cpp


OBJ =	$(SRC:.cpp=.o)


all: $(NAME)

%.o:		%.cpp
	$(GCC) -c $< -o $@

vector:

$(NAME): $(OBJ)
	$(GCC) $(OBJ) -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME) $(LOG_FOLDERS) unit-tests/*/*.log

re: fclean all