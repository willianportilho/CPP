/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:05:17 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/23 21:31:32 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	std::cout << std::endl << "own tests" << std::endl << std::endl;

	std::cout << "comparison operators" << std::endl;
	Fixed	test1(30);
	Fixed	test2(60.45f);
	std::cout << "test1(30) >  test2(60.45) = " << (test1 > test2) << " false" << std::endl;
	std::cout << "test1(30) <  test2(60.45) = " << (test1 < test2) << "  true" << std::endl;
	std::cout << "test1(30) >= test2(60.45) = " << (test1 >= test2) << " false" << std::endl;
	std::cout << "test1(30) <= test2(60.45) = " << (test1 <= test2) << "  true" << std::endl;
	std::cout << "test1(30) == test2(60.45) = " << (test1 == test2) << " false" << std::endl;
	std::cout << "test1(30) != test2(60.45) = " << (test1 != test2) << "  true" << std::endl;

	std::cout << std::endl;
	std::cout << "arithmetic operators" << std::endl;
	Fixed	test3(10.10f);
	Fixed	test4(20);
	std::cout << "test3(10.10) +  test4(20) = " << test3 + test4 << std::endl;
	std::cout << "test3(10.10) -  test4(20) = " << test3 - test4 << std::endl;
	std::cout << "test3(10.10) *  test4(20) = " << test3 * test4 << std::endl;
	std::cout << "test3(10.10) /  test4(20) = " << test3 / test4 << std::endl;	

	std::cout << std::endl;
	std::cout << "increment/decrement" << std::endl;
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

	std::cout << std::endl;
	std::cout << "min/max funtions" << std::endl;
	Fixed	test9(123);
	Fixed	test10(454.456f);
	std::cout << "smallest one either test9(123) and test10(454.456) = "
	<< Fixed::min(test9, test10) << std::endl;
	std::cout << "greatest one either test9(123) and test10(454.456) = "
	<< Fixed::max(test9, test10) << std::endl;

	std::cout << std::endl;
	std::cout << "min/max functions (const version)" << std::endl;
	Fixed const	test11(123);
	Fixed const	test12(454.456f);
	std::cout << "smallest one either test9(123) and test10(454.456) = "
	<< Fixed::min(test11, test12) << std::endl;
	std::cout << "greatest one either test9(123) and test10(454.456) = "
	<< Fixed::max(test11, test12) << std::endl;
	return (0);
}
