/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/11 10:37:08 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include "AForm.hpp"
#include <iostream>
#include <string>

class AForm;

class	Bureaucrat
{
	public:
		Bureaucrat(unsigned int grade, std::string const name);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat(void);
		Bureaucrat			&operator=(Bureaucrat const &rhs);
		void				increment(void);
		void				decrement(void);
		void				signForm(AForm &form);
		void				executeForm(AForm const & form);
		std::string const	getName(void) const;
		unsigned int		getGrade(void) const;
		void				setGrade(unsigned int grade);
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
		Bureaucrat(void);
		std::string const	_name;
		unsigned int		_grade;
};

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &src);

#endif
