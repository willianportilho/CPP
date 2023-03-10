/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:02:42 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/10 12:39:52 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
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

static void	gradesConstructorTests(void)
{
	printTitle("1️⃣  GRADES CONSTRUCTOR TESTS");

	try
	{
		std::cout << "grade_to_sign high:" << std::endl;
		Form	real_madrid("Real Madrid", 0, 1);
		Bureaucrat cristiano(1, "Cristiano");
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		std::cout << "grade_to_execute high:" << std::endl;
		Form	real_madrid("Real Madrid", 1, 0);
		Bureaucrat cristiano(1, "Cristiano");
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		std::cout << "grade_to_sign low:" << std::endl;
		Form	real_madrid("Real Madrid", 151, 1);
		Bureaucrat cristiano(1, "Cristiano");
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		std::cout << "grade_to_execute low:" << std::endl;
		Form	real_madrid("Real Madrid", 1, 151);
		Bureaucrat cristiano(1, "Cristiano");
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		std::cout << "grade_to_sign and grade_to_execute ok:" << std::endl;
		Form	real_madrid("Real Madrid", 1, 150);
		Bureaucrat cristiano(1, "Cristiano");
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		std::cout << "grade_to_sign and grade_to_execute ok:" << std::endl;
		Form	real_madrid("Real Madrid", 150, 1);
		Bureaucrat cristiano(1, "Cristiano");
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return ;
}

static void	gettersTests(void)
{
	printTitle("2️⃣  GETTERS TESTS");

	try
	{
		Form	real_madrid("Real Madrid", 1, 1);
		std::cout << std::endl;
		std::cout << "getName: " << real_madrid.getName() << std::endl;
		std::cout << "getIsSigned: " << (real_madrid.getIsSigned() ? "true" : "false") << std::endl;
		std::cout << "getGradeToSigned: " << real_madrid.getGradeToSign() << std::endl;
		std::cout << "getGradeToExecute: " << real_madrid.getGradeToExecute() << std::endl;
		std::cout << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return ;
}

static void	overloadOutTests(void)
{
	printTitle("2️⃣  OVERLOADOUT TESTS");

	try
	{
		Form	real_madrid("Real Madrid", 1, 1);
		Form	barcelona("Barcelona", 1, 1);
		std::cout << std::endl;
		std::cout << real_madrid;
		std::cout << barcelona;
		std::cout << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return ;
}

static void	signFormTests(void)
{
	printTitle("4️⃣  SIGNFORM TESTS");

	try
	{
		std::cout << "constructor ok, but grade_to_sign low:" << std::endl;
		Form	real_madrid("Real Madrid", 1, 1);
		Bureaucrat cristiano(10, "Cristiano");
		cristiano.signForm(real_madrid);
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		std::cout << "constructor ok and grade_to_sign ok:" << std::endl;
		Form	real_madrid("Real Madrid", 1, 1);
		Bureaucrat cristiano(1, "Cristiano");
		cristiano.signForm(real_madrid);
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void	copyTests(void)
{
	printTitle("5️⃣  COPY TESTS");
	try
	{
		Form	palmeiras("Palmeiras", 1, 1);
		Form	palestra_italia(palmeiras);
		std::cout << palmeiras;
		std::cout << palestra_italia;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Form	juventus("Juventus", 26, 22);
		Form	juve(juventus);
		std::cout << juventus;
		std::cout << juve;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return ;
}

static void	assignmentTests(void)
{
	printTitle("6️⃣  ASSIGNMENT TESTS");
	try
	{
		Form	paris_saint_germain("Paris Saint Germain", 20, 16);
		Form	psg = paris_saint_germain;
		std::cout << paris_saint_germain;
		std::cout << psg;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Form	selecao_braileira("Seleção Braileira", 5, 5);
		Form	brasil = selecao_braileira;
		std::cout << selecao_braileira;
		std::cout << brasil;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return ;
}

int	main(void)
{
	gradesConstructorTests();
	gettersTests();
	overloadOutTests();
	signFormTests();
	copyTests();
	assignmentTests();
	
	return (0);
}
