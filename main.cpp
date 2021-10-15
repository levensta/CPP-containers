#include <iostream>
//#include "iterator.hpp"
//#include <forward_list>
#include <vector>
//#include "vector_iterator.hpp"
#include <memory>
int main() {
	//
	const std::vector<int> vec(10);
	try {
		vec.at(124234);
	}
	catch (std::exception &e) {
		std::cout << "||||" << e.what() << "||||" << std::endl;
	}
	return 0;
}
