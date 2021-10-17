#include "../headers/test_vector.hpp"

void	capacity() {
	std::cout << "\t\t|";
	/*  SIZE  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>	std_vec;
		ft::vector<int>		ft_vec;
		std::list<size_t>	std_lst;
		std::list<size_t>	ft_lst;

		std_vec.push_back(10);
		ft_vec.push_back(10);
		bool	one = std_vec.size() == ft_vec.size();
		list_push<size_t>(std_lst, ft_lst, std_vec.size(), ft_vec.size());
		print_test_iterator<size_t, std::list<size_t>::iterator>(std_lst, ft_lst, mode, 1, "./unit-tests/vector/size.log");

		std_vec.insert(std_vec.begin(), 13, 10);
		ft_vec.insert(ft_vec.begin(), 13, 10);
		bool	two = std_vec.size() == ft_vec.size();
		list_push<size_t>(std_lst, ft_lst, std_vec.size(), ft_vec.size());
		print_test_iterator<size_t, std::list<size_t>::iterator>(std_lst, ft_lst, mode, 2, "./unit-tests/vector/size.log");

		std_vec.assign(130, 9);
		ft_vec.assign(130, 9);
		bool	three = std_vec.size() == ft_vec.size();
		list_push<size_t>(std_lst, ft_lst, std_vec.size(), ft_vec.size());
		print_test_iterator<size_t, std::list<size_t>::iterator>(std_lst, ft_lst, mode, 3, "./unit-tests/vector/size.log");

		bool	four = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 4, "./unit-tests/vector/size.log");
		print_result(one && two && three && four, true);
	}
	/*  MAX_SIZE  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>	std_vec;
		ft::vector<int>		ft_vec;
		std::list<size_t>	std_lst;
		std::list<size_t>	ft_lst;

		std_vec.push_back(10);
		ft_vec.push_back(10);
		bool	one = std_vec.max_size() == ft_vec.max_size();
		list_push<size_t>(std_lst, ft_lst, std_vec.max_size(), ft_vec.max_size());
		print_test_iterator<size_t, std::list<size_t>::iterator>(std_lst, ft_lst, mode, 1, "./unit-tests/vector/max_size.log");

		std_vec.insert(std_vec.begin(), 13, 10);
		ft_vec.insert(ft_vec.begin(), 13, 10);
		bool	two = std_vec.max_size() == ft_vec.max_size();
		list_push<size_t>(std_lst, ft_lst, std_vec.max_size(), ft_vec.max_size());
		print_test_iterator<size_t, std::list<size_t>::iterator>(std_lst, ft_lst, mode, 2, "./unit-tests/vector/max_size.log");

		std_vec.assign(130, 9);
		ft_vec.assign(130, 9);
		bool	three = std_vec.max_size() == ft_vec.max_size();
		list_push<size_t>(std_lst, ft_lst, std_vec.max_size(), ft_vec.max_size());
		print_test_iterator<size_t, std::list<size_t>::iterator>(std_lst, ft_lst, mode, 3, "./unit-tests/vector/max_size.log");

		bool	four = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 4, "./unit-tests/vector/max_size.log");
		print_result(one && two && three && four, true);
	}
	/*  RESIZE  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>	std_vec;
		ft::vector<int>		ft_vec;
		std::list<size_t>	std_lst;
		std::list<size_t>	ft_lst;

		std_vec.assign(130, 9);
		ft_vec.assign(130, 9);
		bool	one = (std_vec.size() == ft_vec.size() && std_vec.capacity() == ft_vec.capacity());
		list_push<size_t>(std_lst, ft_lst, std_vec.size(), ft_vec.size());
		list_push<size_t>(std_lst, ft_lst, std_vec.capacity(), ft_vec.capacity());
		print_test_iterator<size_t, std::list<size_t>::iterator>(std_lst, ft_lst, mode, 1, "./unit-tests/vector/resize.log");

		std_vec.resize(200, 7);
		ft_vec.resize(200, 7);
		bool	two = (std_vec.size() == ft_vec.size() && std_vec.capacity() == ft_vec.capacity());
		list_push<size_t>(std_lst, ft_lst, std_vec.size(), ft_vec.size());
		list_push<size_t>(std_lst, ft_lst, std_vec.capacity(), ft_vec.capacity());
		print_test_iterator<size_t, std::list<size_t>::iterator>(std_lst, ft_lst, mode, 2, "./unit-tests/vector/resize.log");

		std_vec.resize(12, 7);
		ft_vec.resize(12, 7);
		bool	three = (std_vec.size() == ft_vec.size() && std_vec.capacity() == ft_vec.capacity());
		list_push<size_t>(std_lst, ft_lst, std_vec.size(), ft_vec.size());
		list_push<size_t>(std_lst, ft_lst, std_vec.capacity(), ft_vec.capacity());
		print_test_iterator<size_t, std::list<size_t>::iterator>(std_lst, ft_lst, mode, 3, "./unit-tests/vector/resize.log");
		bool	four;
		try {
			ft_vec.resize(ft_vec.max_size() + 1, 1);
			four = false;
		}
		catch (std::exception &e) {
			four = true;
		}

		std_vec.resize(300, 7);
		ft_vec.resize(300, 7);
		bool	five = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 4, "./unit-tests/vector/resize.log");
		print_result(one && two && three && four && five, true);
	}
	/*  CAPACITY  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>	std_vec;
		ft::vector<int>		ft_vec;
		std::list<size_t>	std_lst;
		std::list<size_t>	ft_lst;
		size_t				ft_capacity;

		int	test = 1;
		bool	one = true;
		bool	two = true;
		ft_capacity = ft_vec.capacity();
		for (int i = 0; i < 1000 && one == true; i += 124) {
			std_vec.insert(std_vec.begin(), i, 12);
			ft_vec.insert(ft_vec.begin(), i, 12);

			one = (ft_capacity < ft_vec.capacity() && ft_capacity < ft_vec.size()) || (ft_capacity == ft_vec.capacity() && ft_capacity >= ft_vec.size());
			two = two && ft_vec.capacity() == std_vec.capacity();
			list_push<size_t>(std_lst, ft_lst, std_vec.capacity(), ft_vec.capacity());
			print_test_iterator<size_t, std::list<size_t>::iterator>(std_lst, ft_lst, mode, test, "./unit-tests/vector/capacity.log");
			ft_capacity = ft_vec.capacity();
			++test;
		}
		print_result(one, two);
	}
	/*  EMPTY  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>	std_vec;
		ft::vector<int>		ft_vec;
		std::list<bool>	std_lst;
		std::list<bool>	ft_lst;

		bool	one = std_vec.empty() == ft_vec.empty();
		list_push<bool>(std_lst, ft_lst, std_vec.empty(), ft_vec.empty());
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 1, "./unit-tests/vector/empty.log");

		std_vec.insert(std_vec.begin(), 13, 10);
		ft_vec.insert(ft_vec.begin(), 13, 10);
		bool	two = std_vec.empty() == ft_vec.empty();
		list_push<bool>(std_lst, ft_lst, std_vec.empty(), ft_vec.empty());
		print_test_iterator<bool, std::list<bool>::iterator>(std_lst, ft_lst, mode, 2, "./unit-tests/vector/empty.log");

		bool	three = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 4, "./unit-tests/vector/empty.log");
		print_result(one && two && three, true);
	}
	/*  RESERVE  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>	std_vec;
		ft::vector<int>		ft_vec;
		std::list<size_t>	std_lst;
		std::list<size_t>	ft_lst;

		std_vec.reserve(100);
		ft_vec.reserve(100);
		bool	one = std_vec.capacity() == ft_vec.capacity();
		list_push<size_t>(std_lst, ft_lst, std_vec.capacity(), ft_vec.capacity());
		print_test_iterator<size_t, std::list<size_t>::iterator>(std_lst, ft_lst, mode, 1, "./unit-tests/vector/reserve.log");

		std_vec.reserve(5);
		ft_vec.reserve(5);
		bool	two = std_vec.capacity() == ft_vec.capacity();
		list_push<size_t>(std_lst, ft_lst, std_vec.capacity(), ft_vec.capacity());
		print_test_iterator<size_t, std::list<size_t>::iterator>(std_lst, ft_lst, mode, 2, "./unit-tests/vector/reserve.log");

		bool	three;
		try {
			ft_vec.reserve(ft_vec.max_size() + 1);
			three = false;
		}
		catch (std::exception &e) {
			three = true;
		}

		std_vec.reserve(1000);
		ft_vec.reserve(1000);
		bool	four = test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec);
		print_test_vector<int, std::vector<int>::iterator, ft::vector<int>::iterator>(std_vec, ft_vec, mode, 4, "./unit-tests/vector/reserve.log");
		print_result(one && two && three && four, true);
	}
	std::cout << std::endl;
}