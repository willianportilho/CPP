/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:02:42 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/11 12:57:41 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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

static void	assignmentAndCopyTests(void)
{
	printTitle("0️⃣  ASSIGNMENT AND COPY TESTS");
	ShrubberyCreationForm	shrubbery("shrubbery");
	ShrubberyCreationForm	shrubberyCopy = shrubbery;
	std::cout << shrubbery;
	std::cout << shrubberyCopy;

	return ;
}

static void	shrubberyTest(unsigned int grade, std::string const sub_title)
{
	std::cout << "🟢 " << sub_title << " TEST:" << std::endl;

	try
	{
		ShrubberyCreationForm	home("Home");
		Bureaucrat				willian(grade, "Willian");
		
		willian.signForm(home);
		willian.executeForm(home);
		std::cout << home;
		std::cout << willian;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return ;
}

static void	shrubberyAllTests(void)
{
	printTitle("1️⃣  SHRUBBERY TESTS");
	shrubberyTest(0, "BUREAUCRAT GRADE HIGH ERROR");
	std::cout << std::endl;
	shrubberyTest(151, "BUREAUCRAT GRADE LOW ERROR");
	std::cout << std::endl;
	shrubberyTest(146, "BUREAUCRAT CANNOT SIGN OR EXECUTE");
	std::cout << std::endl;
	shrubberyTest(145, "BUREAUCRAT CAN SIGN BUT NOT EXECUTE");
	std::cout << std::endl;
	shrubberyTest(137, "BUREAUCRAT CAN SIGN AND EXECUTE");
}

static void	robotomyTest(unsigned int grade, std::string const sub_title)
{
	std::cout << "🟢 " << sub_title << " TEST:" << std::endl;

	try
	{
		RobotomyRequestForm	space_x("SpaceX");
		Bureaucrat			willian(grade, "Willian");
		
		willian.signForm(space_x);
		willian.executeForm(space_x);
		std::cout << space_x;
		std::cout << willian;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return ;
}

static void	robotomyAllTests(void)
{
	printTitle("2️⃣  ROBOTOMY TESTS");
	robotomyTest(0, "BUREAUCRAT GRADE HIGH ERROR");
	std::cout << std::endl;
	robotomyTest(151, "BUREAUCRAT GRADE LOW ERROR");
	std::cout << std::endl;
	robotomyTest(73, "BUREAUCRAT CANNOT SIGN OR EXECUTE");
	std::cout << std::endl;
	robotomyTest(72, "BUREAUCRAT CAN SIGN BUT NOT EXECUTE");
	std::cout << std::endl;
	robotomyTest(45, "BUREAUCRAT CAN SIGN AND EXECUTE");
}

static void	presidentialTest(unsigned int grade, std::string const sub_title)
{
	std::cout << "🟢 " << sub_title << " TEST:" << std::endl;

	try
	{
		PresidentialPardonForm	tite("Tite");
		Bureaucrat				willian(grade, "Willian");
		
		willian.signForm(tite);
		willian.executeForm(tite);
		std::cout << tite;
		std::cout << willian;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return ;
}

static void	presidentialAllTests(void)
{
	printTitle("3️⃣  PRESIDENTIAL TESTS");
	presidentialTest(0, "BUREAUCRAT GRADE HIGH ERROR");
	std::cout << std::endl;
	presidentialTest(151, "BUREAUCRAT GRADE LOW ERROR");
	std::cout << std::endl;
	presidentialTest(26, "BUREAUCRAT CANNOT SIGN OR EXECUTE");
	std::cout << std::endl;
	presidentialTest(25, "BUREAUCRAT CAN SIGN BUT NOT EXECUTE");
	std::cout << std::endl;
	presidentialTest(5, "BUREAUCRAT CAN SIGN AND EXECUTE");
}

int	main(void)
{
	assignmentAndCopyTests();
	shrubberyAllTests();
	robotomyAllTests();
	presidentialAllTests();	

	return (0);
}
