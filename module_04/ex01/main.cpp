/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:02:42 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/03 21:53:01 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

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

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;

	delete j;//should not create a leak
	delete i;
	std::cout << std::endl;

	return ;
}

static void	arrayOfAnimalsTests(void)
{
	printTitle("2️⃣  ARRAY OF ANIMALS TESTS");

	Animal const	*animals[10];

	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << std::endl;
	}
	for (int i = 0; i < 10; i++)
	{
		delete animals[i];
		std::cout << std::endl;
	}
}

int	main(void)
{
	subjectTests();
	arrayOfAnimalsTests();

	return (0);
}
