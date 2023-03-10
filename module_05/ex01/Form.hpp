/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/10 12:30:56 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class	Form
{
	public:
		Form(std::string const name, unsigned const grade_to_sign, unsigned int const grade_to_execute);
		Form(Form const &src);
		~Form(void);
		Form				&operator=(Form const &rhs);
		std::string const	getName(void) const;
		bool				getIsSigned(void) const;
		unsigned int		getGradeToSign(void) const;
		unsigned int		getGradeToExecute(void) const;
		void				setIsSigned(bool is_signed);
		void				beSigned(Bureaucrat const &bureaucrat);
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
	private:
		Form(void);
		std::string const	_name;
		bool				_is_signed;
		unsigned int const	_grade_to_sign;
		unsigned int const	_grade_to_execute;
};

std::ostream	&operator<<(std::ostream &out, Form const &src);

#endif
