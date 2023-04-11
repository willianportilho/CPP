/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:59:23 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/10 23:09:11 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw Exceptions("invalid number of arguments");
		(void)argv;
	}
	catch(std::exception const &e)
	{
		std::cerr << "PmergeMe: Error: " << e.what() << std::endl;
	}
	return (0);
}
