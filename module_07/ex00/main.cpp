/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:02:42 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/22 13:09:48 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"
#include <iostream>

int	main(void)
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	// my own tests
	double e = 12345.6;
	double f = 65432.1;
	swap<double, double>(e, f);
	std::cout << std::endl;
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;

	float g = 4.2;
	float h = 4.2;
	swap<float, float>(g, h);
	std::cout << std::endl;
	std::cout << "g = " << g << ", h = " << h << std::endl;
	std::cout << "g (address) =                    " << &g << std::endl;
	std::cout << "h (address) =                    " << &h << std::endl;
	std::cout << "min( g, h ) = " << ::min( g, h ) << ", and address = " << &::min( g, h ) << std::endl;
	std::cout << "max( g, h ) = " << ::max( g, h ) << ", and address = " << &::max( g, h ) << std::endl;
	return (0);
}
