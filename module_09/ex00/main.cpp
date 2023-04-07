/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:59:23 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/06 20:55:50 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	try
	{	
		BitcoinExchange	bitCoinExchange;
		if (argc != 2)
			throw Exceptions("invalid number of arguments");
		bitCoinExchange.exchange(argv[1]);	
	}
	catch(std::exception const &e)
	{
		std::cerr << "btc: error: " << e.what() << std::endl;
	}
	return (0);
}
