/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:05:17 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/16 18:42:00 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";

	std::string	*stringPTR = &string;

	std::string	&stringREF = string;

	std::cout << "memory address - string   : "
	<< &string << std::endl;
	std::cout << "memory address - stringPTR: "
	<< stringPTR << std::endl;
	std::cout << "memory address - stringREF: "
	<< &stringREF << std::endl;

	std::cout << "value - string   : "
	<< string << std::endl;
	std::cout << "value - stringPTR: "
	<< *stringPTR << std::endl;
	std::cout << "value - stringREF: "
	<< stringREF << std::endl;

	return (0);
}
