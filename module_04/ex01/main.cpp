/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:02:42 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/04 13:29:56 by wportilh         ###   ########.fr       */
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
	std::cout << std::endl;

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
		if (i < 9)
			std::cout << std::endl;
	}
}

static void	ideasTests(void)
{
	printTitle("3️⃣  IDEAS TESTS");

	Dog	*dog = new Dog();
	Cat	*cat = new Cat();
	std::cout << std::endl;

	for (int i = 0; i < 100; i++)
	{
		dog->setIdeas("Woof, Woof! I wanna run!", i);
		cat->setIdeas("Meow, Meow! I wanna jump!", i);
	}

	for (int i = 0; i < 100; i++)
		std::cout << (i + 1) << ") Dog: " << dog->getIdeas(i) << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 100; i++)
		std::cout << (i + 1) << ") Cat: " << cat->getIdeas(i) << std::endl;
	std::cout << std::endl;

	std::cout << "Wrong index tests:" << std::endl;
	dog->setIdeas("Woof, Woof! I wanna run!", -1);
	dog->setIdeas("Woof, Woof! I wanna run!", 101);
	cat->setIdeas("Meow, Meow! I wanna jump!", -50);
	cat->setIdeas("Meow, Meow! I wanna jump!", 500);
	dog->getIdeas(200);
	dog->getIdeas(-200);
	cat->getIdeas(101);
	cat->getIdeas(-101);
	return ;
}

static void	deepCopyTests(void)
{
	printTitle("4️⃣  DEEP COPY TESTS");

	Dog	*dog = new Dog();
	//Animal	*copyDog(dog);

	dog->getIdeas(0);

	delete dog;
	return ;
}

int	main(void)
{
	subjectTests();
	arrayOfAnimalsTests();
	ideasTests();
	deepCopyTests();

	return (0);
}
