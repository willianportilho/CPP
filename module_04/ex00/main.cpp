/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:02:42 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/03 13:38:53 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

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

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound(); //will output the dog sound!
	meta->makeSound();

	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;

	return ;
}

static void	wrongTests(void)
{
	printTitle("2️⃣  PURPOSELY WRONG TESTS");

	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_i = new WrongCat();

	std::cout << std::endl;

	std::cout << wrong_meta->getType() << " " << std::endl;
	std::cout << wrong_i->getType() << " " << std::endl;
	wrong_i->makeSound(); //will output the wrongcat sound!
	wrong_meta->makeSound();

	std::cout << std::endl;

	delete wrong_meta;
	delete wrong_i;

	return ;
}

static void	instanceTests(void)
{
	printTitle("3️⃣  INSTANCE TESTS");

	Animal		animal;
	Dog			dog;
	Cat			cat;
	WrongAnimal	wrong_animal;
	WrongCat	wrong_cat;

	std::cout << std::endl;

	std::cout << animal.getType() << std::endl;
	std::cout << dog.getType() << std::endl;
	std::cout << cat.getType() << std::endl;
	std::cout << wrong_animal.getType() << std::endl;
	std::cout << wrong_cat.getType() << std::endl;

	animal.makeSound();
	dog.makeSound();
	cat.makeSound();
	wrong_animal.makeSound();
	wrong_cat.makeSound();

	std::cout << std::endl;

	return ;
}

static void	copyTests(void)
{
	printTitle("4️⃣  COPY CONSTRUCTOR TESTS");

	std::cout << std::endl << "ORIGINAL INSTANCE:" << std::endl;
	Animal		animal;
	Dog			dog;
	Cat			cat;
	WrongAnimal	wrong_animal;
	WrongCat	wrong_cat;

	std::cout << std::endl;

	std::cout << animal.getType() << std::endl;
	std::cout << dog.getType() << std::endl;
	std::cout << cat.getType() << std::endl;
	std::cout << wrong_animal.getType() << std::endl;
	std::cout << wrong_cat.getType() << std::endl;

	animal.makeSound();
	dog.makeSound();
	cat.makeSound();
	wrong_animal.makeSound();
	wrong_cat.makeSound();

	std::cout << std::endl << "COPY INSTANCE:" << std::endl;
	Animal		cp_animal(animal);
	Dog			cp_dog(dog);
	Cat			cp_cat(cat);
	WrongAnimal	cp_wrong_animal(wrong_animal);
	WrongCat	cp_wrong_cat(wrong_cat);

	std::cout << std::endl;

	std::cout << cp_animal.getType() << std::endl;
	std::cout << cp_dog.getType() << std::endl;
	std::cout << cp_cat.getType() << std::endl;
	std::cout << cp_wrong_animal.getType() << std::endl;
	std::cout << cp_wrong_cat.getType() << std::endl;

	cp_animal.makeSound();
	cp_dog.makeSound();
	cp_cat.makeSound();
	cp_wrong_animal.makeSound();
	cp_wrong_cat.makeSound();

	std::cout << std::endl;

	return ;
}

static void	assignmentCopyTests(void)
{
	printTitle("5️⃣  ASSIGNMENT COPY TESTS");

	Animal		animal;
	Animal		animal2;
	Dog			dog;
	Dog			dog2;
	Cat			cat;
	Cat			cat2;
	WrongAnimal	wrong_animal;
	WrongAnimal	wrong_animal2;
	WrongCat	wrong_cat;
	WrongCat	wrong_cat2;

	std::cout << std::endl;

	std::cout << "ORIGINAL INSTANCE:" << std::endl;
	std::cout << animal.getType() << std::endl;
	std::cout << dog.getType() << std::endl;
	std::cout << cat.getType() << std::endl;
	std::cout << wrong_animal.getType() << std::endl;
	std::cout << wrong_cat.getType() << std::endl;

	animal2.setType("ANIMAL MODIFIED");
	dog2.setType("DOG MODIFIED");
	cat2.setType("CAT MODIFIED");
	wrong_animal2.setType("WRONG_CAT MODIFIED");
	wrong_cat2.setType("WRONG_CAT MODIFIED");

	std::cout << std::endl << "MODIFIED INSTANCE:" << std::endl;
	animal = animal2;
	dog = dog2;
	cat = cat2;
	wrong_animal = wrong_animal2;
	wrong_cat = wrong_cat2;

	std::cout << animal.getType() << std::endl;
	std::cout << dog.getType() << std::endl;
	std::cout << cat.getType() << std::endl;
	std::cout << wrong_animal.getType() << std::endl;
	std::cout << wrong_cat.getType() << std::endl;

	std::cout << std::endl;

	return ;
}

int	main(void)
{
	subjectTests();
	wrongTests();
	instanceTests();
	copyTests();
	assignmentCopyTests();
	return (0);
}
