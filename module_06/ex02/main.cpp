/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:02:42 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/20 09:25:30 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <time.h>
#include <iostream>

Base* generate(void)
{
	int	randow;
	std::srand(time(NULL));
	randow = std::rand() % 3;

	switch (randow)
	{
		case 0:
			std::cout << "generate returned \"A\" class" << std::endl;
			return (new A);	
		case 1:
			std::cout << "generate returned \"B\" class" << std::endl;
			return (new B);
		case 2:
			std::cout << "generate returned \"C\" class" << std::endl;
			return (new C);
		default:
			std::cerr << "identify: error: something went wrong (generate)" << std::endl;
	}
	return (NULL);
}

void identify(Base* p)
{
	A *a = dynamic_cast<A*>(p);
	B *b = dynamic_cast<B*>(p);
	C *c = dynamic_cast<C*>(p);

	if (a)
		std::cout << "A (by pointer)" << std::endl;
	else if (b)
		std::cout << "B (by pointer)" << std::endl;
	else if (c)
		std::cout << "C (by pointer)" << std::endl;
	else
		std::cerr << "identify: error: something went wrong (identify pointer)" << std::endl;
	return ;
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A (by reference)" << std::endl;
		return ;
	}
	catch(...)
	{
	}

	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B (by reference)" << std::endl;
		return ;
	}
	catch(...)
	{
	}

	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C (by reference)" << std::endl;
		return ;
	}
	catch(...)
	{
	}

	std::cerr << "identify: error: something went wrong (identify reference)" << std::endl;

	return ;	
}

int	main(void)
{
	Base *test = generate();

	std::cout << std::endl << "Result:" << std::endl;
	identify(test);
	identify(*test);
	return (0);
}
