/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:02:42 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/11 17:51:30 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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

static void	copyTests(void)
{
	printTitle("1️⃣  COPY TESTS");
	ShrubberyCreationForm	shrubbery("shrubbery");
	ShrubberyCreationForm	shrubberyCopy(shrubbery);
	std::cout << shrubbery;
	std::cout << shrubberyCopy;

	std::cout << std::endl;

	RobotomyRequestForm	robotomy("robotomy");
	RobotomyRequestForm	robotomyCopy(robotomy);
	std::cout << robotomy;
	std::cout << robotomyCopy;

	std::cout << std::endl;

	PresidentialPardonForm	president("president");
	PresidentialPardonForm	presidentCopy(president);
	std::cout << president;
	std::cout << presidentCopy;

	std::cout << std::endl;

	return ;
}

static void	assignmentTests(void)
{
	printTitle("2️⃣  ASSIGNMENT TESTS");
	ShrubberyCreationForm	shrubbery("shrubbery");
	ShrubberyCreationForm	shrubberyCopy = shrubbery;
	std::cout << shrubbery;
	std::cout << shrubberyCopy;

	std::cout << std::endl;

	RobotomyRequestForm	robotomy("robotomy");
	RobotomyRequestForm	robotomyCopy = robotomy;
	std::cout << robotomy;
	std::cout << robotomyCopy;

	std::cout << std::endl;

	PresidentialPardonForm	president("president");
	PresidentialPardonForm	presidentCopy = president;
	std::cout << president;
	std::cout << presidentCopy;

	std::cout << std::endl;

	return ;
}

static void	shrubberyTest(unsigned int grade, std::string const sub_title)
{
	std::cout << "🟢 " << sub_title << " TEST:" << std::endl;

	try
	{
		ShrubberyCreationForm	home("Home");
		Bureaucrat				willian("Willian", grade);
		
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
	printTitle("3️⃣  SHRUBBERY TESTS");
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
		Bureaucrat			willian("Willian", grade);
		
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
	printTitle("4️⃣  ROBOTOMY TESTS");
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
		Bureaucrat				willian("Willian", grade);
		
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
	printTitle("5️⃣  PRESIDENTIAL TESTS");
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
	copyTests();
	assignmentTests();
	shrubberyAllTests();
	robotomyAllTests();
	presidentialAllTests();

	std::cout << std::endl;
	try
	{
		Bureaucrat	willian("Willian", 1);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
		rrf->execute(willian);	
	}
	catch(std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
