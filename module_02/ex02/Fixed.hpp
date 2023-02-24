/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:26:09 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/23 21:19:34 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <math.h>

class	Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const &fixed);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed(void);
		Fixed				&operator=(Fixed const &fixed);

		int					getRawBits(void)  const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;
		bool				operator>(Fixed const &fixed) const;
		bool				operator<(Fixed const &fixed) const;
		bool				operator>=(Fixed const &fixed) const;
		bool				operator<=(Fixed const &fixed) const;
		bool				operator==(Fixed const &fixed) const;
		bool				operator!=(Fixed const &fixed) const;
		Fixed 				operator+(Fixed const &fixed) const;
		Fixed 				operator-(Fixed const &fixed) const;
		Fixed 				operator*(Fixed const &fixed) const;
		Fixed 				operator/(Fixed const &fixed) const;
		Fixed				&operator++(void); // prefix increment
		Fixed				&operator--(void); // prefix decrement
		Fixed				operator++(int); // postfix increment
		Fixed				operator--(int); // postfix decrement
		static Fixed		&min(Fixed &l, Fixed &r);
		static Fixed		&max(Fixed &l, Fixed &r);
		static Fixed const	&min(Fixed const &l, Fixed const &r);
		static Fixed const	&max(Fixed const &l, Fixed const &r);
	private:
		int					_fixed_point_value;
		static const int	_n_fractional_bits;
};

std::ostream	&operator<<(std::ostream &COUT, Fixed const &fixed);

#endif
