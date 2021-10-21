#include "headers.hpp"
#include <functional>
#include <ios>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <ostream>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>
// #include "map.hpp"
#include "vector.hpp"
// #include "red_black_tree.hpp"
// #include "new_iterator.hpp"
 #include <stack>
 #include "stack.hpp"

#include "red_black_tree.hpp"

int		main(int narg, char **args) {
	ft::pair<int, int> pr[] = {ft::make_pair(5, 4), ft::make_pair(2, 4), ft::make_pair(3, 4), ft::make_pair(6, 4)};
	ft::end_map_node<ft::pair<int, int> >	e;
	ft::map_node<ft::pair<int, int> > *n = &e;
	std::allocator<ft::map_node<ft::pair<int, int> > >	alloc;
	for (int i = 0; i < 4; ++i) {
		ft::red_black_tree<ft::map_node<ft::pair<int, int> >, ft::end_map_node<ft::pair<int, int> > >::insert(&n, &pr[i], alloc);
	}
	std::cout << "" << std::endl;
	std::cout << "" << std::endl;
	ft::red_black_tree<ft::map_node<ft::pair<int, int> >, ft::end_map_node<ft::pair<int, int> > >::clear(&n, alloc);

//	mkdir("./unit-tests", 0777);
//	if (narg < 2) {
//		test_vector();
////		 test_map();
//		 test_stack();
//	}
//	else {
//		// if (std::string(args[1]) == "map")
//		// 	test_map();
//		if (std::string(args[1]) == "vector")
//			test_vector();
//		 if (std::string(args[1]) == "stack")
//		 	test_stack();
//	}
	return 0;
}