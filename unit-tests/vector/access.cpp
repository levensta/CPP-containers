#include "../headers/test_vector.hpp"

void	access() {
	std::cout << "Default\t\t|";
	std::list<int>	lst;
	lst.push_back(87);
	lst.push_back(-12);
	lst.push_back(9765);
	lst.push_back(982);
	lst.push_back(0);
	lst.push_back(25);
	lst.push_back(-90);
	/*  OPERATOR[]  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>	std_vec(lst.begin(), lst.end());
		ft::vector<int>		ft_vec(lst.begin(), lst.end());
		std::list<size_t>	std_lst;
		std::list<size_t>	ft_lst;

		bool	one = true;
		for (int i = 0; i < lst.size() && one == true; ++i) {
			one = std_vec[i] == ft_vec[i];
			list_push<size_t>(std_lst, ft_lst, std_vec[i], ft_vec[i]);
			print_test_iterator<size_t, std::list<size_t>::iterator>(std_lst, ft_lst, mode, i + 1, "./unit-tests/vector/operator[].log");
		}
		print_result(one, true);
	}
	/*  AT */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>	std_vec(lst.begin(), lst.end());
		ft::vector<int>		ft_vec(lst.begin(), lst.end());
		std::list<size_t>	std_lst;
		std::list<size_t>	ft_lst;

		bool	one = true;
		for (int i = 0; i < lst.size() && one == true; ++i) {
			one = std_vec.at(i) == ft_vec.at(i);
			list_push<size_t>(std_lst, ft_lst, std_vec.at(i), ft_vec.at(i));
			print_test_iterator<size_t, std::list<size_t>::iterator>(std_lst, ft_lst, mode, i + 1, "./unit-tests/vector/at.log");
		}
		bool	two;
		try {
			ft_vec.at(lst.size() + 5);
			two = false;
		}
		catch (std::exception &e) {
			two = true;
		}
		print_result(one && two, true);
	}
	/*  FRONT */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>	std_vec(lst.begin(), lst.end());
		ft::vector<int>		ft_vec(lst.begin(), lst.end());
		std::list<size_t>	std_lst;
		std::list<size_t>	ft_lst;

		bool	one = true;
		for (int i = 0; i < 5 && one == true; ++i) {
			one = std_vec.front() == ft_vec.front();
			list_push<size_t>(std_lst, ft_lst, std_vec.front(), ft_vec.front());
			print_test_iterator<size_t, std::list<size_t>::iterator>(std_lst, ft_lst, mode, i + 1, "./unit-tests/vector/front.log");
			std_vec.insert(std_vec.begin(), i);
			ft_vec.insert(ft_vec.begin(), i);
		}
		print_result(one, true);
	}
	/*  BACK */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		std::vector<int>	std_vec(lst.begin(), lst.end());
		ft::vector<int>		ft_vec(lst.begin(), lst.end());
		std::list<size_t>	std_lst;
		std::list<size_t>	ft_lst;

		bool	one = true;
		for (int i = 0; i < 5 && one == true; ++i) {
			one = std_vec.back() == ft_vec.back();
			list_push<size_t>(std_lst, ft_lst, std_vec.back(), ft_vec.back());
			print_test_iterator<size_t, std::list<size_t>::iterator>(std_lst, ft_lst, mode, i + 1, "./unit-tests/vector/back.log");
			std_vec.push_back(i);
			ft_vec.push_back(i);
		}
		print_result(one, true);
	}
	std::cout << std::endl;
	std::cout << "Const\t\t|";
	/*  CONST_OPERATOR[]  */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		const std::vector<int>	std_vec(lst.begin(), lst.end());
		const ft::vector<int>		ft_vec(lst.begin(), lst.end());
		std::list<size_t>	std_lst;
		std::list<size_t>	ft_lst;

		bool	one = true;
		for (int i = 0; i < lst.size() && one == true; ++i) {
			one = std_vec[i] == ft_vec[i];
			list_push<size_t>(std_lst, ft_lst, std_vec[i], ft_vec[i]);
			print_test_iterator<size_t, std::list<size_t>::iterator>(std_lst, ft_lst, mode, i + 1, "./unit-tests/vector/const_operator[].log");
		}
		print_result(one, true);
	}
	/*  CONST_AT */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		const std::vector<int>	std_vec(lst.begin(), lst.end());
		const ft::vector<int>		ft_vec(lst.begin(), lst.end());
		std::list<size_t>	std_lst;
		std::list<size_t>	ft_lst;

		bool	one = true;
		for (int i = 0; i < lst.size() && one == true; ++i) {
			one = std_vec.at(i) == ft_vec.at(i);
			list_push<size_t>(std_lst, ft_lst, std_vec.at(i), ft_vec.at(i));
			print_test_iterator<size_t, std::list<size_t>::iterator>(std_lst, ft_lst, mode, i + 1, "./unit-tests/vector/const_at.log");
		}
		bool	two;
		try {
			ft_vec.at(lst.size() + 5);
			two = false;
		}
		catch (std::exception &e) {
			two = true;
		}
		print_result(one && two, true);
	}
	/*  CONST_FRONT */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		const std::vector<int>	std_vec(lst.begin(), lst.end());
		const ft::vector<int>		ft_vec(lst.begin(), lst.end());
		std::list<size_t>	std_lst;
		std::list<size_t>	ft_lst;

		bool	one = std_vec.front() == ft_vec.front();
		list_push<size_t>(std_lst, ft_lst, std_vec.front(), ft_vec.front());
		print_test_iterator<size_t, std::list<size_t>::iterator>(std_lst, ft_lst, mode, 1, "./unit-tests/vector/const_front.log");
		print_result(one, true);
	}
	/*  CONST_BACK */
	{
		std::ios_base::openmode	mode = std::fstream::in | std::fstream::out | std::fstream::trunc;
		const std::vector<int>	std_vec(lst.begin(), lst.end());
		const ft::vector<int>		ft_vec(lst.begin(), lst.end());
		std::list<size_t>	std_lst;
		std::list<size_t>	ft_lst;

		bool	one = std_vec.back() == ft_vec.back();
		list_push<size_t>(std_lst, ft_lst, std_vec.back(), ft_vec.back());
		print_test_iterator<size_t, std::list<size_t>::iterator>(std_lst, ft_lst, mode, 1, "./unit-tests/vector/const_back.log");
		print_result(one, true);
	}
	std::cout << std::endl;
}