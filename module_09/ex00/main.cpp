/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:59:23 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/06 14:51:16 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{	
	if (argc != 2)
	{
		std::cerr << "btc: error: invalid number of arguments" << std::endl;
		return (1);
	}
	(void)argv;
	return (0);
}
