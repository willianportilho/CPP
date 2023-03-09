/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:02:42 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/09 18:10:13 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

static void	generalTests(void)
{
	printTitle("1️⃣  GENERAL TESTS");

	try
	{
		Bureaucrat	willian(1, "Willian");
		std::cout << willian;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat	guilherme(150, "Guilherme");
		std::cout << guilherme;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat	wilhelm(0, "Wilhelm");
		std::cout << wilhelm;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat	lian(255, "Lian");
		std::cout << lian;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return ;
}

static void	incrementAndDecrementTests(void)
{
	printTitle("2️⃣  INCREMENT AND DECREMENT TESTS");
	try
	{
		Bureaucrat	willian(1, "Willian");
		std::cout << willian;
		std::cout << "decremented 1 time!" << std::endl;
		willian.decrement();
		std::cout << willian;
		std::cout << "incremented 2 times!" << std::endl;
		willian.increment();
		willian.increment();
		std::cout << willian;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat	nailliw(150, "Nailliw");
		std::cout << nailliw;
		std::cout << "incremented 1 time!" << std::endl;
		nailliw.increment();
		std::cout << nailliw;
		std::cout << "decremented 2 times!" << std::endl;
		nailliw.decrement();
		nailliw.decrement();
		std::cout << nailliw;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return ;
}

static void	copyTests(void)
{
	printTitle("3️⃣  COPY TESTS");
	try
	{
		Bureaucrat	willian(1, "Willian");
		Bureaucrat	willianCopy(willian);
		std::cout << willianCopy;
		std::cout << "decremented 1 time!" << std::endl;
		willianCopy.decrement();
		std::cout << willianCopy;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat	nailliw(150, "Nailliw");
		Bureaucrat	nailliwCopy(nailliw);
		std::cout << nailliwCopy;
		std::cout << "incremented 1 time!" << std::endl;
		nailliwCopy.increment();
		std::cout << nailliwCopy;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return ;
}

static void	assignmentTests(void)
{
	printTitle("4️⃣  ASSIGNMENT TESTS");
	try
	{
		Bureaucrat	willian(1, "Willian");
		Bureaucrat	willianCopy = willian;
		std::cout << willianCopy;
		std::cout << "decremented 1 time!" << std::endl;
		willianCopy.decrement();
		std::cout << willianCopy;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat	nailliw(150, "Nailliw");
		Bureaucrat	nailliwCopy = nailliw;
		std::cout << nailliwCopy;
		std::cout << "incremented 1 time!" << std::endl;
		nailliwCopy.increment();
		std::cout << nailliwCopy;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return ;
}

int	main(void)
{
	generalTests();
	incrementAndDecrementTests();
	copyTests();
	assignmentTests();
	
	return (0);
}
