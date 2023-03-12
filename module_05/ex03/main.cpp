/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:02:42 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/11 22:33:22 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	generalTests(void)
{
	printTitle("1️⃣  GENERAL TESTS");

	{
		std::cout << "🟢 " << "SHRUBBERY FORM OK:" << std::endl;
		Intern 		someRandomIntern;
		AForm		*rrf;
		rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "Home");
		std::cout << *rrf;
		delete rrf;
	}
	{
		std::cout << std::endl << "🟢 " << "ROBOTOMY FORM OK:" << std::endl;
		Intern 		someRandomIntern;
		AForm		*rrf;
		rrf = someRandomIntern.makeForm("RobotomyRequestForm", "SpaceX");
		std::cout << *rrf;
		delete rrf;
	}
	{
		std::cout << std::endl << "🟢 " << "PRESIDENT FORM OK:" << std::endl;
		Intern 		someRandomIntern;
		AForm		*rrf;
		rrf = someRandomIntern.makeForm("PresidentialPardonForm", "Tite");
		std::cout << *rrf;
		delete rrf;
	}
	{
		AForm		*rrf = NULL;
		try
		{
			std::cout << std::endl << "🟢 " << "NON-EXISTENT FORM OK:" << std::endl;
			Intern 		someRandomIntern;
			rrf = someRandomIntern.makeForm("SOMETHING", "ANOTHER SOMETHING");
			std::cout << *rrf << std::endl;
			delete rrf;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
			if (rrf)
				delete rrf;
		}
	}

	return ;
}

static void	otherScenariosTests(void)
{
	printTitle("2️⃣  OTHER SCENARIOS TESTS");
	{
		AForm* rrf = NULL;
		try
		{
			Intern someRandomIntern;
			Bureaucrat	willian("Willian", 1);
			rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "Home");
			willian.signForm(*rrf);
			rrf->execute(willian);
			delete rrf;
		}
		catch(std::exception const &e)
		{
			if (rrf)
				delete rrf;
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		AForm* rrf = NULL;
		try
		{
			Intern someRandomIntern;
			Bureaucrat	willian("Willian", 1);
			rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
			willian.signForm(*rrf);
			rrf->execute(willian);
			delete rrf;
		}
		catch(std::exception const &e)
		{
			if (rrf)
				delete rrf;
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
		{
		AForm* rrf = NULL;
		try
		{
			Intern someRandomIntern;
			Bureaucrat	willian("Willian", 1);
			rrf = someRandomIntern.makeForm("PresidentialPardonForm", "Tite");
			willian.signForm(*rrf);
			std::cout << "🟢  Despite not being forgiven by some (or many) brazilians, ";
			rrf->execute(willian);
			delete rrf;
		}
		catch(std::exception const &e)
		{
			if (rrf)
				delete rrf;
			std::cout << e.what() << std::endl;
		}
	}
	
	
	return ;
}

int	main(void)
{
	generalTests();
	otherScenariosTests();

	return (0);
}
