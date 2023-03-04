/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:02:42 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/04 19:31:48 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
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

	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	std::cout << std::endl;

	delete j;//should not create a leak
	delete i;

	return ;
}

static void	arrayOfAnimalsTests(void)
{
	printTitle("2️⃣  ARRAY OF ANIMALS TESTS");

	AAnimal const	*animals[10];
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
	dog->setIdeas("Woof, Woof! I wanna run!", 100);
	cat->setIdeas("Meow, Meow! I wanna jump!", -50);
	cat->setIdeas("Meow, Meow! I wanna jump!", 500);

	dog->getIdeas(200);
	dog->getIdeas(-200);
	cat->getIdeas(101);
	cat->getIdeas(-101);
	std::cout << std::endl;

	delete dog;
	delete cat;

	return ;
}

static void	copyTests(void)
{
	printTitle("4️⃣  COPY TESTS");
	{
		Dog	*dog = new Dog();
		Dog	*copyDog = new Dog(*dog);
		std::cout << std::endl;

		dog->setIdeas("Bones", 0);
		copyDog->setIdeas("Water", 0);

		std::cout << "    dog: " << dog->getIdeas(0) << std::endl;
		std::cout << "copyDog: " << copyDog->getIdeas(0) << std::endl;
		std::cout << std::endl;

		copyDog->setIdeas("Run", 0);

		std::cout << "    dog: " << dog->getIdeas(0) << std::endl;
		std::cout << "copyDog: " << copyDog->getIdeas(0) << std::endl;
		std::cout << std::endl;

		delete dog;
		delete copyDog;
	}
	{
		Cat	*cat = new Cat();
		Cat	*copyCat = new Cat(*cat);
		std::cout << std::endl;

		cat->setIdeas("Mouse", 0);
		copyCat->setIdeas("Sleep", 0);

		std::cout << "    cat: " << cat->getIdeas(0) << std::endl;
		std::cout << "copyCat: " << copyCat->getIdeas(0) << std::endl;
		std::cout << std::endl;

		copyCat->setIdeas("Milk", 0);

		std::cout << "    cat: " << cat->getIdeas(0) << std::endl;
		std::cout << "copyCat: " << copyCat->getIdeas(0) << std::endl;
		std::cout << std::endl;

		delete cat;
		delete copyCat;
	}
	return ;
}

static void	assignmentTests(void)
{
	printTitle("5️⃣  ASSIGNMENT TESTS");
	{
		Dog	*dog = new Dog();
		Dog	*copyDog = new Dog();
		*copyDog = *dog;
		std::cout << std::endl;

		dog->setIdeas("Bones", 0);
		copyDog->setIdeas("Water", 0);

		std::cout << "    dog: " << dog->getIdeas(0) << std::endl;
		std::cout << "copyDog: " << copyDog->getIdeas(0) << std::endl;
		std::cout << std::endl;

		copyDog->setIdeas("Run", 0);

		std::cout << "    dog: " << dog->getIdeas(0) << std::endl;
		std::cout << "copyDog: " << copyDog->getIdeas(0) << std::endl;
		std::cout << std::endl;

		delete dog;
		delete copyDog;
	}
	{
		Cat	*cat = new Cat();
		Cat	*copyCat = new Cat();
		*copyCat = *cat;
		std::cout << std::endl;

		cat->setIdeas("Mouse", 0);
		copyCat->setIdeas("Sleep", 0);

		std::cout << "    cat: " << cat->getIdeas(0) << std::endl;
		std::cout << "copyCat: " << copyCat->getIdeas(0) << std::endl;
		std::cout << std::endl;

		copyCat->setIdeas("Milk", 0);

		std::cout << "    cat: " << cat->getIdeas(0) << std::endl;
		std::cout << "copyCat: " << copyCat->getIdeas(0) << std::endl;
		std::cout << std::endl;

		delete cat;
		delete copyCat;
	}
	return ;
}

int	main(void)
{
	subjectTests();
	arrayOfAnimalsTests();
	ideasTests();
	copyTests();
	assignmentTests();

	return (0);
}
