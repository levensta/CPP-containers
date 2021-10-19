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
        unit-tests/stack/test_stack.cpp)