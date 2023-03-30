/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:59:23 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/30 14:28:43 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	Span	teste(5);

	try
	{
		// for (int i = 10; i > -1; i--)
		// {
		// 	teste.addNumber(i);
		// }
		teste.addNumber(1233);
		teste.addNumber(130);
		std::cout << "shortest: " << teste.shortestSpan() << std::endl;
		std::cout << " longest: " << teste.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
