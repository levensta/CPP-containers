cmake_minimum_required(VERSION 3.20)
project(ft_containers)

set(CMAKE_CXX_STANDARD 98)

add_executable(ft_containers main.cpp vector_iterator.hpp iterator.hpp vector.hpp utils.hpp headers.hpp
        unit-tests/headers/color.hpp
        unit-tests/headers/test_vector.hpp
        unit-tests/vector/access.cpp
        unit-tests/vector/capacity.cpp
        unit-tests/vector/const_iterator.cpp
        unit-tests/vector/const_reverse_iterator.cpp
        unit-tests/vector/constructors.cpp
        unit-tests/vector/iterator.cpp
        unit-tests/vector/modifiers.cpp
        unit-tests/vector/operators.cpp
        unit-tests/vector/reverse_iterator.cpp
        unit-tests/vector/test_vector.cpp
        unit-tests/print_test.cpp
        stack.hpp
        unit-tests/stack/methods.cpp
        unit-tests/stack/operators.cpp
        unit-tests/stack/test_stack.cpp nodes.hpp red_black_tree.hpp map.hpp tree_iterator.hpp
        unit-tests/map/access.cpp
        unit-tests/map/capacity.cpp
        unit-tests/map/const_iterator.cpp
        unit-tests/map/const_reverse_iterator.cpp
        unit-tests/map/constructors.cpp
        unit-tests/map/iterator.cpp
        unit-tests/map/modifiers.cpp
        unit-tests/map/observers.cpp
        unit-tests/map/operations.cpp
        unit-tests/map/reverse_iterator.cpp
        unit-tests/map/test_map.cpp)