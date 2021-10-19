#include "../headers/test_vector.hpp"

void	reverse_iterator() {
	mkdir("./unit-tests/vector/reverse_iterator", 0777);
	std::cout << "Reverse:\t|";
	std::list<int>	lst;
	lst.push_back(10);
	lst.push_back(99);
	lst.push_back(761);
	lst.push_back(-19);
	lst.insert(lst.end(), 15, 999);
	lst.push_back(975);
	lst.push_back(500);

	/*  OPERATOR*  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>			std_vec;
		ft::vector<int>				ft_vec;
		std::list<int>				std_lst;
		std::list<int>				ft_lst;
		test_push_back<int, std::list<int>::iterator>(std_vec, ft_vec, lst);
		std::vector<int>::reverse_iterator	std_it = std_vec.rbegin();
		ft::vector<int>::reverse_iterator	ft_it = ft_vec.rbegin();

		/*Test1*/
		bool	one = (*ft_it == *std_it);
		list_push<int>(std_lst, ft_lst, *std_it, *ft_it);
		print_test_iterator<int, std::list<int>::iterator>(std_lst, ft_lst, mode, 1, "./unit-tests/vector/reverse_iterator/operator*.log");
		*ft_it = 11;
		*std_it = 11;

		/*Test2*/
		bool	two = (*ft_it == *std_it);
		list_push(std_lst, ft_lst, *std_it, *ft_it);
		print_test_iterator<int, std::list<int>::iterator>(std_lst, ft_lst, mode, 2, "./unit-tests/vector/reverse_iterator/operator*.log");


		bool	three = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 3, "./unit-tests/vector/reverse_iterator/operator*.log");
		print_result(one && two && three, true);
	}
	/*  OPERATOR->  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<std::list<int> >			std_vec;
		ft::vector<std::list<int> >				ft_vec;
		std::list<int>				std_lst;
		std::list<int>				ft_lst;
		test_push_back<std::list<int> >(std_vec, ft_vec, lst, 1);
		std::vector<std::list<int> >::reverse_iterator	std_it = std_vec.rbegin();
		ft::vector<std::list<int> >::reverse_iterator	ft_it = ft_vec.rbegin();

		/*Test1*/
		bool	one = (*ft_it->rbegin() == *std_it->rbegin());
		list_push<int>(std_lst, ft_lst, *std_it->rbegin(), *ft_it->rbegin());
		print_test_iterator<int , std::list<int>::iterator>(std_lst, ft_lst, mode, 1, "./unit-tests/vector/reverse_iterator/operator->.log");
		*ft_it->rbegin() = 11;
		*std_it->rbegin() = 11;

		/*Test2*/
		bool	two = (*ft_it->rbegin() == *std_it->rbegin());
		list_push<int>(std_lst, ft_lst, *std_it->rbegin(), *ft_it->rbegin());
		print_test_iterator<int , std::list<int>::iterator>(std_lst, ft_lst, mode, 1, "./unit-tests/vector/reverse_iterator/operator->.log");

		print_result(one && two, true);
	}
	/*  OPERATOR++  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>			std_vec;
		ft::vector<int>				ft_vec;
		std::list<int>				std_lst;
		std::list<int>				ft_lst;
		test_push_back<int, std::list<int>::iterator>(std_vec, ft_vec, lst);
		std::vector<int>::reverse_iterator	std_it = std_vec.rbegin();
		ft::vector<int>::reverse_iterator	ft_it = ft_vec.rbegin();

		/*Test1*/
		ft_it++;
		std_it++;
		bool	one = (*ft_it == *std_it);
		list_push<int>(std_lst, ft_lst, *std_it, *ft_it);
		print_test_iterator<int, std::list<int>::iterator>(std_lst, ft_lst, mode, 1, "./unit-tests/vector/reverse_iterator/operator++.log");
		*ft_it = 11;
		*std_it = 11;

		/*Test2*/
		bool	two = (*ft_it++ == *std_it++);
		list_push(std_lst, ft_lst, *(--std_it), *(--ft_it));
		print_test_iterator<int, std::list<int>::iterator>(std_lst, ft_lst, mode, 2, "./unit-tests/vector/reverse_iterator/operator++.log");

		bool	three = (*(++ft_it) == *(++std_it));
		list_push(std_lst, ft_lst, *(std_it), *(ft_it));
		print_test_iterator<int, std::list<int>::iterator>(std_lst, ft_lst, mode, 3, "./unit-tests/vector/reverse_iterator/operator++.log");


		bool	four = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 4, "./unit-tests/vector/reverse_iterator/operator++.log");
		print_result(one && two && three && four, true);
	}
	/*  OPERATOR--  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>			std_vec;
		ft::vector<int>				ft_vec;
		std::list<int>				std_lst;
		std::list<int>				ft_lst;
		test_push_back<int, std::list<int>::iterator>(std_vec, ft_vec, lst);
		std::vector<int>::reverse_iterator	std_it = std_vec.rend();
		ft::vector<int>::reverse_iterator	ft_it = ft_vec.rend();

		/*Test1*/
		ft_it--;
		std_it--;
		bool	one = (*ft_it == *std_it);
		list_push<int>(std_lst, ft_lst, *std_it, *ft_it);
		print_test_iterator<int, std::list<int>::iterator>(std_lst, ft_lst, mode, 1, "./unit-tests/vector/reverse_iterator/operator--.log");
		*ft_it = 11;
		*std_it = 11;

		/*Test2*/
		bool	two = (*ft_it-- == *std_it--);
		list_push(std_lst, ft_lst, *(++std_it), *(++ft_it));
		print_test_iterator<int, std::list<int>::iterator>(std_lst, ft_lst, mode, 2, "./unit-tests/vector/reverse_iterator/operator--.log");
		*ft_it = 11;
		*std_it = 11;

		bool	three = (*(--ft_it) == *(--std_it));
		list_push(std_lst, ft_lst, *(std_it), *(ft_it));
		print_test_iterator<int, std::list<int>::iterator>(std_lst, ft_lst, mode, 3, "./unit-tests/vector/reverse_iterator/operator--.log");
		*ft_it = 11;
		*std_it = 11;

		bool	four = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 4, "./unit-tests/vector/reverse_iterator/operator--.log");
		print_result(one && two && three && four, true);
	}
	/*  OPERATOR+=  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>			std_vec;
		ft::vector<int>				ft_vec;
		std::list<int>				std_lst;
		std::list<int>				ft_lst;
		test_push_back<int, std::list<int>::iterator>(std_vec, ft_vec, lst);
		std::vector<int>::reverse_iterator	std_it = std_vec.rbegin();
		ft::vector<int>::reverse_iterator	ft_it = ft_vec.rbegin();

		/*Test1*/
		ft_it += 2;
		std_it += 2;
		bool	one = (*ft_it == *std_it);
		list_push<int>(std_lst, ft_lst, *std_it, *ft_it);
		print_test_iterator<int, std::list<int>::iterator>(std_lst, ft_lst, mode, 1, "./unit-tests/vector/reverse_iterator/operator+=.log");
		*ft_it = 11;
		*std_it = 11;

		/*Test2*/
		ft_it += 5;
		std_it += 5;
		bool	two = (*ft_it == *std_it);
		list_push(std_lst, ft_lst, *(std_it), *(ft_it));
		print_test_iterator<int, std::list<int>::iterator>(std_lst, ft_lst, mode, 2, "./unit-tests/vector/reverse_iterator/operator+=.log");
		*ft_it = 11;
		*std_it = 11;


		bool	three = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 3, "./unit-tests/vector/reverse_iterator/operator+=.log");
		print_result(one && two && three, true);
	}
	/*  OPERATOR-=  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>			std_vec;
		ft::vector<int>				ft_vec;
		std::list<int>				std_lst;
		std::list<int>				ft_lst;
		test_push_back<int, std::list<int>::iterator>(std_vec, ft_vec, lst);
		std::vector<int>::reverse_iterator	std_it = std_vec.rend();
		ft::vector<int>::reverse_iterator	ft_it = ft_vec.rend();

		/*Test1*/
		ft_it -= 2;
		std_it -= 2;
		bool	one = (*ft_it == *std_it);
		list_push<int>(std_lst, ft_lst, *std_it, *ft_it);
		print_test_iterator<int, std::list<int>::iterator>(std_lst, ft_lst, mode, 1, "./unit-tests/vector/reverse_iterator/operator-=.log");
		*ft_it = 11;
		*std_it = 11;

		/*Test2*/
		ft_it -= 5;
		std_it -= 5;
		bool	two = (*ft_it == *std_it);
		list_push(std_lst, ft_lst, *(std_it), *(ft_it));
		print_test_iterator<int, std::list<int>::iterator>(std_lst, ft_lst, mode, 2, "./unit-tests/vector/reverse_iterator/operator-=.log");
		*ft_it = 11;
		*std_it = 11;


		bool	three = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 3, "./unit-tests/vector/reverse_iterator/operator-=.log");
		print_result(one && two && three, true);
	}
	/*  OPERATOR[]  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>			std_vec;
		ft::vector<int>				ft_vec;
		std::list<int>				std_lst;
		std::list<int>				ft_lst;
		test_push_back<int, std::list<int>::iterator>(std_vec, ft_vec, lst);
		std::vector<int>::reverse_iterator	std_it = std_vec.rbegin();
		ft::vector<int>::reverse_iterator	ft_it = ft_vec.rbegin();

		/*Test1*/
		bool	one = (ft_it[0] == std_it[0] && ft_it[6] == std_it[6]);
		list_push<int>(std_lst, ft_lst, std_it[0], ft_it[0]);
		list_push<int>(std_lst, ft_lst, std_it[6], ft_it[6]);
		print_test_iterator<int, std::list<int>::iterator>(std_lst, ft_lst, mode, 1, "./unit-tests/vector/reverse_iterator/operator[].log");
		ft_it[6] = 11;
		std_it[6] = 11;

		/*Test2*/
		ft_it += 6;
		std_it += 6;
		bool	two = (ft_it[0] == std_it[0] && ft_it[6] == std_it[6]);
		list_push<int>(std_lst, ft_lst, std_it[0], ft_it[0]);
		list_push<int>(std_lst, ft_lst, std_it[6], ft_it[6]);
		print_test_iterator<int, std::list<int>::iterator>(std_lst, ft_lst, mode, 2, "./unit-tests/vector/reverse_iterator/operator[].log");
		ft_it[6] = 11;
		std_it[6] = 11;


		bool	three = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 3, "./unit-tests/vector/reverse_iterator/operator[].log");
		print_result(one && two && three, true);
	}
	/*  OPERATOR==  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>			std_vec;
		ft::vector<int>				ft_vec;
		std::list<bool>				std_lst;
		std::list<bool>				ft_lst;
		test_push_back<int, std::list<int>::iterator>(std_vec, ft_vec, lst);
		std::vector<int>::reverse_iterator	std_it = std_vec.rbegin();
		ft::vector<int>::reverse_iterator	ft_it = ft_vec.rbegin();
		bool	ft_bool;
		bool	std_bool;

		/*Test1*/
		ft_bool = ft_it == ft_vec.rbegin();
		std_bool = std_it == std_vec.rbegin();
		bool	one = (ft_bool == std_bool);
		list_push<bool>(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 1, "./unit-tests/vector/reverse_iterator/operator==.log");
		ft_it[6] = 11;
		std_it[6] = 11;

		/*Test2*/
		ft_it += 6;
		std_it += 6;
		ft_bool = ft_it == ft_vec.rbegin();
		std_bool = std_it == std_vec.rbegin();
		bool	two = (ft_bool == std_bool);
		list_push<bool>(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 2, "./unit-tests/vector/reverse_iterator/operator==.log");
		ft_it[6] = 11;
		std_it[6] = 11;


		bool	three = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 3, "./unit-tests/vector/reverse_iterator/operator==.log");
		print_result(one && two && three, true);
	}
	/*  OPERATOR!=  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>			std_vec;
		ft::vector<int>				ft_vec;
		std::list<bool>				std_lst;
		std::list<bool>				ft_lst;
		test_push_back<int, std::list<int>::iterator>(std_vec, ft_vec, lst);
		std::vector<int>::reverse_iterator	std_it = std_vec.rbegin();
		ft::vector<int>::reverse_iterator	ft_it = ft_vec.rbegin();
		bool	ft_bool;
		bool	std_bool;

		/*Test1*/
		ft_bool = ft_it != ft_vec.rbegin();
		std_bool = std_it != std_vec.rbegin();
		bool	one = (ft_bool == std_bool);
		list_push<bool>(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 1, "./unit-tests/vector/reverse_iterator/operator!=.log");
		ft_it[6] = 11;
		std_it[6] = 11;

		/*Test2*/
		ft_it += 6;
		std_it += 6;
		ft_bool = ft_it != ft_vec.rbegin();
		std_bool = std_it != std_vec.rbegin();
		bool	two = (ft_bool == std_bool);
		list_push<bool>(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 2, "./unit-tests/vector/reverse_iterator/operator!=.log");
		ft_it[6] = 11;
		std_it[6] = 11;


		bool	three = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 3, "./unit-tests/vector/reverse_iterator/operator!=.log");
		print_result(one && two && three, true);
	}
	/*  OPERATOR<  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>			std_vec;
		ft::vector<int>				ft_vec;
		std::list<bool>				std_lst;
		std::list<bool>				ft_lst;
		test_push_back<int, std::list<int>::iterator>(std_vec, ft_vec, lst);
		std::vector<int>::reverse_iterator	std_it = std_vec.rbegin();
		ft::vector<int>::reverse_iterator	ft_it = ft_vec.rbegin();
		bool	ft_bool;
		bool	std_bool;

		/*Test1*/
		ft_bool = ft_it < ft_vec.rbegin();
		std_bool = std_it < std_vec.rbegin();
		bool	one = (ft_bool == std_bool);
		list_push<bool>(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 1, "./unit-tests/vector/reverse_iterator/operator<.log");
		ft_it[6] = 11;
		std_it[6] = 11;

		/*Test2*/
		ft_it += 6;
		std_it += 6;
		ft_bool = ft_it < ft_vec.rend();
		std_bool = std_it < std_vec.rend();
		bool	two = (ft_bool == std_bool);
		list_push<bool>(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 2, "./unit-tests/vector/reverse_iterator/operator<.log");
		ft_it[6] = 11;
		std_it[6] = 11;


		bool	three = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 3, "./unit-tests/vector/reverse_iterator/operator<.log");
		print_result(one && two && three, true);
	}
	/*  OPERATOR<=  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>			std_vec;
		ft::vector<int>				ft_vec;
		std::list<bool>				std_lst;
		std::list<bool>				ft_lst;
		test_push_back<int, std::list<int>::iterator>(std_vec, ft_vec, lst);
		std::vector<int>::reverse_iterator	std_it = std_vec.rbegin();
		ft::vector<int>::reverse_iterator	ft_it = ft_vec.rbegin();
		bool	ft_bool;
		bool	std_bool;

		/*Test1*/
		ft_bool = ft_it <= ft_vec.rbegin();
		std_bool = std_it <= std_vec.rbegin();
		bool	one = (ft_bool == std_bool);
		list_push<bool>(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 1, "./unit-tests/vector/reverse_iterator/operator<=.log");
		ft_it[6] = 11;
		std_it[6] = 11;

		/*Test2*/
		ft_it += 6;
		std_it += 6;
		ft_bool = ft_it <= ft_vec.rbegin();
		std_bool = std_it <= std_vec.rbegin();
		bool	two = (ft_bool == std_bool);
		list_push<bool>(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 2, "./unit-tests/vector/reverse_iterator/operator<=.log");
		ft_it[6] = 11;
		std_it[6] = 11;

		/*Test3*/
		ft_it += 2;
		std_it += 2;
		ft_bool = ft_it <= ft_vec.rend();
		std_bool = std_it <= std_vec.rend();
		bool	three = (ft_bool == std_bool);
		list_push<bool>(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 3, "./unit-tests/vector/reverse_iterator/operator<=.log");
		ft_it[6] = 11;
		std_it[6] = 11;


		bool	four = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 4, "./unit-tests/vector/reverse_iterator/operator<=.log");
		print_result(one && two && three && four, true);
	}
	/*  OPERATOR>  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>			std_vec;
		ft::vector<int>				ft_vec;
		std::list<bool>				std_lst;
		std::list<bool>				ft_lst;
		test_push_back<int, std::list<int>::iterator>(std_vec, ft_vec, lst);
		std::vector<int>::reverse_iterator	std_it = std_vec.rbegin();
		ft::vector<int>::reverse_iterator	ft_it = ft_vec.rbegin();
		bool	ft_bool;
		bool	std_bool;

		/*Test1*/
		ft_bool = ft_it > ft_vec.rbegin();
		std_bool = std_it > std_vec.rbegin();
		bool	one = (ft_bool == std_bool);
		list_push<bool>(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 1, "./unit-tests/vector/reverse_iterator/operator>.log");
		ft_it[6] = 11;
		std_it[6] = 11;

		/*Test2*/
		ft_it += 6;
		std_it += 6;
		ft_bool = ft_it > ft_vec.rbegin();
		std_bool = std_it > std_vec.rbegin();
		bool	two = (ft_bool == std_bool);
		list_push<bool>(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 2, "./unit-tests/vector/reverse_iterator/operator>.log");
		ft_it[6] = 11;
		std_it[6] = 11;


		bool	three = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 3, "./unit-tests/vector/reverse_iterator/operator>.log");
		print_result(one && two && three, true);
	}
	/*  OPERATOR>=  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>			std_vec;
		ft::vector<int>				ft_vec;
		std::list<bool>				std_lst;
		std::list<bool>				ft_lst;
		test_push_back<int, std::list<int>::iterator>(std_vec, ft_vec, lst);
		std::vector<int>::reverse_iterator	std_it = std_vec.rbegin();
		ft::vector<int>::reverse_iterator	ft_it = ft_vec.rbegin();
		bool	ft_bool;
		bool	std_bool;

		/*Test1*/
		ft_bool = ft_it >= ft_vec.rbegin();
		std_bool = std_it >= std_vec.rbegin();
		bool	one = (ft_bool == std_bool);
		list_push<bool>(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 1, "./unit-tests/vector/reverse_iterator/operator>=.log");
		ft_it[6] = 11;
		std_it[6] = 11;

		/*Test2*/
		ft_it += 6;
		std_it += 6;
		ft_bool = ft_it >= ft_vec.rbegin();
		std_bool = std_it >= std_vec.rbegin();
		bool	two = (ft_bool == std_bool);
		list_push<bool>(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 2, "./unit-tests/vector/reverse_iterator/operator>=.log");
		ft_it[6] = 11;
		std_it[6] = 11;

		/*Test3*/
		ft_it += 2;
		std_it += 2;
		ft_bool = ft_it >= ft_vec.rend();
		std_bool = std_it >= std_vec.rend();
		bool	three = (ft_bool == std_bool);
		list_push<bool>(std_lst, ft_lst, std_bool, ft_bool);
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 3, "./unit-tests/vector/reverse_iterator/operator>=.log");
		ft_it[6] = 11;
		std_it[6] = 11;

		bool	four = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 4, "./unit-tests/vector/reverse_iterator/operator>=.log");
		print_result(one && two && three && four, true);
	}
	/*  OPERATOR+  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>			std_vec;
		ft::vector<int>				ft_vec;
		std::list<int>				std_lst;
		std::list<int>				ft_lst;
		test_push_back<int, std::list<int>::iterator>(std_vec, ft_vec, lst);
		std::vector<int>::reverse_iterator	std_it = std_vec.rbegin();
		ft::vector<int>::reverse_iterator	ft_it = ft_vec.rbegin();

		/*Test1*/
		bool	one = (*(ft_it + 5) == *(std_it + 5));
		list_push<int>(std_lst, ft_lst, *(std_it + 5), *(ft_it + 5));
		print_test_iterator<int, std::list<int>::iterator>(std_lst, ft_lst, mode, 1, "./unit-tests/vector/reverse_iterator/operator+.log");
		*(ft_it + 5) = 11;
		*(std_it + 5) = 11;
		ft_it++;
		std_it++;

		/*Test2*/
		bool	two = (*(ft_it + 5) == *(std_it + 5));
		list_push(std_lst, ft_lst, *(std_it + 5), *(ft_it + 5));
		print_test_iterator<int, std::list<int>::iterator>(std_lst, ft_lst, mode, 2, "./unit-tests/vector/reverse_iterator/operator+.log");
		*(ft_it + 18) = 11;
		*(std_it + 18) = 11;

		/*Test3*/
		bool	three = (*(ft_it + 18) == *(std_it + 18));
		list_push(std_lst, ft_lst, *(std_it + 18), *(ft_it + 18));
		print_test_iterator<int, std::list<int>::iterator>(std_lst, ft_lst, mode, 3, "./unit-tests/vector/reverse_iterator/operator+.log");

		/*Test4*/
		bool	four = (*(ft_it + 11) == *(std_it + 11));
		list_push(std_lst, ft_lst, *(std_it + 11), *(ft_it + 11));
		print_test_iterator<int, std::list<int>::iterator>(std_lst, ft_lst, mode, 4, "./unit-tests/vector/reverse_iterator/operator+.log");

		bool	five = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 5, "./unit-tests/vector/reverse_iterator/operator+.log");
		print_result(one && two && three && four && five, true);
	}
	/*  OPERATOR-  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>			std_vec;
		ft::vector<int>				ft_vec;
		std::list<int>				std_lst;
		std::list<int>				ft_lst;
		test_push_back<int, std::list<int>::iterator>(std_vec, ft_vec, lst);
		std::vector<int>::reverse_iterator	std_it = std_vec.rend();
		ft::vector<int>::reverse_iterator	ft_it = ft_vec.rend();

		/*Test1*/
		bool	one = (*(ft_it - 5) == *(std_it - 5));
		list_push<int>(std_lst, ft_lst, *(std_it - 5), *(ft_it - 5));
		print_test_iterator<int, std::list<int>::iterator>(std_lst, ft_lst, mode, 1, "./unit-tests/vector/reverse_iterator/operator-.log");
		*(ft_it - 5) = 11;
		*(std_it - 5) = 11;

		/*Test2*/
		bool	two = (*(ft_it - 5) == *(std_it - 5));
		list_push(std_lst, ft_lst, *(std_it - 5), *(ft_it - 5));
		print_test_iterator<int, std::list<int>::iterator>(std_lst, ft_lst, mode, 2, "./unit-tests/vector/reverse_iterator/operator-.log");
		*(ft_it - 18) = 11;
		*(std_it - 18) = 11;

		/*Test3*/
		bool	three = (*(ft_it - 18) == *(std_it - 18));
		list_push(std_lst, ft_lst, *(std_it - 18), *(ft_it - 18));
		print_test_iterator<int, std::list<int>::iterator>(std_lst, ft_lst, mode, 3, "./unit-tests/vector/reverse_iterator/operator-.log");

		/*Test4*/
		bool	four = (*(ft_it - 11) == *(std_it - 11));
		list_push(std_lst, ft_lst, *(std_it - 11), *(ft_it - 11));
		print_test_iterator<int, std::list<int>::iterator>(std_lst, ft_lst, mode, 4, "./unit-tests/vector/reverse_iterator/operator-.log");

		bool	five = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 5, "./unit-tests/vector/reverse_iterator/operator-.log");
		print_result(one && two && three && four && five, true);
	}
	std::cout << std::endl;
}