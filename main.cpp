#include "headers.hpp"
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <utility>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"

int		main(int narg, char **args) {
	mkdir("./unit-tests", 0777);
	if (narg < 2) {
		test_vector();
		test_stack();
		test_map();
	}
	else {
		 if (std::string(args[1]) == "vector")
		 	test_vector();
		 if (std::string(args[1]) == "stack")
		 	test_stack();
		 if (std::string(args[1]) == "map")
		 	test_map();
	}
	return 0;
}