/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:02:42 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/23 16:56:58 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
#include <time.h>

#define MAX_VAL 750

static void	printTitle(std::string const title)
{
	std::cout << std::endl;
	std::cout << "=================" << std::endl;
	std::cout << "=================" << std::endl;
	std::cout << title << std::endl;
	std::cout << "=================" << std::endl;
	std::cout << "=================" << std::endl;
	return ;
}

static void	tests42(void)
{
	printTitle("1️⃣  TESTS 42");

	Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return ;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return ;
}

static void testConstructorWhithNoParameter(void)
{
	printTitle("2️⃣  TEST CONSTRUCTOR WITH NO PARAMETER");

	try
	{
		std::cout << "🟢 test empty int array with invalid index access exception:" << std::endl;
		Array<int>	int_array;
		std::cout << "int array size: " << int_array.size() << std::endl;
		std::cout << int_array[0];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		std::cout << "🟢 test empty char array with invalid index access exception:" << std::endl;
		Array<char>	char_array;
		std::cout << "char array size: " << char_array.size() << std::endl;
		std::cout << char_array[0];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

static void testConstructorWhithParameter(void)
{
	printTitle("3️⃣  TEST CONSTRUCTOR WITH PARAMETER AND DEFAULT ELEMENTS INITIALIZATION");

	try
	{
		std::cout << "🟢 test int array with valid index access:" << std::endl;
		Array<int>	int_array(3);
		std::cout << "int array size: " << int_array.size() << std::endl;
		for (int i = 0; i < 3; i++)
			std::cout << "  int array[" << i << "]: " << static_cast<int>(int_array[i]) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		std::cout << "🟢 test str array with valid index access:" << std::endl;
		Array<char>	char_array(3);
		std::cout << "char array size: " << char_array.size() << std::endl;
		for (int i = 0; i < 3; i++)
			std::cout << "  char array[" << i << "]: " << static_cast<int>(char_array[i]) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

static void	testConstructorCopy(void)
{
	printTitle("4️⃣  TEST CONSTRUCTOR COPY");

	{
		Array<int>	a(5);
		for (size_t i = 0; i < a.size(); i++)
			a[i] = i;

		Array<int>	aCopy(a);
		std::cout << std::endl;

		std::cout << "🟢 test copy array and size" << std::endl;
		std::cout << "    a: ";
		for (size_t i = 0; i < a.size(); i++)
			std::cout << a[i] << " ";
		std::cout << std::endl;
		
		std::cout << "aCopy: ";
		for (size_t i = 0; i < aCopy.size(); i++)
			std::cout << aCopy[i] << " ";
		std::cout << std::endl;

		std::cout << "    a size: " << a.size() << std::endl;
		std::cout << "aCopy size: " << aCopy.size() << std::endl;
		std::cout << std::endl;

		std::cout << "🟢 test deep copy" << std::endl;
		for (size_t i = 0; i < aCopy.size(); i++)
			aCopy[i] = i + 5;

		std::cout << "    a: ";
		for (size_t i = 0; i < a.size(); i++)
			std::cout << a[i] << " ";
		std::cout << std::endl;
		
		std::cout << "aCopy: ";
		for (size_t i = 0; i < aCopy.size(); i++)
			std::cout << aCopy[i] << " ";
		std::cout << std::endl << std::endl;
	}
}

static void	testAssignmentOperator(void)
{
	printTitle("5️⃣  TEST ASSIGNMENT OPERATOR");

	{
		Array<int>	a(5);
		for (size_t i = 0; i < a.size(); i++)
			a[i] = i;

		Array<int>	aCopy;
		aCopy = a;
		std::cout << std::endl;

		std::cout << "🟢 test assignment operator array and size" << std::endl;
		std::cout << "    a: ";
		for (size_t i = 0; i < a.size(); i++)
			std::cout << a[i] << " ";
		std::cout << std::endl;
		
		std::cout << "aCopy: ";
		for (size_t i = 0; i < aCopy.size(); i++)
			std::cout << aCopy[i] << " ";
		std::cout << std::endl;

		std::cout << "    a size: " << a.size() << std::endl;
		std::cout << "aCopy size: " << aCopy.size() << std::endl;
		std::cout << std::endl;

		std::cout << "🟢 test deep copy" << std::endl;
		for (size_t i = 0; i < aCopy.size(); i++)
			aCopy[i] = i + 5;

		std::cout << "    a: ";
		for (size_t i = 0; i < a.size(); i++)
			std::cout << a[i] << " ";
		std::cout << std::endl;
		
		std::cout << "aCopy: ";
		for (size_t i = 0; i < aCopy.size(); i++)
			std::cout << aCopy[i] << " ";
		std::cout << std::endl << std::endl;
	}
}

static void	testArrayTypes(void)
{
	printTitle("6️⃣  TEST ARRAY TYPES");
	{
		Array<char>	char_array(10);
		for (size_t i = 0; i < char_array.size(); i++)
		{
			char_array[i] = i + 'A';
			std::cout << char_array[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "char array size: " << char_array.size() << std::endl;
	}
	std::cout << std::endl;

	{
		Array<int>	int_array(10);
		for (size_t i = 0; i < int_array.size(); i++)
		{
			int_array[i] = i;
			std::cout << int_array[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "int array size: " << int_array.size() << std::endl;
	}
	std::cout << std::endl;

	{
		Array<double>	double_array(10);
		for (size_t i = 0; i < double_array.size(); i++)
		{
			double_array[i] = static_cast<double>(i) + 0.5;
			std::cout << double_array[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "double array size: " << double_array.size() << std::endl;
	}
	std::cout << std::endl;

	{
		Array<std::string>	string_array(3);
		string_array[0] = "42SP";
		string_array[1] = "42RIO";
		string_array[2] = "42BH";
		for (size_t i = 0; i < string_array.size(); i++)
			std::cout << string_array[i] << " ";
		std::cout << std::endl;
		std::cout << "std::string array size: " << string_array.size() << std::endl;
	}

	return ;
}

static void	testException(void)
{
	printTitle("7️⃣  TEST EXCEPTION");

	try
	{
		std::cout << "🟢 overflow index" << std::endl;
		Array<int>	int_array(30);
		std::cout << "int array size: " << int_array.size() << std::endl;
		for (int i = 0; i < 31; i++)
		{
			if (i != 30)
				std::cout << "int array[" <<  i << "]: " << static_cast<int>(int_array[i]) << std::endl;
			else
				std::cout << "int array[" << i << "]: " << std::endl << static_cast<int>(int_array[i]) << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		std::cout << "🟢 underflow index" << std::endl;
		Array<int>	int_array(30);
		std::cout << "int array size: " << int_array.size() << std::endl;
		for (int i = -1; i > -31; i--)
			std::cout << "int array[" << i << "]: " << std::endl << static_cast<int>(int_array[i]) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return ;
}

static void	testReadOnly(void)
{
	printTitle("8️⃣  TEST READ ONLY");

	std::cout << std::endl;
	Array<int> const	a(10);
	for (size_t i = 0; i < 10; i++)
	{
		// a[i] = i * 100;
		std::cout << a[i] << std::endl;
	}

	return ;
}

int main(int, char**)
{
	tests42();
	testConstructorWhithNoParameter();
	testConstructorWhithParameter();
	testConstructorCopy();
	testAssignmentOperator();
	testArrayTypes();
	testException();
	testReadOnly();

    return 0;
}
