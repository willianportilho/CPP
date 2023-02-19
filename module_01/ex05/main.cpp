/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:05:17 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/19 15:21:46 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	Harl	level;

	std::cout << "DEBUG: " << "valid" << std::endl;
	level.complain("DEBUG");
	std::cout << std::endl;

	std::cout << "INFO: " << "valid" << std::endl;
	level.complain("INFO");
	std::cout << std::endl;

	std::cout << "WARNING: " << "valid" << std::endl;
	level.complain("WARNING");
	std::cout << std::endl;

	std::cout << "ERROR: " << "valid" << std::endl;
	level.complain("ERROR");
	std::cout << std::endl;

	std::cout << "TEST: " << "invalid" << std::endl;
	level.complain("TEST");
	std::cout << std::endl;

	std::cout << "0123456789: " << "invalid" << std::endl;
	level.complain("0123456789");
	std::cout << std::endl;

	std::cout << "TWO WORDS: " << "invalid" << std::endl;
	level.complain("TWO WORDS");
	std::cout << std::endl;

	return (0);
}
