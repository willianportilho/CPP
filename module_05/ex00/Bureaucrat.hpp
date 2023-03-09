/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/08 21:59:17 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>

class	Bureaucrat
{
	public:
		Bureaucrat(unsigned int grade, std::string const name);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat(void);
		Bureaucrat			&operator=(Bureaucrat const &rhs);
		std::string const	getName(void);
		unsigned int		getGrade(void);
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

#endif
