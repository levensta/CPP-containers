#include <iostream>
#include "iterator.hpp"
#include <forward_list>

int main() {
	std::cout << "Hello, World!" << std::endl;
	std::forward_list<int>	vec;
	vec.push_front(10);
	vec.push_front(12);
	std::forward_list<int>::iterator it = vec.begin();
	ft::advance(it, -1);
	std::cout << *it << std::endl;
	return 0;
}
