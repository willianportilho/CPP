/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:59:23 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/30 17:35:38 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

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

static void	subjectTests(void)
{
	printTitle("1️⃣  SUBJECT TESTS");

	try
	{
		std::cout << "🟢 vector limit: 5 numbers | try add: 5 numbers" << std::endl;
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << " longestSpan: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return ;
}

static void	addManyNumbersTests(void)
{
	printTitle("2️⃣  ADD MANY NUMBERS TESTS");

	try
	{
		std::cout << "🟢 vector limit: 11000 numbers | try add: 11000 numbers" << std::endl;
		Span	sp(11000);

		std::vector<unsigned int>	manyNumbers;
		for (int i = 0; i < 11000; i++)
			manyNumbers.push_back(i);
		std::vector<unsigned int>::iterator	it, it2;
		it = manyNumbers.begin();
		it2 = manyNumbers.end();

		sp.addManyNumbers(it, it2);

		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << " longestSpan: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return ;
}

static void	numberLimitReachedTests(void)
{
	printTitle("3️⃣  NUMBER VECTOR LIMIT REACHED TESTS");

	try
	{
		std::cout << "🔴 vector limit: 5 numbers | try add: 6 numbers | addNumber() function throws an exception, because the limit numbers to be added are reached" << std::endl;
		Span	sp(5);

		for (int i = 0; i < 6; i++)
			sp.addNumber(i);

		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << " longestSpan: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return ;
}

static void	overflowTests(void)
{
	printTitle("4️⃣  OVERFLOW TESTS");

	try
	{
		std::cout << "🔴 vector limit unsigned int: " << std::numeric_limits<unsigned int>::max()
		<< " | try add: " << (static_cast<long unsigned int>(std::numeric_limits<unsigned int>::max()) + 1)
		<< " | addNumber() function throws an exception, because detects an overflow" << std::endl;

		Span	sp(1);

		sp.addNumber(static_cast<long unsigned int>(std::numeric_limits<unsigned int>::max()) + 1);

		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << " longestSpan: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return ;
}

static void	snapNotFoundTests(void)
{
	printTitle("5️⃣  SNAP NOT FOUND TESTS");

	try
	{
		std::cout << "🔴 vector limit: 0 numbers | try add: 0 numbers | shortestSpan() function throws an exception, because there's no numbers added" << std::endl;
		Span	sp(0);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		std::cout << "🔴 vector limit: 1 number | try add: 1 number | shortestSpan() function throws an exception, because there's only one number added" << std::endl;
		Span	sp(1);

		sp.addNumber(1234567890);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return ;
}

static void	emptyVectorTests(void)
{
	printTitle("6️⃣  EMPTY VECTOR TESTS");

	try
	{
		std::cout << "🔴 vector limit: 100 numbers | try add: 0 numbers | addManyNumbers() throws an exception, because the 'it' iterator is empty" << std::endl;
		Span	sp(100);

		std::vector<unsigned int>	emptyVector;
		std::vector<unsigned int>::iterator	it, it2;
		it = emptyVector.begin();
		it2 = emptyVector.end();

		sp.addManyNumbers(it, it2);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return ;
}

int main()
{
	subjectTests();
	addManyNumbersTests();
	numberLimitReachedTests();
	overflowTests();
	snapNotFoundTests();
	emptyVectorTests();

	return (0);
}
