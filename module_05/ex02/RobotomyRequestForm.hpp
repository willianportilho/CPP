/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/10 16:30:52 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"
#include <iostream>
#include <string>

class	RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(std::string const target);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		~RobotomyRequestForm(void);
		RobotomyRequestForm	&operator=(RobotomyRequestForm const &rhs);
		std::string const	getTarget(void) const;
		void				execute(Bureaucrat const & executor) const;
	private:
		RobotomyRequestForm(void);
		std::string const		_target;
};

#endif
