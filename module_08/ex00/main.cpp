/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:02:42 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/29 13:20:37 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int	main(void)
{
	{
		std::cout << "🟢 VECTOR TEST" << std::endl;
		std::vector<int>	data;
		try
		{
			for (int i = -100; i < 100; i++)
				data.push_back(i);
			data.push_back(50);
			int i = 50;
			std::vector<int>::iterator it = easyfind(data, i);
			int index = it - data.begin();
			std::cout << *it << " at index: " << index << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	{
		std::cout << "🔴 VECTOR EXCEPTION TEST" << std::endl;
		std::vector<int>	data;
		try
		{
			for (int i = -100; i < 100; i++)
				data.push_back(i);
			int i = -101;
			std::vector<int>::iterator it = easyfind(data, i);
			int index = it - data.begin();
			std::cout << *it << " at index: " << index << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	{
		std::cout << "🟢 LIST TEST" << std::endl;
		std::list<int>	data;
		try
		{
			for (int i = -100; i < 100; i++)
				data.push_back(i);
			data.push_back(-100);
			int i = -100;
			std::list<int>::iterator it = easyfind(data, i);
			std::list<int>::iterator find_index = data.begin();
			for (int index = 0; find_index != data.end(); index++)
			{
				if (*find_index == *it)
				{
					std::cout << *it << " at index: " << index << std::endl;
					break;
				}
				find_index++;
			}
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	{
		std::cout << "🔴 LIST EXCEPTION TEST" << std::endl;
		std::list<int>	data;
		try
		{
			for (int i = -100; i < 100; i++)
				data.push_back(i);
			int i = 101;
			std::list<int>::iterator it = easyfind(data, i);
			std::list<int>::iterator find_index = data.begin();
			for (int index = 0; find_index != data.end(); index++)
			{
				if (*find_index == *it)
				{
					std::cout << *it << " at index: " << index << std::endl;
					break;
				}
				find_index++;
			}
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	{
		std::cout << "🟢 DEQUE TEST" << std::endl;
		std::deque<int>	data;
		try
		{
			for (int i = -100; i < 100; i++)
				data.push_back(i);
			data.push_back(8);
			int i = 8;
			std::deque<int>::iterator it = easyfind(data, i);
			int index = it - data.begin();
			std::cout << *it << " at index: " << index << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	{
		std::cout << "🔴 DEQUE EXCEPTION TEST" << std::endl;
		std::deque<int>	data;
		try
		{
			for (int i = -100; i < 100; i++)
				data.push_back(i);
			int i = 101;
			std::deque<int>::iterator it = easyfind(data, i);
			int index = it - data.begin();
			std::cout << *it << " at index: " << index << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	return (0);
}
