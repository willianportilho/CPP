/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:02:42 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/31 20:06:26 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <string>
#include <iostream>

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
	printTitle("1️⃣  SUBJECT TESTS (CAMPARE MUTANT AND LIST RESULTS)");

	{
		std::cout << "🟢 MutantStack result: " << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		std::cout << std::endl;
	}

	{
		std::cout << "🟢 list result: " << std::endl;
		std::list<int> lstack;
		lstack.push_back(5);
		lstack.push_back(17);
		std::cout << lstack.back() << std::endl;
		lstack.pop_back();
		std::cout << lstack.size() << std::endl;
		lstack.push_back(3);
		lstack.push_back(5);
		lstack.push_back(737);
		//[...]
		lstack.push_back(0);
		std::list<int>::iterator it = lstack.begin();
		std::list<int>::iterator ite = lstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(lstack);
	}

	return ;
}

static void	beginEndTests(void)
{
	printTitle("2️⃣  BEGIN()/END() TESTS");

	{
		std::cout << "🟢 prints 0-4 using begin() and end() iterators: " << std::endl;
		MutantStack<int> mstack;

		for (int i = 0; i < 5; i++)
			mstack.push(i);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl << std::endl;

		std::cout << "🟢 removes '2', '3' and '4' elements from stack: " << std::endl;
		for (int i = 0; i < 3; i++)
			mstack.pop();
		it = mstack.begin();
		ite = mstack.end();
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}

	return ;	
}

static void	rbeginRendTests(void)
{
	printTitle("3️⃣  RBEGIN()/REND() TESTS");

	{
		std::cout << "🟢 prints 0-4 (reverese form) using rbegin() and rend() reverse iterators: " << std::endl;
		MutantStack<int> mstack;

		for (int i = 0; i < 5; i++)
			mstack.push(i);

		MutantStack<int>::reverse_iterator it = mstack.rbegin();
		MutantStack<int>::reverse_iterator ite = mstack.rend();
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl << std::endl;

		std::cout << "🟢 removes '2', '3' and '4' elements from stack: " << std::endl;
		for (int i = 0; i < 3; i++)
			mstack.pop();
		it = mstack.rbegin();
		ite = mstack.rend();
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}

	return ;	
}

static void	copyTests(void)
{
	printTitle("4️⃣  COPY TESTS");

	{
		std::cout << "🟢 prints ORIGINAL INSTANCE 0-4, using begin() and end() iterators: " << std::endl;
		MutantStack<int> stack;

		for (int i = 0; i < 5; i++)
			stack.push(i);

		MutantStack<int>::iterator it = stack.begin();
		MutantStack<int>::iterator ite = stack.end();
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl << std::endl;

		std::cout << "🟢 prints COPY INSTANCE: " << std::endl;
		MutantStack<int>	copyStack(stack);
		it = copyStack.begin();
		ite = copyStack.end();
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl << std::endl;

		std::cout << "🟢 prints ORIGINAL INSTANCE (MODIFIED) | DEEP COPY TEST: " << std::endl;
		stack.pop();
		stack.pop();

		it = stack.begin();
		ite = stack.end();
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl << std::endl;

		std::cout << "🟢 prints COPY INSTANCE (UNMODIFIED) | DEEP COPY TEST: " << std::endl;
		it = copyStack.begin();
		ite = copyStack.end();
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}

	return ;	
}

static void	assignmentTests(void)
{
	printTitle("5️⃣  ASSIGNMENT TESTS");

	{
		std::cout << "🟢 prints ORIGINAL INSTANCE 0-4, using begin() and end() iterators: " << std::endl;
		MutantStack<int> stack;

		for (int i = 0; i < 5; i++)
			stack.push(i);

		MutantStack<int>::iterator it = stack.begin();
		MutantStack<int>::iterator ite = stack.end();
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl << std::endl;

		std::cout << "🟢 prints COPY INSTANCE: " << std::endl;
		MutantStack<int>	copyStack = stack;
		it = copyStack.begin();
		ite = copyStack.end();
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl << std::endl;

		std::cout << "🟢 prints ORIGINAL INSTANCE (MODIFIED) | DEEP COPY TEST: " << std::endl;
		stack.pop();
		stack.pop();

		it = stack.begin();
		ite = stack.end();
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl << std::endl;

		std::cout << "🟢 prints COPY INSTANCE (UNMODIFIED) | DEEP COPY TEST: " << std::endl;
		it = copyStack.begin();
		ite = copyStack.end();
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}

	return ;	
}

int	main(void)
{
	subjectTests();
	beginEndTests();
	rbeginRendTests();
	copyTests();
	assignmentTests();

	return (0);
}
