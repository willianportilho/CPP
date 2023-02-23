/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:05:17 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/23 20:47:12 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b( Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	//std::cout << Fixed::max(a, b) << std
	
	Fixed	test1(30);
	Fixed	test2(60.45f);
	std::cout << "test1(30) >  test2(60.45) = " << (test1 > test2) << " false" << std::endl;
	std::cout << "test1(30) <  test2(60.45) = " << (test1 < test2) << "  true" << std::endl;
	std::cout << "test1(30) >= test2(60.45) = " << (test1 >= test2) << " false" << std::endl;
	std::cout << "test1(30) <= test2(60.45) = " << (test1 <= test2) << "  true" << std::endl;
	std::cout << "test1(30) == test2(60.45) = " << (test1 == test2) << " false" << std::endl;
	std::cout << "test1(30) != test2(60.45) = " << (test1 != test2) << "  true" << std::endl;

	Fixed	test3(10.10f);
	Fixed	test4(20);
	std::cout << "test3(10.10) +  test4(20) = " << test3 + test4 << std::endl;
	std::cout << "test3(10.10) -  test4(20) = " << test3 - test4 << std::endl;
	std::cout << "test3(10.10) *  test4(20) = " << test3 * test4 << std::endl;
	std::cout << "test3(10.10) /  test4(20) = " << test3 / test4 << std::endl;	

	Fixed	test5(0);
	Fixed	test6(0);
	Fixed	test7(0);
	Fixed	test8(0);
	std::cout << "test5(0) whith prefix increment          =  " << ++test5 << std::endl;
	std::cout << "test6(0) whith prefix decrement          = " << --test6 << std::endl;
	std::cout << "test7(0) whith postfix increment         =  " << test7++ << std::endl;
	std::cout << "test7(0) whith postfix increment (after) =  " << test7 << std::endl;
	std::cout << "test8(0) whith postfix decrement         =  " << test8-- << std::endl;
	std::cout << "test8(0) whith postfix decrement (after) = " << test8 << std::endl;
	return (0);
}
