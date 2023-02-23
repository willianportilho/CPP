/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:27:37 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/23 15:03:18 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixed_point_value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
	return ;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_point_value = (value * (1 << Fixed::_n_fractional_bits));
	return ;
}

Fixed::Fixed(const float value)
{
	(void)value;
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_point_value = roundf(value * (1 << Fixed::_n_fractional_bits));
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed	&Fixed::operator=(Fixed const &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
	 	this->_fixed_point_value = fixed.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void)  const
{
	return (this->_fixed_point_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixed_point_value = raw;
	return ;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_fixed_point_value  / (1 << Fixed::_n_fractional_bits));
}

int	Fixed::toInt(void) const
{
	return (this->_fixed_point_value  / (1 << Fixed::_n_fractional_bits));
}

std::ostream	&operator<<(std::ostream &COUT, Fixed const &fixed)
{
	COUT << fixed.toFloat();
	return (COUT);
}

const int	Fixed::_n_fractional_bits = 8;
