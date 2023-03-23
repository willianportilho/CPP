/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:02:42 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/22 21:05:05 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <cstddef>
#include <iostream>
#include <string>

int	main(void)
{
	{
		std::cout << "🟢 TESTS" << std::endl;
		std::string arr1[3] =		{"tesla", "microsoft", "apple"};
		int			arr2[8] =		{4, 0, 0, 2, 8, 9, 2, 2};
		double		arr3[5] =		{0.1, 2.3, 4.5, 6.7, 8.9};

		size_t size_arr1 = sizeof(arr1) / sizeof(arr1[0]);
		std::cout << "size arr1: " << size_arr1 << std::endl;
		std::cout << " original: ";
		::iter(arr1, size_arr1, &print);
		std::cout << std::endl;
		std::cout << " modified: ";
		::iter(arr1, size_arr1, &toUpperCase);
		::iter(arr1, size_arr1, &print);
		std::cout << std::endl;
		std::cout << "recovered: ";
		::iter(arr1, size_arr1, &toLowerCase);
		::iter(arr1, size_arr1, &print);
		std::cout << std::endl << std::endl;

		size_t size_arr2 = sizeof(arr2) / sizeof(arr2[0]);
		std::cout << "size arr2: " << size_arr2 << std::endl;
		std::cout << " original: ";
		::iter(arr2, size_arr2, &print);
		std::cout << std::endl;
		std::cout << " modified: ";
		::iter(arr2, size_arr2, &decrement);
		::iter(arr2, size_arr2, &print);
		std::cout << std::endl;
		std::cout << "recovered: ";
		::iter(arr2, size_arr2, &increment);
		::iter(arr2, size_arr2, &print);
		std::cout << std::endl << std::endl;

		size_t size_arr3 = sizeof(arr3) / sizeof(arr3[0]);
		std::cout << "size arr3: " << size_arr3 << std::endl;
		std::cout << " original: ";
		::iter(arr3, size_arr3, &print);
		std::cout << std::endl;
		std::cout << " modified: ";
		::iter(arr3, size_arr3, &increment);
		::iter(arr3, size_arr3, &print);
		std::cout << std::endl;
		std::cout << "recovered: ";
		::iter(arr3, size_arr3, &decrement);
		::iter(arr3, size_arr3, &print);
		std::cout << std::endl << std::endl;
	}

	{
		std::cout << "🟢 INTENTIONAL ERRORS" << std::endl;
		std::string const arr4[1] =	{"apple"};

		size_t size_arr4 = sizeof(arr4) / sizeof(arr4[0]);
		std::cout << "size arr4: " << size_arr4 << std::endl;
		std::cout << " original: ";
		::iter(arr4, size_arr4, &print);
		std::cout << std::endl;
		std::cout << " modified: ";
		::iter(arr4, size_arr4, &toUpperCase);
		::iter(arr4, size_arr4, &print);
		std::cout << std::endl;
		std::cout << "recovered: ";
		::iter(arr4, size_arr4, &toLowerCase);
		::iter(arr4, size_arr4, &print);
		std::cout << std::endl;
	}

	return (0);
}
