/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:27:37 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/23 20:38:30 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixed_point_value(0)
{
	return ;
}

Fixed::Fixed(Fixed const &fixed)
{
	*this = fixed;
	return ;
}

Fixed::Fixed(const int value)
{
	this->_fixed_point_value = (value * (1 << Fixed::_n_fractional_bits));
	return ;
}

Fixed::Fixed(const float value)
{
	this->_fixed_point_value = roundf(value * (1 << Fixed::_n_fractional_bits));
	return ;
}

Fixed::~Fixed(void)
{
	return ;
}

Fixed	&Fixed::operator=(Fixed const &fixed)
{
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

int	Fixed::toInt(void) const
{
	return (this->getRawBits() / (1 << Fixed::_n_fractional_bits));
}

float	Fixed::toFloat(void) const
{
	return ((float)this->getRawBits() / (float)(1 << Fixed::_n_fractional_bits));
}

bool	Fixed::operator>(Fixed const &fixed) const
{
    return (this->getRawBits() > fixed.getRawBits());
}

bool	Fixed::operator<(Fixed const &fixed) const
{
    return (this->getRawBits() < fixed.getRawBits());
}

bool	Fixed::operator>=(Fixed const &fixed) const
{
    return (this->getRawBits() >= fixed.getRawBits());
}

bool	Fixed::operator<=(Fixed const &fixed) const
{
    return (this->getRawBits() <= fixed.getRawBits());
}

bool	Fixed::operator==(Fixed const &fixed) const
{
    return (this->getRawBits() == fixed.getRawBits());
}

bool	Fixed::operator!=(Fixed const &fixed) const
{
    return (this->getRawBits() != fixed.getRawBits());
}

Fixed	Fixed::operator+(Fixed const &fixed) const
{
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed	Fixed::operator-(Fixed const &fixed) const
{
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed	Fixed::operator*(Fixed const &fixed) const
{
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed	Fixed::operator/(Fixed const &fixed) const
{
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed	&Fixed::operator++(void)
{
	this->_fixed_point_value += 1;
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->_fixed_point_value -= 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	old;

	old = *this;
	operator++();
	return (old);
}

Fixed	Fixed::operator--(int)
{
	Fixed	old;

	old = *this;
	operator--();
	return (old);
}

std::ostream	&operator<<(std::ostream &COUT, Fixed const &fixed)
{
	COUT << fixed.toFloat();
	return (COUT);
}

const int	Fixed::_n_fractional_bits = 8;
